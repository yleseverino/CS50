SELECT DISTINCT(name) FROM movies JOIN
stars ON movies.id = stars.movie_id JOIN
people ON stars.person_id = people.id
WHERE movie_id IN (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = "Kevin Bacon" AND birth = 1958) AND name <> "Kevin Bacon";