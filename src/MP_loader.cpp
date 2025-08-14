/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU
 * AGPL v3 license:
 * https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

// Forward declare AddSC functions from script files
void AddSC_boss_alice();
void AddSC_instance_smaragdsanktum();
void AddSC_npc_alice_start();

// Add all scripts
void AddAliceScripts()
{
    AddSC_boss_alice();
    AddSC_instance_smaragdsanktum();
    AddSC_npc_alice_start();
}

// Called by the core to add the module's scripts
void Addmod_bloody_raid_modulScripts()
{
    AddAliceScripts();
}

