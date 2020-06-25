import cs50
import csv
import sys


# Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")


def main():
    if len(sys.argv) != 2:
        print("Error in parameters")
        print("Expected: python dna foo.csv")
        exit(1)

    with open(sys.argv[1], 'r') as file:

        reader = csv.DictReader(file)

        for row in reader:

            name = row['name'].split()

            if len(name) == 2:

                db.execute("INSERT INTO students (first, last, house, birth) VALUES (?,?,?,?)", name[0], name[1], row['house'], row['birth'])

            else:

                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)", name[0], name[1], name[2], row['house'], row['birth'])


main()