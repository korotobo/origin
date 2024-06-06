--task 1

--добавим список жанров
INSERT INTO genres_list (genre_name)
VALUES ('Trance'), ('Post-Hardcore'), ('Pop');

--добавим список исполнителей
INSERT INTO performers_list (performer_name)
VALUES ('Above & Beyond'),
('Genix'),
('Enter Shikari'),
('Bring Me The Horizon'),
('Валерий Леонтьев'),
('Валерий Меладзе');

--добавим список альбомов
INSERT INTO album_list (album_name,album_release_year)
VALUES ('Distorted Truth', '2019'),
('199X', '2021'),
('Nothing is True & Everything is Possible', '2020'),
('Sempiternal', '2013'),
('Муза', '1983'),
('Океан', '2005');

--добавим треклист
INSERT INTO track_list (track_name,duration_track,id_album_list)
VALUES ('Distorted Truth', '4:13:00', 1),
('All I Want', '4:12:00', 2),
('Be Free', '04:16:00', 2),
('THE GREAT UNKNOWN', '03:25:00', 3),
('Crossing The Rubicon', '03:18:00', 3),
('Sleepwalking', '03:52:00', 4),
('Полёт на дельтаплане', '03:47:00', 5),
('Иностранец', '04:05:00', 6),
('Береги себя, мой ангел', '03:51:00', 6);

--добавим список сборников
INSERT INTO collections_list (collection_name,collection_release_year,id_track_list)
VALUES ('Common Ground Companion EP', '2019', 1),
('Group Therapy Radio', '2021', 2),
('2004-2013', '2017', 4),
('Коллекция лучших альбомов', '2014', 5);

--добавим "посредников"
INSERT INTO broker_genres_performers (id_performers_list, id_genres_list)
VALUES (1,1), (2,1), (3,2), (4,2), (5,3), (6,3);

INSERT INTO broker_performers_album (id_album_list,id_performers_list)
VALUES (1,1), (2,2), (3,3), (4,4), (5,5), (6,6);
