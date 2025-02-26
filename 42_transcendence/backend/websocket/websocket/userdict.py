import logging
import threading
import json
from typing import Dict, TYPE_CHECKING

from exceptions.CustomException import InternalException
from websocket.room.roomuser import RoomUser


class UserDict:
    logger = logging.getLogger(__name__)

    def __init__(self) -> None:
        self.lock = threading.Lock()
        self.dict: Dict[int, RoomUser] = {}

    def add(self, user_id: int, roomuser: RoomUser):
        with self.lock:
            if user_id in self.dict:
                self.logger.error(f"user_id={user_id} is in dict! Not Adding")
                return False
            self.logger.info(f"user_id={user_id} successfully added to UserDict")
            self.dict[user_id] = roomuser
            return True

    def remove(self, user_id: int):
        with self.lock:
            if user_id not in self.dict:
                self.logger.error(f"user_id={user_id} is not in dict! not deleting")
                return False
            self.logger.info(f"user_id={user_id} successfully deleted from UserDict")
            del self.dict[user_id]
            return True

    def get(self, user_id: int) -> RoomUser:
        with self.lock:
            if user_id not in self.dict:
                self.logger.error(f"Trying to find user_id={user_id} failed!")
                raise InternalException()
            self.logger.info(f"Trying to find user_id={user_id} succeeded")
            return self.dict[user_id]
