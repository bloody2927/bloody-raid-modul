-- NPC and Boss templates for Smaragdsanktum
SET @START_NPC := 90000;
SET @BOSS := 90001;

-- Creature templates
DELETE FROM `creature_template` WHERE `entry` IN (@START_NPC, @BOSS);
INSERT INTO `creature_template` (`entry`,`name`,`subname`,`minlevel`,`maxlevel`,`modelid1`,`faction`,`npcflag`,`scale`,`rank`,`type`,`type_flags`,`InhabitType`,`unit_class`) VALUES
(@START_NPC,'Alice','Guide to the Smaragdsanktum',80,80,31000,35,1,1,0,7,0,3,1),
(@BOSS,'The Emerald Matron','',83,83,31001,14,0,1,3,7,0,3,1);

-- Creature models
DELETE FROM `creature_model_info` WHERE `modelid` IN (31000,31001);
INSERT INTO `creature_model_info` (`modelid`,`bounding_radius`,`combat_reach`,`gender`) VALUES
(31000,0.3519,1.5,1),
(31001,1.5,4.0,2);
