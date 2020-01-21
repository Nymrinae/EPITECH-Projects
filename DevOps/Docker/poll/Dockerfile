FROM    python:3.7-alpine
WORKDIR /app
ENV     FLASK_APP app.py
ENV     FLASK_RUN_HOST 0.0.0.0
ENV     FLASK_RUN_PORT 80

# install requirements
COPY requirements.txt ./
RUN pip install -r requirements.txt
EXPOSE 80

COPY . .
CMD ["flask", "run", "--host=0.0.0.0 --port=80"]