#include "emerald_sanctum.h"
#include "SpellAuraEffects.h"
#include "ObjectAccessor.h"

class boss_alice_the_dreammother : public CreatureScript
{
public:
    boss_alice_the_dreammother() : CreatureScript("boss_alice_the_dreammother") { }

    struct boss_alice_the_dreammotherAI : public BossAI
    {
        boss_alice_the_dreammotherAI(Creature* c) : BossAI(c, DATA_ALICE) { }

        void Reset() override
        {
            _Reset();
            events.Reset();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            events.ScheduleEvent(EVENT_ICY_GRIP, 10s);
            events.ScheduleEvent(EVENT_COLD, 20s);
            events.ScheduleEvent(EVENT_SLIME_ROOT, 25s);
            events.ScheduleEvent(EVENT_BERSERK, 10min);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            if (InstanceScript* inst = me->GetInstanceScript())
                inst->SetData(DATA_ALICE, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_ICY_GRIP:
                    if (SPELL_ICY_GRIP) DoCastAOE(SPELL_ICY_GRIP, true);
                    events.ScheduleEvent(EVENT_ICY_GRIP, 45s);
                    break;

                case EVENT_COLD:
                    if (SPELL_BLISTERING_COLD) DoCast(me, SPELL_BLISTERING_COLD, false);
                    events.ScheduleEvent(EVENT_COLD, 30s);
                    break;

                case EVENT_SLIME_ROOT:
                    if (Unit* t = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                    {
                        if (SPELL_VOLATILE_OOZE_ADH) DoCast(t, SPELL_VOLATILE_OOZE_ADH, false);
                        if (SPELL_SLIME_PUDDLE)      DoCast(t, SPELL_SLIME_PUDDLE, true);
                        if (SPELL_SLIME_SPRAY)       DoCast(t, SPELL_SLIME_SPRAY, false);
                        if (SPELL_MUTATED_INFECTION) DoCast(t, SPELL_MUTATED_INFECTION, false);
                    }
                    events.ScheduleEvent(EVENT_SLIME_ROOT, 60s);
                    break;

                case EVENT_METEOR:
                    if (Unit* t2 = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        if (SPELL_METEOR_STRIKE) DoCast(t2, SPELL_METEOR_STRIKE, false);
                    events.ScheduleEvent(EVENT_METEOR, 35s);
                    break;

                case EVENT_BERSERK:
                    if (SPELL_BERSERK) DoCast(me, SPELL_BERSERK, true);
                    break;

                default: break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* c) const override { return new boss_alice_the_dreammotherAI(c); }
};

void AddSC_boss_alice_the_dreammother() { new boss_alice_the_dreammother(); }
