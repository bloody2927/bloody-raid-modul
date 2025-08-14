#include "ScriptMgr.h"

// Forward declare AddSC functions from script files
void AddSC_boss_alice();
void AddSC_instance_smaragdsanktum();
void AddSC_npc_alice_start();

// Add all scripts
codex/remove-stray-strings-and-duplicate-includes
void Addmod_bloody_raid_modulScripts()

void AddAliceScripts()
master
{
    AddSC_boss_alice();
    AddSC_instance_smaragdsanktum();
    AddSC_npc_alice_start();
codex/refactor-loader-functions-and-scripts
}

// Add all
// cf. the naming convention
// https://github.com/azerothcore/azerothcore-wotlk/blob/master/doc/changelog/master.md#how-to-upgrade
// additionally replace all '-' in the module folder name with '_' here
void Addmod_bloody_raid_modulScripts()
{
    Addbloody_raid_modulScripts();
}

codex/remove-stray-strings-and-duplicate-includes

}

// Called by the core to add the module's scripts
void Addmod_bloody_raid_modulScripts()
{
    AddAliceScripts();
master
}

master
