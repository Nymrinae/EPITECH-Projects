# T-DAT-902 Nostradamovies

## Project's Presentation
Recommender is a BigData project where the final goal is to predict the genre of a movie based on his poster only.

## Technologies
Frontend: TypeScript, Vue3, TailwindCSS

Backend: Python, Flask
## Getting Started

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

Put the following data (extract if necessary) on a **/data** folder at the root of the repository

https://epitechfr.sharepoint.com/sites/TDAT902/Documents%20partages/Forms/AllItems.aspx?csf=1&web=1&e=VzMzUU&cid=6713fb30%2D4a61%2D4555%2D945d%2D904259fdf2fa&RootFolder=%2Fsites%2FTDAT902%2FDocuments%20partages%2Fdata&FolderCTID=0x012000F564A00B5E98FE4380EF0C645E31A70D

**The csv must be renamed dataset.csv**