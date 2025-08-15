#include "ScriptMgr.h"

// Vorwärtsdeklarationen deiner AddSC_*-Funktionen
void AddSC_boss_alice_the_dreammother();
void AddSC_npc_emerald_keeper();
void AddSC_instance_smaragdsanktum();

// Diese Funktion wird vom Modul-Loader des Cores gesucht.
// Name = "Add" + <Ordnername mit '-' -> '_'> + "Scripts"
void Addbloody_raid_modulScripts()
{
    // Hier alle Skript-Registrierer aufrufen:
    AddSC_boss_alice_the_dreammother();
    AddSC_npc_emerald_keeper();
    AddSC_instance_smaragdsanktum();
}
