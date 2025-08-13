-- Map and instance template for Smaragdsanktum
SET @MAPID := 930;
SET @BOSS := 90001;

-- Map registration
DELETE FROM `map` WHERE `entry`=@MAPID;
INSERT INTO `map` (`entry`,`name`,`directory`,`map_type`,`expansion`) VALUES (@MAPID,'Smaragdsanktum','Smaragdsanktum',1,2);

-- Instance template
DELETE FROM `instance_template` WHERE `map`=@MAPID;
INSERT INTO `instance_template` (`map`,`parent`,`script`,`allowMount`,`insideResurrection`) VALUES
(@MAPID,0,'instance_smaragdsanktum',0,1);

-- Encounter data
DELETE FROM `instance_encounters` WHERE `entry`=@BOSS;
INSERT INTO `instance_encounters` (`entry`,`map`,`difficulty`,`name`,`data`) VALUES
(@BOSS,@MAPID,0,'The Emerald Matron',@BOSS);
