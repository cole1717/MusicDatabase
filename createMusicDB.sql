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


-- ------------------------------------------------------
-- View `table_view`
-- ------------------------------------------------------
CREATE VIEW table_view AS
	SELECT tracks.name AS title, artists.name AS artist, albums.name AS album
	FROM tracks, artists, albums
	WHERE artists.artistId = albums.artistId
	AND tracks.albumId = albums.albumId;

INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('1', 'Rock');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('2', 'Pop');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('3', 'Country');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('4', 'Hip-hop');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('5', 'Classical');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('6', 'Alternative');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('7', 'Jazz');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('8', 'Reggae');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('9', 'Blues');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('10', 'Techno');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('11', 'Electronic');
INSERT INTO `music`.`genres` (`genreId`, `name`) VALUES ('12', 'Experimental');

INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('1', 'AC/DC');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('2', 'Backstreet Boys');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('3', 'Zac Brown Band');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('4', 'Led Zeppelin');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('5', 'Genesis');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('6', 'Eagles');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('7', 'Sublime');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('8', 'Flo Rida');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('9', 'Bob Marley');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('10', 'Chris Stapleton');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('11', 'Chris Young');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('12', 'Kenny Chesney');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('13', 'Journey');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('14', 'The Beatles');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('15', 'Stevie Ray Vaughan');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('16', 'Herbie Hancock');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('17', 'Eiffel 65');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('18', 'Tim Sparks');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('19', 'Will Smith');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('20', 'Bruno Mars');
INSERT INTO `music`.`artists` (`artistId`, `name`) VALUES ('21', 'Dirty Projectors');

INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('1', 'Back in Black', '1980-07-25', '1', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('2', 'Backstreet Boys', '1996-05-06', '2', '2');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('3', 'The Foundation', '2008-11-18', '3', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('4', 'You Get What You Give', '2010-09-21', '3', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('5', 'Led Zeppelin IV', '1971-11-08', '4', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('6', 'Led Zeppelin', '1969-01-12', '4', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('7', 'Invisible Touch', '1986-06-06', '5', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('8', 'Hotel California', '1976-12-08', '6', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('9', 'Sublime', '1996-07-30', '7', '6');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('10', 'The Razors Edge', '1990-10-24', '1', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('11', 'Wild Ones', '2012-07-03', '8', '4');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('12', 'Exodus', '1977-06-03', '9', '8');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('13', 'Traveller', '2015-05-05', '10', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('14', 'A.M.', '2013-09-17', '11', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('15', 'Be as You Are (Songs from an Old Blue Chair)', '2005-01-25', '12', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('16', 'Welcome to the Fishbowl', '2012-06-19', '12', '3');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('17', 'Escape', '1981-07-31', '13', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('18', 'Sgt. Pepper\'s Lonely Hearts Club Band', '1966-11-24', '14', '1');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('19', 'Texas Flood', '1983-06-13', '15', '9');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('20', 'Possibilities', '2005-08-30', '16', '7');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('21', 'Europop', '1999-05-22', '17', '10');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('22', 'The Nutcracker Suite', '1993-09-28', '18', '5');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('23', 'Big Willie Style', '1997-12-25', '19', '4');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('24', '24K Magic', '2016-11-18', '20', '2');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('25', 'Dirty Projectors', '2017-2-21', '21', '11');
INSERT INTO `music`.`albums` (`albumId`, `name`, `releaseDate`, `artistId`, `genreId`) VALUES ('26', 'Bitte Orca', '2009-6-9', '21', '12');

INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('1', 'Hells Bells', '5:12', '5', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('2', 'Shoot To Thrill', '5:17', '5', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('3', 'What Do You Do For Money Honey', '3:36', '3', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('4', 'Givin\' The Dog a Bone', '3:32', '3', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('5', 'Let Me Put My Love Into You', '4:15', '4', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('6', 'Back In Black', '4:16', '5', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('7', 'You Shook Me All Night Long', '3:30', '5', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('8', 'Have A Drink On Me', '3:58', '4', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('9', 'Shake A Leg', '4:06', '3', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('10', 'Rock And Roll Ain\'t Noise Pollution', '4:26', '4', '1', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('11', 'We\'ve Got It Goin\' On', '3:41', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('12', 'Quit Playing Games (With My Heart)', '3:54', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('13', 'As Long As You Love Me', '3:34', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('14', 'Everybody (Backstreet\'s Back)', '4:48', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('15', 'All I Have To Give', '4:35', '3', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('16', 'Anywhere For You', '4:41', '2', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('17', 'Hey, Mr. DJ (Keep Playin\' This Song)', '4:26', '3', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('18', 'I\'ll Never Break Your Heart', '4:48', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('19', 'Darlin\'', '5:32', '2', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('20', 'Get Down (You\'re The One For Me)', '3:52', '3', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('21', 'Set Adrift On Memory Bliss', '3:30', '3', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('22', 'If You Want It To Be Good Girl', '4:48', '4', '2', '2');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('23', 'Whatever It Is', '3:28', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('24', 'Where the Boat Leaves From', '3:43', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('25', 'Mary', '2:48', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('26', 'It\'s Not OK', '4:11', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('27', 'Jolene', '4:20', '3', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('28', 'Sic \'Em On a Chicken', '3:52', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('29', 'Toes', '4:21', '5', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('30', 'Violin Intro to Free', '1:02', '2', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('31', 'Free', '3:49', '4', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('32', 'Chicken Fried', '3:57', '5', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('33', 'Different Kind of Fine', '3:18', '5', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('34', 'Highway 20 Ride', '3:49', '5', '3', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('35', 'Let It Go', '4:37', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('36', 'No Hurry', '3:46', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('37', 'I Play the Road', '4:20', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('38', 'Cold Hearted', '3:48', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('39', 'Quiet Your Mind', '3:40', '3', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('40', 'Colder Weather', '4:34', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('41', 'Settle Me Down', '3:22', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('42', 'Who Knows', '9:59', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('43', 'Martin', '5:06', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('44', 'Knee Deep (feat. Jimmy Buffett)', '3:23', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('45', 'Whiskey\'s Gone', '2:47', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('46', 'As She\'s Walking Away (feat. Alan Jackson)', '3:44', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('47', 'Keep Me In Mind', '3:34', '5', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('48', 'Make This Day', '4:03', '4', '4', '3');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('49', 'Black Dog', '4:54', '4', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('50', 'Rock And Roll', '3:40', '5', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('51', 'The Battle of Evermore', '5:51', '3', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('52', 'Stairway to Heaven', '8:02', '5', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('53', 'Misty Mountain Hop', '4:38', '4', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('54', 'Four Sticks', '4:44', '2', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('55', 'Going to California', '3:31', '3', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('56', 'When the Levee Breaks', '7:07', '5', '5', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('57', 'Good Times Bad Times', '2:46', '4', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('58', 'Babe I\'m Gonna Leave You', '6:42', '3', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('59', 'You Shook Me', '6:28', '3', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('60', 'Dazed and Confused', '6:28', '5', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('61', 'Your Time Is Gonna Come', '4:34', '3', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('62', 'Black Mountain Side', '2:12', '2', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('63', 'Communication Breakdown', '2:30', '4', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('64', 'I Can\'t Quit You Baby', '4:42', '4', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('65', 'How Many More Times', '8:27', '3', '6', '4');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('66', 'Invisible Touch', '3:26', '5', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('67', 'Tonight, Tonight, Tonight', '8:49', '4', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('68', 'Land of Confusion', '4:45', '5', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('69', 'In Too Deep', '4:59', '4', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('70', 'Anything She Does', '4:06', '4', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('71', 'Domino', '10:42', '5', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('72', 'Throwing It All Away', '3:51', '3', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('73', 'The Brazilian', '4:49', '2', '7', '5');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('74', 'Hotel California', '6:30', '5', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('75', 'New Kid in Town', '5:04', '3', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('76', 'Life in the Fast Lane', '4:46', '5', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('77', 'Wasted Time', '4:55', '4', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('78', 'Victim of Love', '4:11', '4', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('79', 'Pretty Maids All in a Row', '4:05', '3', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('80', 'Try and Love Again', '5:10', '3', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('81', 'The Last Resort', '7:25', '4', '8', '6');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('82', 'Garden Grove', '4:22', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('83', 'What I Got', '2:51', '5', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('84', 'Wrong Way', '2:16', '4', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('85', 'Same in the End', '2:36', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('86', 'April 29, 1992 (Miami)', '3:53', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('87', 'Santeria', '3:03', '5', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('88', 'Seed', '2:10', '3', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('89', 'Jailhouse', '4:52', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('90', 'Pawn Shop', '6:06', '4', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('91', 'Paddle Out', '1:15', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('92', 'The Ballad of Johnny Butt', '2:11', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('93', 'Burritos', '3:55', '1', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('94', 'Under My Voodoo', '3:25', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('95', 'Get Ready', '4:50', '2', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('96', 'Caress Me Down', '3:31', '4', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('97', 'Doin\' Time', '4:14', '4', '9', '7');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('98', 'Thunderstruck', '4:52', '5', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('99', 'Fire Your Guns', '2:53', '3', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('100', 'Moneytalks', '3:48', '4', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('101', 'The Razors Edge', '3:48', '5', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('102', 'Mistress for Christmas', '3:59', '3', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('103', 'Rock Your Heart Out', '4:06', '2', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('104', 'Are You Ready', '4:10', '4', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('105', 'Shot of Love', '3:56', '3', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('106', 'Let\'s Make It', '3:32', '2', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('107', 'Goodbye & Good Riddance to Bad Luck', '3:13', '2', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('108', 'If You Dare', '3:08', '3', '10', '1');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('109', 'Whistle', '3:45', '4', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('110', 'Wild Ones (feat. Sia)', '3:53', '5', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('111', 'Let It Roll', '3:14', '3', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('112', 'Good Feeling', '4:08', '5', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('113', 'In My Mind, Part 2 (feat. Georgi Kay)', '4:30', '3', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('114', 'Sweet Spot (feat. Jennifer Lopez)', '3:48', '3', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('115', 'Thinking of You', '3:40', '3', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('116', 'I Cry', '3:43', '4', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('117', 'Run (feat. Redfoo0', '3:53', '3', '11', '8');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('118', 'Natural Mystic', '3:28', '3', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('119', 'So Much Things to Say', '3:08', '3', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('120', 'Guiltiness', '3:19', '2', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('121', 'The Heathen', '2:32', '2', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('122', 'Exodus', '7:40', '3', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('123', 'Jamming', '3:31', '4', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('124', 'Waiting in Vain', '4:16', '3', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('125', 'Turn Your Lights Down Low', '3:39', '3', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('126', 'Three Little Birds', '3:00', '5', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('127', 'One Love/People Get Ready', '2:52', '5', '12', '9');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('128', 'Traveller', '3:42', '5', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('129', 'Fire Away', '4:04', '4', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('130', 'Tennessee Whiskey', '4:52', '5', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('131', 'Parachute', '4:13', '5', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('132', 'Whiskey and You', '3:56', '4', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('133', 'Nobody to Blame', '4:04', '4', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('134', 'More of You', '4:37', '3', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('135', 'When the Stars Come Out', '4:16', '2', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('136', 'Daddy Doesn\'t Pray Anymore', '4:09', '3', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('137', 'Was It 26', '4:49', '3', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('138', 'The Devil Named Music', '6:07', '4', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('139', 'Outlaw State of Mind', '5:37', '4', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('140', 'Sometimes I Cry', '4:02', '3', '13', '10');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('141', 'Aw Naw', '3:09', '5', '14', '11');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('142', 'Lonely Eyes', '3:39', '4', '14', '11');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('143', 'Goodbye', '3:46', '3', '14', '11');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('144', 'Who I Am With You', '3:11', '5', '14', '11');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('145', 'Guitars and Tiki Bars', '4:36', '5', '15', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('146', 'Island Boy', '3:56', '3', '15', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('147', 'Somewhere in the Sun', '4:45', '3', '15', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('148', 'Boston', '4:16', '4', '15', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('149', 'Come Over', '4:09', '3', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('150', 'Feel Like a Rock Star (feat. Tim McGraw)', '3:28', '5', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('151', 'Sing \'Em Good My Friend', '4:38', '5', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('152', 'Welcome to the Fishbowl', '3:30', '4', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('153', 'El Cerrito Place', '5:52', '4', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('154', 'Time Flies', '3:37', '4', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('155', 'You and Tequila (feat. Grace Potter)', '4:49', '4', '16', '12');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('156', 'Don\'t Stop Believin', '4:11', '5', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('157', 'Who\'s Crying Now', '5:01', '4', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('158', 'Keep On runnin', '3:40', '3', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('159', 'Escape', '5:17', '3', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('160', 'Lay It Down', '4:13', '4', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('161', 'Open Arms', '3:23', '5', '17', '13');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('162', 'Sgt. Pepper\'s Lonely Hearts Club Band', '2:02', '5', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('163', 'With a Little Help From My Friends', '2:44', '4', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('164', 'Lucy in the Sky with Diamonds', '3:28', '4', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('165', 'Getting Better', '2:48', '3', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('166', 'Being for the Benefit of Mr. Kite!', '2:37', '3', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('167', 'When I\'m Sixty-Four', '2:37', '5', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('168', 'A Day in the Life', '5:39', '4', '18', '14');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('169', 'Love Struck Baby', '2:24', '3', '19', '15');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('170', 'Pride and Joy', '3:40', '5', '19', '15');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('171', 'Texas Flood', '5:21', '4', '19', '15');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('172', 'Tell Me', '2:49', '3', '19', '15');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('173', 'Dirty Pool', '5:02', '3', '19', '15');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('174', 'Stitched Up (feat. John Mayer)', '5:27', '5', '20', '16');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('175', 'Safiatou (feat. Santana)', '5:25', '4', '20', '16');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('176', 'I Do It for Your Love (feat. Paul Simon)', '5:58', '3', '20', '16');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('177', 'Sister Moon (feat. Sting)', '6:54', '4', '20', '16');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('178', 'Blue (Da Ba Dee)', '3:30', '5', '21', '17');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('179', 'Too Much of Heaven', '5:17', '2', '21', '17');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('180', 'Move Your Body', '4:28', '4', '21', '17');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('181', 'Hyperlind (Deep Down)', '4:57', '3', '21', '17');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('182', 'SIlicon World', '4:31', '2', '21', '17');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('183', 'Overture (adap. P.I. Tchaikovsky)', '2:10', '4', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('184', 'March of the Toy Soldiers (adap. P.I. Tchaikovsky)', '2:12', '4', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('185', 'Dance of the Sugar Plum Fairy (adap. P.I. Tchaikovsky)', '1:57', '5', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('186', 'Waltz of the Flowers (adap. P.I. Tchaikovsky)', '6:11', '3', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('187', 'Samiotisa', '2:33', '2', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('188', 'The Blues on Bartok Street', '3:25', '3', '22', '18');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('189', 'Y\'All Know', '3:57', '3', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('190', 'Gettin\' Jiggy Wit It', '3:47', '5', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('191', 'Candy', '3:56', '4', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('192', 'Don\'t Say Nothin', '4:22', '2', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('193', 'Miami', '3:17', '5', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('194', 'Yes Yes Y\'All', '4:23', '4', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('195', 'It\'s All Good', '4:04', '3', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('196', 'Just the Two of Us', '5:15', '4', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('197', 'Big Willie Style', '3:35', '4', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('198', 'Men in Black', '3:47', '5', '23', '19');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('199', '24K Magic', '3:46', '5', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('200', 'Chunky', '3:06', '3', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('201', 'Perm', '3:30', '3', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('202', 'That\'s What I Like', '3:26', '5', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('203', 'Versace on the Floor', '4:21', '4', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('204', 'Straight Up & Down', '3:18', '3', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('205', 'Calling All My Lovelies', '4:10', '2', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('206', 'Finesse', '3:10', '4', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('207', 'Too Good to Say Goodbye', '4:41', '3', '24', '20');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('208', 'Keep Your Name', '4:30', '5', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('209', 'Death Spiral', '5:08', '4', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('210', 'Up In Hudson', '7:31', '4', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('211', 'Work Together', '4:24', '5', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('212', 'Little Bubble', '5:05', '3', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('213', 'Winner Take Nothing', '4:49', '4', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('214', 'Ascent Through Clouds', '6:56', '5', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('215', 'Cool Your Heart', '3:49', '4', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('216', 'I See You', '6:05', '4', '25', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('217', 'Cannibal Resource', '3:55', '4', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('218', 'Temecula Sunrise', '5:05', '5', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('219', 'The Bride', '2:49', '3', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('220', 'Stillness Is the Move', '5:14', '4', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('221', 'Thwo Doves', '3:42', '5', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('222', 'Useful Chamber', '6:28', '4', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('223', 'No Intention', '4:17', '5', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('224', 'Remade Horizon', '3:55', '5', '26', '21');
INSERT INTO `music`.`tracks` (`trackId`, `name`, `duration`, `rating`, `albumId`, `artistId`) VALUES ('225', 'Fluorescent Half Dome', '5:45', '4', '26', '21');
