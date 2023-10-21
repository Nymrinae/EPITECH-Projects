# T-DAT-901 Recommender

## Project's Presentation
Recommender is a BigData project where the final goal is to recommend a product to a client. The first step is to analyse a given dataset composed of over seven millions customers purchases. We are going to use these stats to recommend items based on client's taste, budget and such.

## Technologies
Frontend: TypeScript, VueJS, Bootstrap Vue

Backend: Python, Flask

Recommender System: sklearn, pandas

## Getting Started

Client:
```bash
cd front && npm install && npm run serve
```

Server:
```bash
pip install -r requirements.txt # install dependencies

# and depending on your OS
cd back && start.bat # Windows

cd back && python3 -m flask run --port 5000 # Linux
```

Put the following data on a **/data/processed** folder at the root of back repository

ClientSummary: https://mega.nz/file/rKgGybyJ#jBa5fO0ldcPOAIzBnXD468JWg-qgvWV3gLwm8pHlO8s

TicketSummary: https://mega.nz/file/TWpAUTgA#vQI9v3-mG4ZQsItmd6zMrns7aLxszJjUhKMqOKATsHE

KaDo Dataset: https://mega.nz/file/TWpAUTgA#vQI9v3-mG4ZQsItmd6zMrns7aLxszJjUhKMqOKATsHE
