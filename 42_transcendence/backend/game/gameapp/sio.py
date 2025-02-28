import json
import logging
from typing import Any

import socketio

from gameapp.envs import FRONTEND_URL, GAME_URL

NAMESPACE = "/game"

INIT_EVENT = "init"
UPDATE_BALL_EVENT = "updateBall"
UPDATE_SCORE_EVENT = "updateScore"
UPDATE_PADDLE_EVENT = "updatePaddle"
GAME_OVER_EVENT = "gameOver"
RESET_POSITIONS_EVENT = "resetPositions"
OPPONENT_EVENT = "opponent"

sio = socketio.Server(
    cors_allowed_origins=[
        "https://localhost",
        f"https://{FRONTEND_URL}",
        GAME_URL,
    ]
)

logger = logging.getLogger(__name__)


def sio_emit(event: str, data: dict[str, Any], to: str):
    if event != UPDATE_BALL_EVENT and event != UPDATE_PADDLE_EVENT:
        logger.debug(f"sio_emit: event={event}, data={json.dumps(data)}, to={to}")

    sio.emit(event, data, to=to, namespace=NAMESPACE)


def sio_session(sid: str):
    return sio.session(sid, namespace=NAMESPACE)


def sio_disconnect(sid: str):
    logger.info(f"Make sid={sid} disconnect")
    sio.disconnect(sid, namespace=NAMESPACE)


def sio_enter_room(sid: str, room_name: str):
    logger.debug(f"sid={sid} enters room to {room_name}")
    sio.enter_room(sid, room_name, namespace=NAMESPACE)
