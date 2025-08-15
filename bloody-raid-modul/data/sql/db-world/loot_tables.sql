-- Loot tables for Smaragdsanktum boss
SET @BOSS := 90001;

DELETE FROM `creature_loot_template` WHERE `entry`=@BOSS;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@BOSS,50734,15,1,0,1,1), -- Royal Scepter of Terenas II
(@BOSS,49908,100,1,0,1,3); -- Primordial Saronite
