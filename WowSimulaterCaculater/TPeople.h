#pragma once
#include "TObject.h"
#include "TWeapon.h"
#include "TState.h"
#include "list"
#include "TEvent.h"
#include "TEnergy.h"

class TPeople
{
public:
        TPeople();
        ~TPeople();
        void Run();
        void AddRightWeapon(TWeapon * weapon);
        void AddLeftWeapon(TWeapon * weapon);
        int GetHarm();
        void SetAp(int ap);

        bool HasState(std::string name);

        void PropertyPrint();
protected:
        TEnergy m_energy;
        int m_star;
        TWeapon * m_right_weapon;
        TWeapon * m_left_weapon;
        std::list<TEvent> m_events;
        std::list<TState*> m_states;
        float m_hit_rate;
        float m_boom_rate;
        float m_left_weapon_rate;
        int m_ap;

        int m_harm;
};

