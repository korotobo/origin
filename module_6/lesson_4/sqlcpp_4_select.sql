--task 2


--Название и продолжительность самого длительного трека.
SELECT track_list.track_name, track_list.duration_track
FROM track_list
WHERE track_list.duration_track = (SELECT max(duration_track) FROM track_list);

--Название треков, продолжительность которых не менее 3,5 минут.
SELECT track_list.track_name, track_list.duration_track
FROM track_list
WHERE track_list.duration_track > '03:30:00';

--Названия сборников, вышедших в период с 2018 по 2020 год включительно.
SELECT collection_name
FROM collections_list
WHERE collection_release_year between '2018' and '2020';

--Исполнители, чьё имя состоит из одного слова.
SELECT performer_name
FROM performers_list
WHERE performer_name not LIKE '% %';

--Название треков, которые содержат слово «мой» или «my».
SELECT track_name
FROM track_list
WHERE track_name LIKE '%мой%' or track_name like '%My%' or track_name like '%my%';


--task 3


--Количество исполнителей в каждом жанре.
SELECT genre_name, count(performer_name)
FROM genres_list
LEFT JOIN broker_genres_performers ON genres_list.id_genres_list = broker_genres_performers.id_genres_list
LEFT JOIN performers_list ON performers_list.id_performers_list = genres_list.id_genres_list
GROUP BY genre_name
ORDER BY count(performer_name) desc;

--Количество треков, вошедших в альбомы 2019–2020 годов.
SELECT count(*)
FROM track_list
JOIN album_list ON album_list.id_album_list = track_list.id_album_list
WHERE album_release_year between '2019' and '2020';

--Средняя продолжительность треков по каждому альбому.
SELECT album_name, AVG(duration_track)
FROM track_list
JOIN album_list ON album_list.id_album_list = track_list.id_album_list
GROUP BY album_name
ORDER BY AVG(duration_track);

--Все исполнители, которые не выпустили альбомы в 2020 году.
SELECT performer_name
FROM performers_list
JOIN broker_performers_album ON performers_list.id_performers_list = broker_performers_album.id_performers_list
JOIN album_list ON broker_performers_album.id_album_list = album_list.id_album_list
WHERE album_release_year != '2020';

--Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
SELECT collection_name, performer_name
FROM collections_list
JOIN album_list ON collections_list.id_album_list = album_list.id_album_list
JOIN broker_performers_album ON album_list.id_album_list = broker_performers_album.id_album_list
JOIN performers_list ON performers_list.id_performers_list = broker_performers_album.id_performers_list
WHERE performer_name = 'Genix';

