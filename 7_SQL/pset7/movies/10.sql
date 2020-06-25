SELECT DISTINCT name FROM directors JOIN
movies ON directors.movie_id = movies.id JOIN
people ON directors.person_id = people.id JOIN
ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;