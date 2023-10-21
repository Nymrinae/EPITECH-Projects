## Installation

Client:

```bash
cd front && npm install && npm run dev
```

Server:

```bash
pip install -r requirements.txt # install dependencies
cd back

python3 helpers/h5Converter.py # generate dataset

# and depending on your OS
start.bat # Windows
python3 -m flask run --port 5000 # Linux, prod mode
python3 app.py runserver -d # Linux, dev mode
```
