CREATE TABLE Artist (
  id INT PRIMARY KEY,
  name VARCHAR(255)
);

CREATE TABLE Genre (
  id INT PRIMARY KEY,
  name VARCHAR(255)
);

CREATE TABLE Album (
  id INT PRIMARY KEY,
  name VARCHAR(255),
  year INT
);

CREATE TABLE Track (
  id INT PRIMARY KEY,
  name VARCHAR(255),
  duration INT,
  album_id INT,
  FOREIGN KEY (album_id) REFERENCES Album(id)
);

CREATE TABLE Compilation (
  id INT PRIMARY KEY,
  name VARCHAR(255),
  year INT
);

CREATE TABLE ArtistGenre (
  artist_id INT,
  genre_id INT,
  FOREIGN KEY (artist_id) REFERENCES Artist(id),
  FOREIGN KEY (genre_id) REFERENCES Genre(id)
);

CREATE TABLE ArtistAlbum (
  artist_id INT,
  album_id INT,
  FOREIGN KEY (artist_id) REFERENCES Artist(id),
  FOREIGN KEY (album_id) REFERENCES Album(id)
);

CREATE TABLE TrackCompilation (
  track_id INT,
  compilation_id INT,
  FOREIGN KEY (track_id) REFERENCES Track(id),
  FOREIGN KEY (compilation_id) REFERENCES Compilation(id)
);
