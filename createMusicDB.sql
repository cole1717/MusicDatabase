-- MySQL Workbench Forward Engineering
SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema music
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema music
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `music`;
CREATE SCHEMA IF NOT EXISTS `music` DEFAULT CHARACTER SET utf8 ;
USE `music` ;

-- -----------------------------------------------------
-- Table `music`.`Artists`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Artists` (
  `artistId` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(60) NOT NULL,
  PRIMARY KEY (`artistId`));


-- -----------------------------------------------------
-- Table `music`.`Genres`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Genres` (
  `genreId` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`genreId`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `music`.`Albums`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Albums` (
  `albumId` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(60) NOT NULL,
  `releaseDate` DATE NULL,
  `artistId` INT NOT NULL,
  `genreId` INT NOT NULL,
  PRIMARY KEY (`albumId`),
  INDEX `fk_Albums_Artists_idx` (`artistId` ASC),
  INDEX `fk_Albums_Genres1_idx` (`genreId` ASC),
  CONSTRAINT `fk_Albums_Artists`
    FOREIGN KEY (`artistId`)
    REFERENCES `music`.`Artists` (`artistId`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_Albums_Genres`
    FOREIGN KEY (`genreId`)
    REFERENCES `music`.`Genres` (`genreId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);


-- -----------------------------------------------------
-- Table `music`.`Tracks`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Tracks` (
  `trackId` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(60) NOT NULL,
  `duration` TIME(0) NULL,
  `rating` ENUM('1', '2', '3', '4', '5') NULL,
  `albumId` INT NOT NULL,
  `artistId` INT NOT NULL,
  PRIMARY KEY (`trackId`),
  INDEX `fk_Tracks_Albums1_idx` (`albumId` ASC),
  CONSTRAINT `fk_Tracks_Albums`
    FOREIGN KEY (`albumId`)
    REFERENCES `music`.`Albums` (`albumId`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `music`.`Playlists`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Playlists` (
  `playlistId` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(60) NOT NULL,
  PRIMARY KEY (`playlistId`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `music`.`Playlists_has_Tracks`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `music`.`Playlists_has_Tracks` (
  `playlistId` INT NOT NULL,
  `trackId` INT NOT NULL,
  PRIMARY KEY (`playlistId`, `trackId`),
  INDEX `fk_Playlists_has_Tracks_Tracks1_idx` (`trackId` ASC),
  INDEX `fk_Playlists_has_Tracks_Playlists1_idx` (`playlistId` ASC),
  CONSTRAINT `fk_Playlists_has_Tracks_Playlists1`
    FOREIGN KEY (`playlistId`)
    REFERENCES `music`.`Playlists` (`playlistId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Playlists_has_Tracks_Tracks1`
    FOREIGN KEY (`trackId`)
    REFERENCES `music`.`Tracks` (`trackId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;


-- -----------------------------------------------------
-- Procedure `search_artist`
-- -----------------------------------------------------
DROP PROCEDURE IF EXISTS search_artist;

DELIMITER $$
CREATE PROCEDURE search_artist(artist_name VARCHAR(60))
BEGIN
	IF 	 (artist_name = '')
    THEN 
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
			FROM tracks, artists, albums
			WHERE tracks.artistId = artists.artistId
			AND tracks.albumId = albums.albumId
			ORDER BY artist;
		END;
	ELSE
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
			FROM tracks, artists, albums
			WHERE artists.name LIKE CONCAT('%', artist_name, '%')
			AND tracks.artistId = artists.artistId
			AND tracks.albumId = albums.albumId
			ORDER BY albums.name;
		END;
    END IF;
END
$$ DELIMITER ;


-- ------------------------------------------------------
-- Procedure `search_song`
-- ------------------------------------------------------
DROP PROCEDURE IF EXISTS search_song;

DELIMITER $$
CREATE PROCEDURE search_song(song_name VARCHAR(60))
BEGIN
	IF (song_name = '')
    THEN
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
            FROM tracks, artists, albums
            WHERE tracks.artistId = artists.artistId
            AND tracks.albumId = albums.albumId
            ORDER BY artist;
		END;
	ELSE
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
			FROM tracks, artists, albums
			WHERE tracks.name LIKE CONCAT('%', song_name, '%')
			AND tracks.artistId = artists.artistId
			AND tracks.albumId = albums.albumId;
		END;
	END IF;
END
$$ DELIMITER ;


-- ------------------------------------------------------
-- Procedure `search_album`
-- ------------------------------------------------------
DROP PROCEDURE IF EXISTS search_album;

DELIMITER $$
CREATE PROCEDURE search_album(album_name VARCHAR(60))
BEGIN
	IF (album_name = '')
    THEN
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
            FROM tracks, artists, albums
            WHERE tracks.artistId = artists.artistId
            AND tracks.albumId = albums.albumId;
		END;
	ELSE
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
			FROM tracks, artists, albums
			WHERE albums.name LIKE CONCAT('%', album_name, '%')
			AND tracks.artistId = artists.artistId
			AND tracks.albumId = albums.albumId;
		END;
	END IF;
END
$$ DELIMITER ;


-- ------------------------------------------------------
-- Procedure `search_genre`
-- ------------------------------------------------------
DROP PROCEDURE IF EXISTS search_genre;

DELIMITER $$
CREATE PROCEDURE search_genre(genre_name VARCHAR(60))
BEGIN
	IF (genre_name = '')
	THEN
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
            FROM tracks, artists, albums
            WHERE tracks.artistId = artists.artistId
            AND tracks.albumId = albums.albumId
            ORDER BY artists.name, albums.name;
		END;
	ELSE
		BEGIN
			SELECT tracks.name AS title, 
				artists.name AS artist, albums.name AS album
			FROM tracks, artists, albums, genres
			WHERE genres.name LIKE CONCAT('%', genre_name, '%')
			AND genres.genreId = albums.genreId
			AND tracks.artistId = artists.artistId
			AND tracks.albumId = albums.albumId
			ORDER BY artists.name , albums.name;
		END;
	END IF;
END
$$ DELIMITER ;

