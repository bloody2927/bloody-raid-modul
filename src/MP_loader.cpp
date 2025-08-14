#include "ScriptMgr.h"

// Forward declare AddSC functions from script files
void AddSC_boss_alice();
void AddSC_instance_smaragdsanktum();
void AddSC_npc_alice_start();

// Add all scripts
void Addmod_bloody_raid_modulScripts()
{
    AddSC_boss_alice();
    AddSC_instance_smaragdsanktum();
    AddSC_npc_alice_start();
}

