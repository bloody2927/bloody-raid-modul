#ifndef ALICE_H
#define ALICE_H

// NPC identifiers for the Alice encounter
enum AliceNPCs
{
    NPC_ALICE            = 90000,
    NPC_ALICE_MINION     = 90001,
    NPC_ALICE_HELPER     = 90002
};

// GameObject identifiers associated with Alice
enum AliceGameObjects
{
    GO_ALICE_GATE        = 190000,
    GO_ALICE_TREASURE    = 190001
};

// Spell identifiers used by Alice and her minions
enum AliceSpells
{
    SPELL_METEOR_STRIKE  = 300000,
    SPELL_SHADOW_BOLT    = 300001,
    SPELL_ARCANE_BLAST   = 300002
};

// Phases of the Alice boss encounter
enum AlicePhases
{
    PHASE_INTRO          = 1,
    PHASE_COMBAT         = 2,
    PHASE_FINAL          = 3
};

// Optional achievements related to Alice encounter
enum AliceAchievements
{
    ACHIEVEMENT_FAST_KILL = 400000,
    ACHIEVEMENT_NO_DEATHS = 400001
};

#endif // ALICE_H
