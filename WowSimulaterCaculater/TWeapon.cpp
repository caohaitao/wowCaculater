#include "stdafx.h"
#include "TWeapon.h"
#include "TWowCommon.h"


TWeapon::TWeapon(std::string name,int harm_min, int harm_max, int speed)
        :TObject(name)
        ,m_harm_min(harm_min)
        ,m_harm_max(harm_max)
        ,m_speed(speed)
        ,m_old_speed(speed)
{
}


TWeapon::~TWeapon()
{
}

void TWeapon::TimeEvent(std::list<TEvent> & events)
{
        TObject::TimeEvent(events);
        if (m_time_value > m_speed)
        {
                m_time_value = 0;
                TEvent event;
                event.m_owner = m_name;
                event.m_type = TEvent::Attack;
                event.value = RandInt(m_harm_min, m_harm_max);
                events.push_back(event);
        }
}

int TWeapon::GetSpeed()
{
        return m_speed;
}

void TWeapon::ChangeSpeed(int s)
{
        printf("%s 改变速度为 %0.4f->%0.4f\n", m_name.c_str(),
                m_speed / 10.0f, s / 10.0f);
        m_speed = s;
}

void TWeapon::RegainSpeed()
{
        printf("%s 改变速度为 %0.4f->%0.4f\n", m_name.c_str(),
                m_speed / 10.0f, m_old_speed / 10.0f);
        m_speed = m_old_speed;
}

int TWeapon::GetARandomHarm()
{
        return RandInt(m_harm_min, m_harm_max);
}

int TWeapon::GetHarmMin()
{
        return m_harm_min;
}

int TWeapon::GetHarmMax()
{
        return m_harm_max;
}
