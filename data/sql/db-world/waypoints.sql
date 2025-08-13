-- Waypoints for Smaragdsanktum creatures
SET @BOSS_PATH := 900001;

DELETE FROM `waypoint_data` WHERE `id`=@BOSS_PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@BOSS_PATH,1,0,0,0,0,0,0,100,0),
(@BOSS_PATH,2,10,0,0,0,0,0,100,0);
