-- Tür-Template + Spawn (Tür öffnet bei Boss=DONE)
REPLACE INTO gameobject_template
(entry, type, displayId, name, size, data0, data1, data2, data3, data4, data5, data6, ScriptName)
VALUES
(400001, 0, 6951, 'Emerald Sanctum - Alice Door', 1, 0,0,0,0,0,0,0, '');

DELETE FROM gameobject WHERE id = 400001 AND map = 724;
INSERT INTO gameobject (id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, spawntimesecs)
VALUES (400001, 724, 1, 1, 4540.0, 284.0, 50.5, 3.14, 300);
