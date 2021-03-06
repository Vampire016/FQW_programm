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
-- Table structure for table `actions`
--

DROP TABLE IF EXISTS `actions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `actions` (
  `id` int NOT NULL,
  `act_pos` int DEFAULT NULL,
  `right_or_left` varchar(1) NOT NULL,
  `id_ord` int NOT NULL,
  `id_creator` int NOT NULL,
  `id_editor` int NOT NULL,
  `date_create` datetime NOT NULL,
  `act_type` int NOT NULL,
  `date_beg` datetime DEFAULT NULL,
  `date_fin` datetime DEFAULT NULL,
  `check` tinyint(1) DEFAULT NULL,
  `text` longtext,
  `date_agree` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_actions_orders_idx` (`id_ord`),
  CONSTRAINT `fk_actions_orders` FOREIGN KEY (`id_ord`) REFERENCES `orders` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `actions`
--

LOCK TABLES `actions` WRITE;
/*!40000 ALTER TABLE `actions` DISABLE KEYS */;
INSERT INTO `actions` VALUES (1,0,'L',1,1,1,'2021-03-07 15:56:00',1,NULL,NULL,NULL,NULL,NULL),(2,0,'L',2,4,4,'2021-03-12 16:10:00',1,NULL,NULL,NULL,NULL,NULL),(3,0,'L',3,4,4,'2021-03-13 13:10:00',1,NULL,NULL,NULL,NULL,NULL),(4,0,'L',4,3,3,'2021-03-13 13:21:00',1,NULL,NULL,NULL,NULL,NULL),(5,0,'L',5,1,1,'2021-04-26 20:26:00',1,NULL,NULL,NULL,NULL,NULL),(6,0,'L',6,4,4,'2021-04-26 20:34:00',1,NULL,NULL,NULL,NULL,NULL),(7,0,'L',7,1,1,'2021-06-06 12:00:00',1,NULL,NULL,NULL,NULL,NULL),(8,0,'L',8,4,4,'2021-06-06 12:00:00',1,NULL,NULL,NULL,NULL,NULL),(10,1,'L',4,3,3,'2021-06-07 19:13:49',3,'2021-06-07 12:00:00','2021-06-07 14:00:00',1,'?????????????????? ???????????????? ????????????????????????\n\n?????????????????????? ???? ?????????????????? ???????? ?????????????????????? ???????????????? (4??)',NULL),(11,2,'L',4,3,3,'2021-06-07 19:42:15',4,NULL,NULL,NULL,'?????????????? ???????????????????????? ??????????????????????, ???????????????????? ???????????????????? ?? ????????.\n\n???????????????? ???????????? ????????????, ???????????? ?? ?????????????? 3850 ??. ????????????????','2021-06-07 17:36:30'),(12,0,'L',9,1,1,'2021-06-10 15:35:00',1,NULL,NULL,NULL,NULL,NULL),(13,0,'L',10,4,4,'2021-06-10 15:43:00',1,NULL,NULL,NULL,NULL,NULL),(14,0,'L',11,4,4,'2021-06-10 15:59:00',1,NULL,NULL,NULL,NULL,NULL),(15,0,'L',12,4,4,'2021-06-10 18:21:00',1,NULL,NULL,NULL,NULL,NULL),(16,0,'L',13,4,4,'2021-06-10 18:26:00',1,NULL,NULL,NULL,NULL,NULL),(17,0,'L',14,4,4,'2021-06-10 18:32:00',1,NULL,NULL,NULL,NULL,NULL),(18,0,'L',15,4,4,'2021-06-10 19:00:00',1,NULL,NULL,NULL,NULL,NULL),(19,0,'L',16,4,4,'2021-06-10 20:12:00',1,NULL,NULL,NULL,NULL,NULL),(20,0,'L',17,4,4,'2021-06-10 20:16:00',1,NULL,NULL,NULL,NULL,NULL),(21,0,'L',18,4,4,'2021-06-10 20:18:00',1,NULL,NULL,NULL,NULL,NULL),(22,0,'L',19,4,4,'2021-06-10 20:28:00',1,NULL,NULL,NULL,NULL,NULL),(23,0,'L',20,4,4,'2021-06-10 20:54:00',1,NULL,NULL,NULL,NULL,NULL),(24,0,'L',21,4,4,'2021-06-10 20:57:00',1,NULL,NULL,NULL,NULL,NULL),(25,0,'L',22,4,4,'2021-06-10 21:07:00',1,NULL,NULL,NULL,NULL,NULL),(26,0,'L',23,4,4,'2021-06-10 21:12:00',1,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `actions` ENABLE KEYS */;
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
