-- Beispiel-Positionen (bitte auf eure Kammer anpassen)
DELETE FROM creature WHERE id IN (900010, 900001) AND map = 724;

INSERT INTO creature (id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, spawntimesecs)
VALUES
(900010, 724, 1, 1, 4600.0, 285.0, 50.0, 3.14, 120), -- Start-NPC
(900001, 724, 1, 1, 4545.0, 284.0, 50.5, 3.14, 300); -- Boss
