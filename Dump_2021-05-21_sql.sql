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
-- Table structure for table `categories`
--

DROP TABLE IF EXISTS `categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `categories` (
  `id` int NOT NULL,
  `NameSC` tinytext,
  `NameC` tinytext,
  `C+SC` tinytext GENERATED ALWAYS AS (if((`NameSC` <> _utf8mb4''),concat(`NameC`,_utf8mb4' -> ',`NameSC`),`NameC`)) VIRTUAL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categories`
--

LOCK TABLES `categories` WRITE;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
INSERT INTO `categories` (`id`, `NameSC`, `NameC`) VALUES (1,'Аудит','Администрирования'),(2,'Неисправность подключения','Администрирования'),(3,'Ошибка приложения','Администрирования'),(4,'Низкая скорость','Интернет'),(5,'Подключение','Интернет'),(6,'Прочие работы','Интернет'),(7,'Ремонт','Интернет'),(8,'Строительство','Интернет'),(9,'Неисправность техники','Техническое обеспечение'),(10,NULL,'Аудит'),(11,NULL,'Обновление 1С');
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `control`
--

DROP TABLE IF EXISTS `control`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `control` (
  `id` int NOT NULL,
  `WhoControlling` int DEFAULT NULL,
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_control_users1_idx` (`WhoControlling`),
  CONSTRAINT `fk_control_orders1` FOREIGN KEY (`id`) REFERENCES `orders` (`id`),
  CONSTRAINT `fk_control_users1` FOREIGN KEY (`WhoControlling`) REFERENCES `users` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `control`
--

LOCK TABLES `control` WRITE;
/*!40000 ALTER TABLE `control` DISABLE KEYS */;
INSERT INTO `control` VALUES (1,NULL),(2,NULL),(3,NULL),(4,NULL),(5,NULL),(6,NULL),(7,NULL),(8,NULL),(9,NULL),(10,NULL),(11,NULL),(12,NULL),(13,NULL),(14,NULL),(15,NULL),(16,NULL),(17,NULL),(18,NULL);
/*!40000 ALTER TABLE `control` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `create`
--

DROP TABLE IF EXISTS `create`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `create` (
  `id` int NOT NULL,
  `DateOpen` datetime DEFAULT NULL,
  `WhoCreate` int NOT NULL,
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_create_users1_idx` (`WhoCreate`),
  CONSTRAINT `fk_create_orders1` FOREIGN KEY (`id`) REFERENCES `orders` (`id`),
  CONSTRAINT `fk_create_users1` FOREIGN KEY (`WhoCreate`) REFERENCES `users` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `create`
--

LOCK TABLES `create` WRITE;
/*!40000 ALTER TABLE `create` DISABLE KEYS */;
INSERT INTO `create` VALUES (1,'2021-03-07 15:56:00',1),(2,'2021-03-12 16:10:00',4),(3,'2021-03-13 13:10:00',4),(4,'2021-03-13 13:21:00',3),(5,'2021-04-26 20:26:00',1),(6,'2021-04-26 20:34:00',4),(7,'2021-05-01 12:00:00',4),(8,'2021-05-02 12:00:00',4),(9,'2021-05-03 12:00:00',4),(10,'2021-05-04 12:00:00',1),(11,'2021-05-05 12:00:00',4),(12,'2021-05-06 12:00:00',1),(13,'2021-05-07 12:00:00',4),(14,'2021-05-08 12:00:00',1),(15,'2021-05-09 12:00:00',4),(16,'2021-05-10 12:00:00',4),(17,'2021-05-11 12:00:00',4),(18,'2021-05-12 12:00:00',1);
/*!40000 ALTER TABLE `create` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `edit`
--

DROP TABLE IF EXISTS `edit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `edit` (
  `id` int NOT NULL,
  `DateEdit` datetime DEFAULT NULL,
  `WhoEdit` int NOT NULL,
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_edit_orders1_idx` (`id`),
  KEY `fk_edit_users1_idx` (`WhoEdit`),
  CONSTRAINT `fk_edit_orders1` FOREIGN KEY (`id`) REFERENCES `orders` (`id`),
  CONSTRAINT `fk_edit_users1` FOREIGN KEY (`WhoEdit`) REFERENCES `users` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edit`
--

LOCK TABLES `edit` WRITE;
/*!40000 ALTER TABLE `edit` DISABLE KEYS */;
INSERT INTO `edit` VALUES (1,'2021-03-08 15:56:00',1),(2,'2021-03-12 16:11:00',1),(3,'2021-03-16 13:10:00',2),(4,'2021-03-16 13:21:00',3),(5,'2021-04-26 20:27:22',1),(6,'2021-05-08 22:51:44',3),(7,'2021-05-16 15:01:06',3),(8,'2021-05-16 15:01:30',3),(9,'2021-05-16 15:01:53',3),(10,'2021-05-16 15:02:12',3),(11,'2021-05-16 15:02:44',3),(12,'2021-05-16 15:04:06',3),(13,'2021-05-16 15:05:16',3),(14,'2021-05-16 15:05:40',3),(15,'2021-05-16 15:05:53',3),(16,'2021-05-16 15:06:26',3),(17,'2021-05-16 15:06:46',3),(18,'2021-05-16 15:07:01',3);
/*!40000 ALTER TABLE `edit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `functions`
--

DROP TABLE IF EXISTS `functions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `functions` (
  `id` int NOT NULL,
  `FName` tinytext NOT NULL,
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `functions`
--

LOCK TABLES `functions` WRITE;
/*!40000 ALTER TABLE `functions` DISABLE KEYS */;
INSERT INTO `functions` VALUES (1,'Инженер связи'),(2,'Монтажник'),(3,'Системный администратор'),(4,'Помощник сис.администр.'),(5,'Программист 1С'),(6,'Маркетолог'),(7,'Главный бухгалтер'),(8,'Зам. ген. директора'),(9,'Генеральный директор');
/*!40000 ALTER TABLE `functions` ENABLE KEYS */;
UNLOCK TABLES;

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

--
-- Table structure for table `priority`
--

DROP TABLE IF EXISTS `priority`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `priority` (
  `id` int NOT NULL,
  `PName` tinytext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `priority`
--

LOCK TABLES `priority` WRITE;
/*!40000 ALTER TABLE `priority` DISABLE KEYS */;
INSERT INTO `priority` VALUES (1,'Очень низкий'),(2,'Низкий'),(3,'Средний'),(4,'Высокий'),(5,'Очень высокий');
/*!40000 ALTER TABLE `priority` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `requestsource`
--

DROP TABLE IF EXISTS `requestsource`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `requestsource` (
  `id` int NOT NULL,
  `RName` tinytext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `requestsource`
--

LOCK TABLES `requestsource` WRITE;
/*!40000 ALTER TABLE `requestsource` DISABLE KEYS */;
INSERT INTO `requestsource` VALUES (1,'Direct'),(2,'E-mail'),(3,'Formcreator'),(4,'Helpdesk'),(5,'Other'),(6,'Phone'),(7,'Written');
/*!40000 ALTER TABLE `requestsource` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rights`
--

DROP TABLE IF EXISTS `rights`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `rights` (
  `Name` varchar(20) NOT NULL,
  `Edit` tinyint(1) DEFAULT NULL,
  UNIQUE KEY `Name_UNIQUE` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rights`
--

LOCK TABLES `rights` WRITE;
/*!40000 ALTER TABLE `rights` DISABLE KEYS */;
INSERT INTO `rights` VALUES ('Admin',1),('Manager',0),('SuperAdmin',1);
/*!40000 ALTER TABLE `rights` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `status`
--

DROP TABLE IF EXISTS `status`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `status` (
  `id` int NOT NULL,
  `SName` tinytext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `status`
--

LOCK TABLES `status` WRITE;
/*!40000 ALTER TABLE `status` DISABLE KEYS */;
INSERT INTO `status` VALUES (1,'Новый'),(2,'В работе (назначена)'),(3,'В работе (запланирована)'),(4,'Ожидающие'),(5,'Решена'),(6,'Закрыто');
/*!40000 ALTER TABLE `status` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `types`
--

DROP TABLE IF EXISTS `types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `types` (
  `id` int NOT NULL,
  `TName` tinytext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `types`
--

LOCK TABLES `types` WRITE;
/*!40000 ALTER TABLE `types` DISABLE KEYS */;
INSERT INTO `types` VALUES (1,'Инцендент'),(2,'Запрос');
/*!40000 ALTER TABLE `types` ENABLE KEYS */;
UNLOCK TABLES;

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
INSERT INTO `users` (`id`, `Name`, `SecName`, `Login`, `Password`, `Rights`, `Function`, `Active`, `Valid_from`, `Valid_until`, `Email`, `Phone`, `Phone_m`, `Phone2`, `Phone2_m`, `Description`) VALUES (1,'Илья','Панин','i.panin','zarkj17n','SuperAdmin',1,1,'2021-04-02 00:00:00','2021-06-20 23:59:59','pan-ov-16@mail.ru','+7-(496)-753-16-12','+7-(901)-791-80-71',NULL,NULL,'Разработчик приложения по учету заявок от клиентов'),(2,'Алексей','Панин','123','123',NULL,2,1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(3,'Наталья','Панина','321','321','Manager',6,1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(4,'робот','Почтовый','post-bot','post-bot',NULL,NULL,1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `work`
--

DROP TABLE IF EXISTS `work`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `work` (
  `id` int NOT NULL,
  `DateClose` datetime DEFAULT NULL,
  `WhoWork` int DEFAULT NULL,
  `DateDecision` datetime DEFAULT NULL,
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_work_orders1_idx` (`id`),
  KEY `fk_work_users1_idx` (`WhoWork`),
  CONSTRAINT `fk_work_orders1` FOREIGN KEY (`id`) REFERENCES `orders` (`id`),
  CONSTRAINT `fk_work_users1` FOREIGN KEY (`WhoWork`) REFERENCES `users` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `work`
--

LOCK TABLES `work` WRITE;
/*!40000 ALTER TABLE `work` DISABLE KEYS */;
INSERT INTO `work` VALUES (1,'2021-03-08 15:56:22',1,NULL),(2,'2021-03-12 16:11:00',3,NULL),(3,'2021-03-13 13:10:00',2,NULL),(4,'2021-03-13 13:21:30',3,NULL),(5,NULL,1,NULL),(6,'2021-04-26 21:39:37',1,'2021-04-26 20:59:00'),(7,NULL,NULL,NULL),(8,NULL,NULL,NULL),(9,NULL,NULL,NULL),(10,NULL,NULL,NULL),(11,NULL,NULL,NULL),(12,NULL,NULL,NULL),(13,NULL,NULL,NULL),(14,NULL,NULL,NULL),(15,NULL,NULL,NULL),(16,NULL,NULL,NULL),(17,NULL,NULL,NULL),(18,NULL,NULL,NULL);
/*!40000 ALTER TABLE `work` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-05-21 21:43:22
