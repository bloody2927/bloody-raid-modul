SET @NPC := 91000;
SET @GOSSIP_MENU := 91000;
SET @GOSSIP_TEXT := 91000;

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP_MENU;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (@GOSSIP_MENU, @GOSSIP_TEXT);

DELETE FROM `npc_text` WHERE `ID`=@GOSSIP_TEXT;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@GOSSIP_TEXT, 'Seid ihr bereit den Kampf zu beginnen?');

UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP_MENU, `npcflag`=`npcflag`|1, `ScriptName`='npc_alice_start' WHERE `entry`=@NPC;
