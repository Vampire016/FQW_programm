-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: mysqldb
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `id` int NOT NULL,
  `FullName` tinytext GENERATED ALWAYS AS (concat(`SecName`,_utf8mb4' ',`Name`)) VIRTUAL,
  `Name` tinytext,
  `SecName` tinytext,
  `Login` varchar(26) DEFAULT NULL,
  `Password` varchar(12) DEFAULT NULL,
  `Rights` varchar(20) DEFAULT NULL,
  `Function` int DEFAULT NULL,
  `Active` tinyint(1) NOT NULL,
  `Valid_from` datetime DEFAULT NULL,
  `Valid_until` datetime DEFAULT NULL,
  `Email` tinytext,
  `Phone` tinytext,
  `Phone_m` tinytext,
  `Phone2` tinytext,
  `Phone2_m` tinytext,
  `Description` text,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `Login_UNIQUE` (`Login`),
  KEY `fk_users_rights1_idx` (`Rights`),
  KEY `fk_users_func1_idx` (`Function`),
  CONSTRAINT `fk_users_func1` FOREIGN KEY (`Function`) REFERENCES `functions` (`id`),
  CONSTRAINT `fk_users_rights1` FOREIGN KEY (`Rights`) REFERENCES `rights` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `Name`, `SecName`, `Login`, `Password`, `Rights`, `Function`, `Active`, `Valid_from`, `Valid_until`, `Email`, `Phone`, `Phone_m`, `Phone2`, `Phone2_m`, `Description`) VALUES (1,'Илья','Панин','i.panin','zarkj17n','SuperAdmin',1,1,'2021-04-02 00:00:00','2021-06-20 23:59:59','pan-ov-16@mail.ru','+7-(496)-753-16-12','+7-(901)-791-80-71',NULL,NULL,'Разработчик приложения по учету заявок от клиентов'),(2,'Алексей','Панин','a.panin','123','Admin',2,1,NULL,NULL,NULL,'+7-(903)-999-99-99','+7-()---','+7-()---','+7-()---',NULL),(3,'Наталья','Панина','n.panina','1234','Manager',6,1,NULL,NULL,NULL,'+7-(965)-344-41-65','+7-()---','+7-()---','+7-()---',NULL),(4,'робот','Почтовый','post-bot','post-bot',NULL,NULL,1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(5,'test','Demo','321','321','SuperAdmin',NULL,1,NULL,NULL,'','+7-(000)-000-00-00',NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-06-10 21:14:28
