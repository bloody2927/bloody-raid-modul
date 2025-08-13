codex/modify-cmakelists.txt-for-new-scripts
/*
 * Placeholder script for boss Alice encounter
 */

#include "ScriptMgr.h"

void AddSC_boss_alice()
{

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Data
{
    DATA_ALICE = 1
};

enum Spells
{
    SPELL_METEOR_STRIKE = 70000,
    SPELL_ICY_GRIP      = 70001,
    SPELL_SLIME_ROOT    = 70002,
    SPELL_BERSERK       = 70003,
    SPELL_AOE_DAMAGE    = 70004,
    SPELL_GAS_BOMB      = 70005,
    SPELL_SUMMON_SLIME  = 70006
};

enum Events
{
    EVENT_METEOR_STRIKE = 1,
    EVENT_ICY_GRIP,
    EVENT_SLIME_ROOT,
    EVENT_AOE_DAMAGE,
    EVENT_GAS_BOMB,
    EVENT_SUMMON_SLIME,
    EVENT_BERSERK,
    EVENT_PHASE_TWO,
    EVENT_PHASE_THREE
};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_THREE = 4
};

struct boss_alice : public BossAI
{
    boss_alice(Creature* creature) : BossAI(creature, DATA_ALICE) { }

    void Reset() override
    {
        _Reset();
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_METEOR_STRIKE, 5000, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_ICY_GRIP, 15000, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_AOE_DAMAGE, 10000, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SLIME_ROOT, 20000, 0, PHASE_ONE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(70, damage) && events.GetPhaseMask() == PHASE_ONE)
            events.ScheduleEvent(EVENT_PHASE_TWO, 0, 0, PHASE_ONE);
        else if (me->HealthBelowPctDamaged(40, damage) && events.GetPhaseMask() == PHASE_TWO)
            events.ScheduleEvent(EVENT_PHASE_THREE, 0, 0, PHASE_TWO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_METEOR_STRIKE:
                    DoCastVictim(SPELL_METEOR_STRIKE);
                    events.ScheduleEvent(EVENT_METEOR_STRIKE, 15000, 0, events.GetPhaseMask());
                    break;
                case EVENT_ICY_GRIP:
                    DoCastAOE(SPELL_ICY_GRIP);
                    events.ScheduleEvent(EVENT_ICY_GRIP, 30000, 0, events.GetPhaseMask());
                    break;
                case EVENT_SLIME_ROOT:
                    DoCastAOE(SPELL_SLIME_ROOT);
                    events.ScheduleEvent(EVENT_SLIME_ROOT, 45000, 0, PHASE_ONE);
                    break;
                case EVENT_AOE_DAMAGE:
                    DoCastAOE(SPELL_AOE_DAMAGE);
                    events.ScheduleEvent(EVENT_AOE_DAMAGE, 20000, 0, events.GetPhaseMask());
                    break;
                case EVENT_GAS_BOMB:
                    DoCastAOE(SPELL_GAS_BOMB);
                    events.ScheduleEvent(EVENT_GAS_BOMB, 20000, 0, events.GetPhaseMask());
                    break;
                case EVENT_SUMMON_SLIME:
                    DoCast(SPELL_SUMMON_SLIME);
                    events.ScheduleEvent(EVENT_SUMMON_SLIME, 25000, 0, events.GetPhaseMask());
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    break;
                case EVENT_PHASE_TWO:
                    events.SetPhase(PHASE_TWO);
                    events.ScheduleEvent(EVENT_AOE_DAMAGE, 10000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_GAS_BOMB, 15000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SUMMON_SLIME, 20000, 0, PHASE_TWO);
                    break;
                case EVENT_PHASE_THREE:
                    events.SetPhase(PHASE_THREE);
                    events.ScheduleEvent(EVENT_BERSERK, 1000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_METEOR_STRIKE, 5000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_ICY_GRIP, 15000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_GAS_BOMB, 20000, 0, PHASE_THREE);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_alice()
{
    RegisterCreatureAI(boss_alice);
master
}

