import logging
from datetime import datetime, timezone, timedelta
from http.client import INTERNAL_SERVER_ERROR

from socketio.exceptions import ConnectionRefusedError

from exceptions.CustomException import CustomException
from gameapp.sio import sio


logger = logging.getLogger(__name__)


def event_on(event: str, *args, **kwargs):
    def handle_exception(func):
        def _wrapper(*args, **kwargs):
            start = datetime.now(timezone.utc)
            is_paddle_move = event == "paddleMove"
            try:
                if not is_paddle_move:
                    logger.debug(f"This websocket is for event={event}")
                ret = func(*args, **kwargs)
                if ret is None:
                    return {}
                return ret
            except ConnectionRefusedError as e:
                logger.error("connection refused error")
                logger.exception(e)
                raise e
            except CustomException as e:
                logger.error(f"custom exception type={type(e)}")
                logger.exception(e)
                return {"error": e.__str__(), "code": e.get_status_code()}
            except Exception as e:
                logger.error(f"Unknown exception, type={type(e)}")
                logger.exception(e)
                return {"error": "internal_error", "code": INTERNAL_SERVER_ERROR}
            finally:
                if not is_paddle_move:
                    elapsed = datetime.now(timezone.utc) - start
                    logger.debug(f"Elapsed = {elapsed / timedelta(milliseconds=1)}ms")

        _outer = sio.on(event, *args, **kwargs)(_wrapper)  # type: ignore
        return _outer

    return handle_exception
