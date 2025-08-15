#include "emerald_sanctum.h"

class npc_emerald_keeper : public CreatureScript
{
public:
    npc_emerald_keeper() : CreatureScript("npc_emerald_keeper") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Begin the encounter.", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, 1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        CloseGossipMenuFor(player);
        if (action == 1)
            if (InstanceScript* inst = creature->GetInstanceScript())
                if (Creature* boss = ObjectAccessor::GetCreature(*creature, inst->GetGuidData(DATA_ALICE)))
                    boss->AI()->DoZoneInCombat(boss, 150.0f);
        return true;
    }
};

void AddSC_npc_emerald_keeper() { new npc_emerald_keeper(); }
