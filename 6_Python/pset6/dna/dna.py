__author__ = "Yle Severino Carvalho"
__email__ = "ylewap0@gmail.com"


__license__ = "MIT"
__version__ = "1.0.1"


import pandas
import sys


def main():
    if len(sys.argv) != 3:
        print("Error in parameters")
        print("Expected: python dna foo.csv foo.txt")
        exit(1)

    people = pandas.read_csv(sys.argv[1], index_col=0)

    # Open file and close after copy the data to dna variable
    with open(sys.argv[2], 'r') as file:
        dna = file.read()

    # Create a dictionary to store the results from the sequence
    results = {}
    for i in range(len(people.columns)):
        results[people.columns[i]] = dnasearch(dna, people.columns[i])

    teste = pandas.Series(data=results, name='teste')  # Convert dict to a datafram to compare

    # Compare each row with the row teste
    for index, row in people.iterrows():
        if row.equals(teste):
            print(index)
            exit(0)

    print("No match")


def dnasearch(dna: str, STR: str):
    size_str = len(STR)
    soma = 0
    total = 0

    # Count number of STRs
    i = 0
    while i < len(dna):
        if dna[i:i + size_str] == STR:
            soma += 1
            i += size_str
        else:
            soma = 0
            i += 1
        if soma > total:
            total = soma

    return total


main()