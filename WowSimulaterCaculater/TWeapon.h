#pragma once
#include "TObject.h"

class TWeapon:public TObject
{
public:
        TWeapon(std::string name, int harm_min,int harm_max,int speed);
        virtual ~TWeapon();

        virtual void TimeEvent(std::list<TEvent> & events) override;

        int GetSpeed();

        void ChangeSpeed(int s);

        void RegainSpeed();

        int GetARandomHarm();

        int GetHarmMin();

        int GetHarmMax();
protected:
        int m_harm_min;
        int m_harm_max;
        int m_speed;

        int m_old_speed;
};

