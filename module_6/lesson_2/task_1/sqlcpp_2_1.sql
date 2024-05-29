CREATE TABLE IF NOT EXISTS genres_list (
	id_genres_list SERIAL PRIMARY key,	
	genre_name VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS performers_list (
	id_performers_list SERIAL PRIMARY key,	
	performer_name VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS album_list (
	id_album_list SERIAL PRIMARY key,	
	album_name VARCHAR(40) NOT null,
	album_release_year VARCHAR(4) NOT null
);

CREATE TABLE IF NOT EXISTS track_list (
	id_track_list SERIAL PRIMARY key,	
	track_name VARCHAR(40) NOT null,
	duration_track TIME NOT null,
	id_album_list INTEGER NOT NULL references album_list(id_album_list)
);

CREATE TABLE IF NOT EXISTS broker_genres_performers (
	id_genres_list INTEGER NOT NULL references genres_list(id_genres_list),
	id_performers_list INTEGER NOT NULL references performers_list(id_performers_list)
);

CREATE TABLE IF NOT EXISTS broker_performers_album (
	id_album_list INTEGER NOT NULL references album_list(id_album_list),
	id_performers_list INTEGER NOT NULL references performers_list(id_performers_list)
);

CREATE TABLE IF NOT EXISTS collections_list (
	id_collections_list SERIAL PRIMARY key,	
	collection_name VARCHAR(40) NOT null,
	collection_release_year VARCHAR(4) NOT null,
	id_track_list INTEGER NOT NULL references track_list(id_track_list),
	id_album_list INTEGER NOT NULL references album_list(id_album_list)
);

CREATE TABLE IF NOT EXISTS broker_album_track (
	id_album_list INTEGER NOT NULL references album_list(id_album_list),
	id_track_list INTEGER NOT NULL references track_list(id_track_list)
);
