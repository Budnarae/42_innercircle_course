import threading
from typing import List, TypedDict, TYPE_CHECKING

from exceptions.CustomException import (
    WebSocketAlreadyRoomJoinedException,
    WebSocketRoomFullException,
    WebSocketRoomNotFoundException,
    WebSocketRoomNotJoinedException,
)
from websocket.room.roomuser import RoomUserJson
from websocket.utils import generate_random

if TYPE_CHECKING:
    from websocket.userdict import UserDict


class RoomJson(TypedDict):
    room_id: str
    room_name: str
    room_limit: int
    room_cur_people: int


class Room:
    room_id: str
    room_name: str
    room_limit: int
    user_list: List[int]

    def __init__(self, room_name: str, room_limit: int, admin: int) -> None:
        self.room_id: str = generate_random(21)
        self.room_name: str = room_name
        self.room_limit: int = room_limit
        self.user_list: List[int] = [admin]
        self.lock = threading.Lock()

    def to_json(self) -> RoomJson:
        with self.lock:
            return {
                "room_id": self.room_id,
                "room_name": self.room_name,
                "room_cur_people": len(self.user_list),
                "room_limit": self.room_limit,
            }

    def add_user(self, user_id: int) -> None:
        with self.lock:
            if not self.__is_valid():
                raise WebSocketRoomNotFoundException()
            if len(self.user_list) >= self.room_limit:
                raise WebSocketRoomFullException()
            if user_id in self.user_list:
                raise WebSocketAlreadyRoomJoinedException()

            self.user_list.append(user_id)

    def remove_user(self, user_id: int) -> None:
        """
        Aquire lock
        """
        with self.lock:
            if not self.__is_valid():
                raise WebSocketRoomNotFoundException()
            if user_id not in self.user_list:
                raise WebSocketRoomNotJoinedException()

            self.user_list.remove(user_id)

    def __is_valid(self) -> bool:
        return len(self.user_list) > 0

    def is_valid(self) -> bool:
        with self.lock:
            return self.__is_valid()

    def people_list_to_json(self, user_dict: "UserDict") -> List[RoomUserJson]:
        """
        Aquire lock, Release the lock, and then Requires `user_dict`'s lock
        """
        with self.lock:
            user_list = self.user_list[:]

        ret = []
        for u in user_list:
            ret.append(user_dict.get(u).to_json())
        return ret

    def is_full(self) -> bool:
        """
        Aquire lock
        """
        with self.lock:
            if not self.__is_valid():
                return False
            return len(self.user_list) == self.room_limit

    def is_admin(self, user_id: int) -> bool:
        with self.lock:
            if not self.__is_valid():
                return False
            return self.user_list[0] == user_id
