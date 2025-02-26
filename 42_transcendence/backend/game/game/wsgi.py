"""
WSGI config for game project.

It exposes the WSGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.1/howto/deployment/wsgi/
"""

import logging
import os
from typing import Any

import django
import socketio
from socketio.exceptions import ConnectionRefusedError
from django.core.wsgi import get_wsgi_application

from exceptions.CustomException import CustomException, InternalException
from game.decorators import event_on
from gameapp.sio import NAMESPACE, sio

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "game.settings")
django.setup()

from gameapp.wsgi_utils import (
    on_connect,
    on_disconnect,
    on_next_game,
    on_paddle_move,
)

application = get_wsgi_application()
application = socketio.WSGIApp(sio, application)

logger = logging.getLogger(__name__)


@event_on("connect", namespace=NAMESPACE)
def connect(sid: str, environ, auth: dict[str, Any]):
    try:
        on_connect(sid, auth)
    except ConnectionRefusedError as e:
        logger.error("While connecting, ConnectionRefusedError occurred")
        raise e
    except CustomException as e:
        logger.error(f"While connecting: Custom Exception type={type(e)}")
        logger.exception(e)
        raise ConnectionRefusedError(e.__str__())
    except Exception as e:
        logger.error(f"While Connecting: Other exception type={type(e)}")
        logger.exception(e)
        raise ConnectionRefusedError(InternalException().__str__())


@event_on("paddleMove", namespace=NAMESPACE)
def paddle_move(sid: str, data: dict[str, Any]):
    on_paddle_move(sid, data)


@event_on("nextGame", namespace=NAMESPACE)
def next_game(sid: str):
    on_next_game(sid)


@event_on("disconnect", namespace=NAMESPACE)
def disconnect(sid: str, reason):
    try:
        on_disconnect(sid, reason)
    except Exception as e:
        logger.error(f"on disconnect, error type={type(e)}")
        logger.exception(e)
        raise e
