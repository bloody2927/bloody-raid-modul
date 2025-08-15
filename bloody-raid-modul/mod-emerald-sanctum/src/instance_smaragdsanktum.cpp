#include "emerald_sanctum.h"

class instance_smaragdsanktumt : public InstanceMapScript
{
public:
    instance_smaragdsanktumt() : InstanceMapScript("instance_smaragdsanktum", MAP_RUBY_SANCTUM) { }

    struct instance_smaragdsanktum_Instance : public InstanceScript
    {
        instance_smaragdsanktum_Instance(Map* map) : InstanceScript(map) { SetBossNumber(1); }

        ObjectGuid aliceGUID;
        ObjectGuid doorGUID;

        void Initialize() override
        {
            SetBossState(DATA_ALICE, NOT_STARTED);
            aliceGUID.Clear();
            doorGUID.Clear();
        }

        void OnCreatureCreate(Creature* c) override
        {
            if (c->GetEntry() == NPC_ALICE)
                aliceGUID = c->GetGUID();
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            if (go->GetEntry() == GO_ALICE_DOOR)
            {
                doorGUID = go->GetGUID();
                if (GetBossState(DATA_ALICE) == DONE)
                    HandleGameObject(doorGUID, true);
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_ALICE)
            {
                SetBossState(DATA_ALICE, EncounterState(data));
                if (data == DONE)
                    HandleGameObject(doorGUID, true);
            }
        }

        uint32 GetData(uint32 type) const override
        {
            return (type == DATA_ALICE) ? GetBossState(DATA_ALICE) : 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            return (type == DATA_ALICE) ? aliceGUID : ObjectGuid::Empty;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_smaragdsanktum_Instance(map);
    }
};

void AddSC_instance_smaragdsanktum() { new instance_smaragdsanktumt(); }
