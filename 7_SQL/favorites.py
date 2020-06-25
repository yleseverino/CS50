import csv


counts = {}

with open("CS50 2019 - Lecture 7 - Favorite TV Shows (Responses) - Form Responses 1.csv", 'r') as cs50:

    reader = csv.DictReader(cs50)

    for row in reader:

        title = row["title"].lower()

        if title in counts:
            counts[title] +=1

        else:
            counts[title] = 1

for name, counts in sorted(counts.items(), key=lambda oi:oi[1] ):
    print(name, counts, sep=' | ')
