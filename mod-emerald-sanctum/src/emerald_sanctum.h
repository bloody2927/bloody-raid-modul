#pragma once

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

constexpr uint32 MAP_RUBY_SANCTUM = 724; // wir referenzieren RS-Map serverseitig

// Encounter / Data
enum ESData
{
    DATA_ALICE      = 1,
    DATA_ALICE_DOOR = 2,
};

// GameObjects
enum ESGameObjects
{
    GO_ALICE_DOOR = 400001, // SQL 06 legt das Template+Spawn an
};

// Creatures
enum ESCreatures
{
    NPC_ALICE          = 900001, // Boss
    NPC_EMERALD_KEEPER = 900010, // Start-NPC (Gossip)
};

// Spells (einige direkt fix, Rest TODO => 0 ist erlaubt; Casts sind guardet)
enum ESSpells
{
    SPELL_ICY_GRIP        = 70117, // funktional
    SPELL_BLISTERING_COLD = 70123, // funktional
    SPELL_BERSERK         = 26662, // funktional

    SPELL_VOLATILE_OOZE_ADH = 0,   // TODO
    SPELL_SLIME_PUDDLE      = 0,   // TODO
    SPELL_SLIME_SPRAY       = 0,   // TODO
    SPELL_MUTATED_INFECTION = 0,   // TODO
    SPELL_METEOR_STRIKE     = 0,   // optional
    SPELL_SLEEP             = 0,   // optional
};

// Boss-Events
enum ESEvents
{
    EVENT_NONE,
    EVENT_ICY_GRIP,
    EVENT_COLD,
    EVENT_SLIME_ROOT,
    EVENT_METEOR,
    EVENT_BERSERK,
};
