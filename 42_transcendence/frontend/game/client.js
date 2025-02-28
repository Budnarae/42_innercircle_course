import { initScene, onWindowResize } from "./sceneSetup.js";
import { createGeometry } from "./geometrySetup.js";
import {
  animate,
  stopAnimation,
  handleKeyDown,
  handleKeyUp,
} from "./animation.js";
import { updateScore, updateOpponent } from "./scoreboard.js";
import { showGameOver, updateGamePopup, setGameOver } from "./gameOver.js";
import { JWT } from "../modules/authentication/jwt.mjs";
import { MainPage } from "../modules/page/main.mjs";
import { clearBody } from "../modules/page/lowRankElements.mjs";
import { LOGIN_EXPIRED_MSG } from "../modules/authentication/globalConstants.mjs";

export let socket = null;
export const gameSocketDisconnect = () => {
  if (socket !== null) {
    socket.disconnect();
    socket = null;
  }
};
export const gameSocketConnect = () => {
  if (socket !== null) {    
    gameSocketDisconnect();
  }
  
  socket = io("/game", {
    auth: {
      jwt: JWT.getJWTTokenFromCookie().accessToken,
    },
    path: "/game-sio/",
  });

  socket.on("connect", () => {
    alert("게임에 연결되었습니다.");
  });

  socket.on("connect_error", async (error) => {
    alert("게임 연결 중 문제가 발생하였습니다.");
    alert("재연결을 시도합니다.");
    if (error.message === "jwt.expired") {
      try {
        await JWT.getNewToken();
        gameSocketConnect();
      } catch (e) {
        alert(`${LOGIN_EXPIRED_MSG}(${e})`);
        logout();
      }
    } else {
      alert(`재연결에 실패하였습니다. 메인 페이지로 이동합니다(${error})`);
      socket = null;
      clearBody();
      MainPage.renderAndPushHistory();
    }
  });
};

export const runPongGame = () => {
  const restartButton = document.getElementById("restartButton");
  const gameOverPopup = document.getElementById("gameOverPopup");

  let paddleId;
  let player1Score = 0;
  let player2Score = 0;

  let keyDownHandler;
  let keyUpHandler;

  let scene, camera, renderer, composer;

  gameSocketConnect();
  ({ scene, camera, renderer, composer } = initScene());
  createGeometry(scene);

  window.addEventListener("resize", () => {
    onWindowResize(camera, renderer, composer);
  });
  window.addEventListener("popstate", removeKeyEvent);

  // 버튼 클릭 시 게임 재시작
  restartButton.addEventListener("click", () => {
    if (restartButton.textContent === "나가기") {
      window.history.back(); // 뒤로가기
    } else if (restartButton.textContent === "다음 게임") {
      removeKeyEvent();
      socket.emit("nextGame"); // 다음 게임 시작
      gameOverPopup.style.display = "none";
      setGameOver(false);
    }
  });

  handleSocketEvents(socket, scene);

  function removeKeyEvent() {
    if (keyDownHandler) {
      window.removeEventListener("keydown", keyDownHandler);
      keyDownHandler = null;
    }
    if (keyUpHandler) {
      window.removeEventListener("keyup", keyUpHandler);
      keyUpHandler = null;
    }
  }

  function handleSocketEvents(socket, scene) {
    socket.on("init", (data) => {
      paddleId = data.paddleId;
      const opponent = data.opponent;
      setGameOver(false);
      stopAnimation(scene);
      removeKeyEvent();
      keyDownHandler = (event) => handleKeyDown(event, paddleId);
      keyUpHandler = (event) => handleKeyUp(event, paddleId);
      window.addEventListener("keydown", keyDownHandler);
      window.addEventListener("keyup", keyUpHandler);
      resetGameObjects(opponent);
      animate(scene, camera, composer, socket, paddleId);
    });

    socket.on("updatePaddle", (data) => {
      const paddle = scene.getObjectByName(data.paddleId);
      if (paddle) paddle.position.x = data.position;
    });

    socket.on("updateBall", (ballData) => {
      const ball = scene.getObjectByName("ball");
      if (ball) {
        ball.position.set(ballData.x, ballData.y, 0.2);
      }
    });

    socket.on("updateScore", (scores) => {
      player1Score = scores.paddle1;
      player2Score = scores.paddle2;
      updateScore(scene, player1Score, player2Score, paddleId);
    });

    socket.on("resetPositions", resetPositions);

    socket.on("gameOver", (data) => {
      let win = data.winner === paddleId;
      if (data.disconnect_win === true) win = true;
      setGameOver(true);
      showGameOver(
        win,
        data.paddle1,
        data.paddle2,
        "", // 기본값
        true // 기본값
      );
    });

    socket.on("opponent", (data) => {
      const nextOpponent = data.opponent;
      const lastGame = data.lastGame;
      updateGamePopup(nextOpponent, lastGame);
    });

    socket.on("disconnect", (reason) => {
      removeKeyEvent();
      stopAnimation(scene);
      alert(`게임에서 퇴장하였습니다. (reason : ${reason})`);
    });
  }

  // 오브젝트(카메라, 점수판, 공과 패들) 초기화 함수 : 게임 시작할 때만 호출
  function resetGameObjects(opponent) {
    resetPositions();
    updateOpponent(scene, paddleId, opponent);
    updateScore(scene, 0, 0, paddleId);

    if (paddleId === "paddle1") {
      camera.position.set(0, -10.5, 3);
      camera.lookAt(0, 0, 1);
    } else if (paddleId === "paddle2") {
      camera.position.set(0, 10.5, 3);
      camera.lookAt(0, 0, 1);
      camera.rotation.z = Math.PI;
    }
  }

  // 패들, 공 위치 초기화 함수 : 점수판 업데이트 시 호출
  function resetPositions() {
    const paddle1 = scene.getObjectByName("paddle1");
    const paddle2 = scene.getObjectByName("paddle2");
    const ball = scene.getObjectByName("ball");

    if (paddle1) paddle1.position.set(0, -6.5, 0.2);
    if (paddle2) paddle2.position.set(0, 6.5, 0.2);
    if (ball) {
      ball.position.set(0, 0, 0.2);
      ball.vel = 0;
    }
  }
};

// delete from temp_match_user ;delete from temp_match_room_user  ;delete from temp_match ;delete from temp_match_room  ;