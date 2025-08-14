DELETE FROM creature_text WHERE entry IN (900001);
INSERT INTO creature_text (entry, groupid, id, text, type, language, probability, emote, duration, sound, comment) VALUES
(900001, 0, 0, 'You dare trespass the Emerald sanctum?', 14, 0, 100, 0, 0, 0, 'Alice - Aggro'),
(900001, 1, 0, 'Dreams turn to nightmares!',             14, 0, 100, 0, 0, 0, 'Alice - Phase'),
(900001, 2, 0, 'The dream… persists…',                   14, 0, 100, 0, 0, 0, 'Alice - Death');
