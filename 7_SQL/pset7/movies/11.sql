SELECT title from movies JOIN
stars ON movies.id = stars.movie_id JOIN
ratings ON movies.id = ratings.movie_id JOIN
PEOPLE ON stars.person_id = people.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;