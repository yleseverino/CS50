import cs50
import csv

# Create an empty File
open("shows3.db", "w").close()

# Open that file for SQLite
db = cs50.SQL("sqlite:///shows3.db")

# Create table in database in shows3.db
db.execute("CREATE TABLE shows (tconst TEXT, primaryTitle TEXT, startYear NUMERIC, genres TEXT)")

# Open title basis
with open("title.basics.tsv", "r") as titles:
    
    # Create myself a dictReader
    reader = csv.DictReader(titles, delimiter = '\t')

    for row in reader:

        if row["titleType"] == "tvSeries" and row["isAdult"] == "0":

            if row["startYear"] != '\\N':

                startYear = int(row["startYear"])

                if startYear >= 1970:

                    tconst = row["tconst"]
                    primaryTitle =  row["primaryTitle"]
                    genres = row["genres"]

                    db.execute("INSERT INTO shows (tconst, primaryTitle, startYear, genres) VALUES (?,?,?,?)",tconst, primaryTitle, startYear, genres)
