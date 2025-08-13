-- Spell overrides for Smaragdsanktum
-- Adjust radius, damage and duration of custom spells
UPDATE `spell_template` SET `EffectRadiusIndex1`=15 WHERE `entry`=90000;
UPDATE `spell_template` SET `EffectBasePoints1`=600 WHERE `entry`=90001;
UPDATE `spell_template` SET `DurationIndex`=28 WHERE `entry`=90002;
