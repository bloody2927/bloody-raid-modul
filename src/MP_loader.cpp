/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU
 * AGPL v3 license:
 * https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

codex/modify-cmakelists.txt-for-new-scripts
// Forward declare AddSC functions from script files

// From SC
master
void AddSC_boss_alice();
void AddSC_instance_smaragdsanktum();
void AddSC_npc_alice_start();

codex/modify-cmakelists.txt-for-new-scripts
// Add all scripts
void Addbloody_raid_modulScripts()
{
    AddSC_boss_alice();
    AddSC_instance_smaragdsanktum();
    AddSC_npc_alice_start();

void AddAliceScripts() {
  AddSC_boss_alice();
  AddSC_instance_smaragdsanktum();
  AddSC_npc_alice_start();
master
}

// Add all
// cf. the naming convention
// https://github.com/azerothcore/azerothcore-wotlk/blob/master/doc/changelog/master.md#how-to-upgrade
// additionally replace all '-' in the module folder name with '_' here
void Addmod_bloody_raid_modulScripts() { AddAliceScripts(); }
