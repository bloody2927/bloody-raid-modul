-- Creature and gameobject spawns for Smaragdsanktum
SET @CGUID := 9100000;
SET @OGUID := 9100000;

REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`equipment_id`,
`position_x`,`position_y`,`position_z`,`orientation`,
`spawntimesecsmin`,`spawntimesecsmax`,`spawndist`,`MovementType`) VALUES
(@CGUID+0,90000,571,1,1,0,5806.72,482.03,658.47,1.22,300,300,0,0), -- Alice start NPC in Dalaran
(@CGUID+1,90001,930,1,1,0,125.39,-210.51,35.71,3.14,86400,86400,0,0); -- The Emerald Matron

REPLACE INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,
`position_x`,`position_y`,`position_z`,`orientation`,
`rotation0`,`rotation1`,`rotation2`,`rotation3`,
`spawntimesecsmin`,`spawntimesecsmax`,`animprogress`,`state`) VALUES
(@OGUID+0,181011,930,1,1,130.23,-207.87,35.73,0.0,0,0,0,1,0,0,100,1); -- Portal to entrance
