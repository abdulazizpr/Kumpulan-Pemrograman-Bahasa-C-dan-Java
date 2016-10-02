/*
Navicat MySQL Data Transfer

Source Server         : aziz
Source Server Version : 100110
Source Host           : localhost:3306
Source Database       : tmd

Target Server Type    : MYSQL
Target Server Version : 100110
File Encoding         : 65001

Date: 2016-06-02 05:01:59
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `energy` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('13', 'aziz', '1220');
INSERT INTO `user` VALUES ('14', 'dita', '190');
INSERT INTO `user` VALUES ('15', 'dit', '250');
INSERT INTO `user` VALUES ('16', 'tes', '950');
INSERT INTO `user` VALUES ('17', 'maziz', '200');
INSERT INTO `user` VALUES ('18', 'bedul', '310');
INSERT INTO `user` VALUES ('19', 'a', '380');
INSERT INTO `user` VALUES ('20', 'nana', '140');
INSERT INTO `user` VALUES ('21', 'tt', '160');
INSERT INTO `user` VALUES ('22', 'regg', '0');
INSERT INTO `user` VALUES ('23', 'hh', '10');
INSERT INTO `user` VALUES ('24', 'ie', '100');
INSERT INTO `user` VALUES ('25', 'nano', '230');
