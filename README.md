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

This module adds a custom raid encounter to [AzerothCore](https://www.azerothcore.org). It targets the **master** branch of AzerothCore and does not require any core modifications.

## Requirements
* AzerothCore master branch
* CMake and a working C++17 toolchain
* A MySQL database compatible with AzerothCore

## Installation
1. Clone this repository into your AzerothCore `modules` directory:
   ```bash
   cd azerothcore-wotlk/modules
   git clone https://github.com/your-account/bloody-raid-modul.git
   ```
2. Import the SQL file into the world database:
   ```bash
   mysql -u user -p world < modules/bloody-raid-modul/data/sql/db-world/skeleton_module_acore_string.sql
   ```
3. Enable the module by copying the config file and setting the option:
   ```bash
   cp modules/bloody-raid-modul/conf/my_custom.conf.dist worldserver.conf.d/my_custom.conf
   # inside the file ensure
   MyModule.Enable = 1
   ```
4. Re-run `cmake` and compile AzerothCore.

## Encounter overview
The Bloody Raid consists of three phases:

1. **Blood Ritual** – the boss uses blood-based abilities and periodically spawns blood minions.
2. **Hemorrhage** – at 60% health the boss enters a frenzy, summoning additional waves of minions and using area attacks.
3. **Final Siphon** – below 30% health, the boss drains life from players and becomes enraged until defeated.

### Optional achievements
* **Bloodless Victory** – defeat the encounter without any player dropping below 50% health.
* **Cleanup Crew** – destroy all spawned minions before the next wave appears.

### Debug information
When `MyModule.Enable` is set, a greeting will be sent to players on login. Additional debug logs can be enabled by running the server in debug mode.

## License
This project is released under the terms of the [GNU AGPL v3](LICENSE).

