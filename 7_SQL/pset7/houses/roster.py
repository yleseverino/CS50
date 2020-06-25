import cs50
import sys


# Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")


def main():

    if len(sys.argv) != 2:
        print("Error in parameters")
        print("Expected: python dna name")
        exit(1)

    rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last", sys.argv[1])

    for row in rows:

        if (row['middle'] == None):

            print(f"{row['first']} {row['last']}, born {row['birth']}")

        else:

            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")


main()
