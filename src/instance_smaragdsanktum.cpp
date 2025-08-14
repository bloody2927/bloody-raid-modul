/*
 * Instance script for Smaragdsanktum
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "alice.h"

#include <array>

namespace
{
// Map identifier taken from the database script
constexpr uint32 SMARAGDSANKTUM_MAP_ID = 930;

// Encounter data identifiers. Keep DATA_UNUSED to preserve indexing in
// existing boss scripts that start at 1.
enum EncounterData
{
    DATA_UNUSED,
    DATA_ALICE,
    DATA_MAX_ENCOUNTER
};
}

class instance_smaragdsanktum : public InstanceMapScript
{
public:
    instance_smaragdsanktum() : InstanceMapScript("instance_smaragdsanktum", SMARAGDSANKTUM_MAP_ID) { }

    struct instance_smaragdsanktum_InstanceMap : public InstanceScript
    {
        instance_smaragdsanktum_InstanceMap(Map* map) : InstanceScript(map)
        {
            Initialize();
        }

        void Initialize() override
        {
            SetBossNumber(DATA_MAX_ENCOUNTER);

            _bossGuids.fill(ObjectGuid::Empty);
            _doorGuids.fill(ObjectGuid::Empty);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ALICE:
                    _bossGuids[DATA_ALICE] = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_ALICE_GATE:
                    _doorGuids[DATA_ALICE] = go->GetGUID();

                    if (GetBossState(DATA_ALICE) == DONE)
                        HandleGameObject(go->GetGUID(), true);
                    break;
            }
        }

        std::array<ObjectGuid, DATA_MAX_ENCOUNTER> _bossGuids{};
        std::array<ObjectGuid, DATA_MAX_ENCOUNTER> _doorGuids{};
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_smaragdsanktum_InstanceMap(map);
    }
};

void AddSC_instance_smaragdsanktum()
{
    new instance_smaragdsanktum();
}

