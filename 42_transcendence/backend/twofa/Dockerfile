FROM python:3.13.0-alpine

# Install packages
RUN python -m pip install --upgrade pip
RUN python -m pip install \
    Django \
    "psycopg[binary]" \
    python-dotenv \
    requests \
    logging \
    pyotp \
    djangorestframework \
    gunicorn


# Move Script File
COPY ./run_server.sh /server/run_server.sh
RUN chmod +x /server/run_server.sh

# Execute Script
WORKDIR /server
ENTRYPOINT ["sh", "./run_server.sh"]
