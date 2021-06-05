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
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `id` int NOT NULL,
  `Category` int NOT NULL,
  `Priory` int NOT NULL,
  `Status` int NOT NULL,
  `Title` tinytext,
  `Description` text,
  `RequestSource` int NOT NULL,
  `Type` int NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `Ord_S_fk_idx` (`Status`),
  KEY `Ord_P_fk_idx` (`Priory`),
  KEY `Ord_R_fk_idx` (`RequestSource`),
  KEY `fk_orders_categories1_idx` (`Category`),
  KEY `Ord_T_fk_idx` (`Type`),
  CONSTRAINT `fk_orders_categories1` FOREIGN KEY (`Category`) REFERENCES `categories` (`id`),
  CONSTRAINT `Ord_P_fk` FOREIGN KEY (`Priory`) REFERENCES `priority` (`id`),
  CONSTRAINT `Ord_R_fk` FOREIGN KEY (`RequestSource`) REFERENCES `requestsource` (`id`),
  CONSTRAINT `Ord_S_fk` FOREIGN KEY (`Status`) REFERENCES `status` (`id`),
  CONSTRAINT `Ord_T_fk` FOREIGN KEY (`Type`) REFERENCES `types` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,5,3,6,'142108 Сосновая 10 - Подключение сети интернет','Заказчик подал заявку на подключение к сети интернет скоростью до 100 Mbit/s +7(900)5550055',1,1),(2,7,3,2,'142100 Долгово9 - Обрыв кабеля','Из-за наледей оборвало кабель',2,1),(3,3,3,2,'142106 Правды 28 - Ошибка при запуске приложения авторизации','При запуске приложения выдает ошибку № 0х00000035f \"Ошибка авторизации, обратитесь к администратору\"',2,1),(4,9,3,3,'142122 Циолковского 15 - Wi-fi роутер \"Приказал долго жить\"','В один прекрасный момент роутер просто отключился и больше не реагирует на команды',1,1),(5,5,3,1,'142100 пр-т Мира 12 - Подключение к локальной сети','Подключить к внутренней сети организации еще 4 терминала (настольных ПК)',1,1),(6,6,4,2,'142148 ул. Загородная - Восстановление пробитого кабеля','Во время ремонтных работ был задет кабель широкополостного соединения с сетью интернет (Витая пара до 100 мб/с), тебуется замена и монтаж',1,2),(7,1,3,1,'1','1',1,1),(8,1,3,1,'1','1',1,1),(9,1,3,1,'1','1',1,1),(10,1,3,1,'1','1',1,1),(11,1,3,1,'1','1',1,1),(12,1,3,1,'1','1',1,1),(13,1,3,1,'1','1',1,1),(14,1,3,1,'1','1',1,1),(15,1,3,1,'1','1',1,1),(16,1,3,1,'1','1',1,1),(17,1,3,1,'1','1',1,1),(18,1,3,1,'1','1',1,1);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-05-21 20:34:04
