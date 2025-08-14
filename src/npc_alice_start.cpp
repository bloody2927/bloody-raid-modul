/*
 * Placeholder script for NPC Alice start
 */

#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "Position.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum AliceStart
{
    NPC_ALICE        = 91001,
    ACTION_START_BOSS = GOSSIP_ACTION_INFO_DEF + 1,
    ACTION_TELEPORT   = GOSSIP_ACTION_INFO_DEF + 2,
    GOSSIP_TEXT_ID    = 91000
};

static Position const AliceSummonPos = {100.0f, 100.0f, 20.0f, 0.0f};
static Position const BossRoomPos    = {120.0f, 120.0f, 20.0f, 0.0f};

class npc_alice_start : public CreatureScript
{
public:
    npc_alice_start() : CreatureScript("npc_alice_start") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->PrepareGossipMenu(creature);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Bosskampf starten", GOSSIP_SENDER_MAIN, ACTION_START_BOSS);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport zur Bosskammer", GOSSIP_SENDER_MAIN, ACTION_TELEPORT);
        player->SendGossipMenu(GOSSIP_TEXT_ID, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
            case ACTION_START_BOSS:
            {
                if (InstanceScript* instance = creature->GetInstanceScript())
                {
                    if (Creature* alice = instance->SummonCreature(NPC_ALICE, AliceSummonPos))
                        instance->DoZoneInCombat(alice);
                }
                creature->DespawnOrUnsummon();
                break;
            }
            case ACTION_TELEPORT:
            {
                if (Map* map = creature->GetMap())
                {
                    Map::PlayerList const& players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* plr = itr->GetSource())
                            plr->TeleportTo(creature->GetMapId(), BossRoomPos.GetPositionX(), BossRoomPos.GetPositionY(), BossRoomPos.GetPositionZ(), BossRoomPos.GetOrientation());
                }
                break;
            }
        }

        return true;
    }
};

void AddSC_npc_alice_start()
{
    new npc_alice_start();
}

