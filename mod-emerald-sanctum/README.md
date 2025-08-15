# Emerald Sanctum (Alice) – AzerothCore Module

- Verwendet **Map 724 (Ruby Sanctum)** serverseitig als Geometrie.
- Keine Client-Patches nötig; alle Spawns/Objekte kommen aus `sql/world`.
- InstanceScript: `instance_smaragdsanktum` (setzt Boss-State & Tür).

## Einbindung in AzerothCore (später bei dir lokal)
1. Modul in `azerothcore-wotlk/modules/mod-emerald-sanctum/` legen.
2. AC wie üblich bauen:


mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j

3. SQLs importieren: `sql/world/01..06`.
4. Map 724 betreten → Start-NPC → Boss starten.

## Hinweis zu Spell-IDs
Einige Spell-Konstanten sind Platzhalter (`0`). Das Modul baut trotzdem.
Später in `src/emerald_sanctum.h` die TODO-IDs ersetzen (aus eurer DB).
