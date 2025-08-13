# Bloody Raid Module

This module adds the Smaragdsanktum raid with custom NPCs, instance data, waypoints, spell tweaks and loot tables.

## Importing the SQL files

Import the SQL files under `data/sql/db-world` into your AzerothCore world database in the order below:

1. `npc_alice.sql` – registers the starter NPC and boss creature templates.
2. `instance_smaragdsanktum.sql` – registers the map, instance template and encounter data.
3. `waypoints.sql` – defines movement paths for the encounter.
4. `spells_override.sql` – applies custom spell radius, damage and duration tweaks.
5. `loot_tables.sql` – adds boss loot entries.

Example commands:

```
mysql -u <user> -p world < data/sql/db-world/npc_alice.sql
mysql -u <user> -p world < data/sql/db-world/instance_smaragdsanktum.sql
mysql -u <user> -p world < data/sql/db-world/waypoints.sql
mysql -u <user> -p world < data/sql/db-world/spells_override.sql
mysql -u <user> -p world < data/sql/db-world/loot_tables.sql
```

Replace `world` with the name of your world database.
