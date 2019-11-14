#include "stdafx.h"
#include "TEnergy.h"
#include "windows.h"

TEnergy::TEnergy()
        :TObject("energy")
        ,m_value(100)
{
}


TEnergy::~TEnergy()
{
}

int TEnergy::GetValue()
{
        return m_value;
}

void TEnergy::UseValue(int v)
{
        
        m_value -= v;
        if (m_value < 0)
        {
                m_value = 0;
        }
        printf("使用能量(%d),当前能量(%d)\n", v, m_value);
}


void TEnergy::AddValue()
{
        m_value += 20;
        if (m_value > 100)
        {
                m_value = 100;
        }
        printf("恢复能量，当前能量为%d\n", m_value);
}

void TEnergy::TimeEvent(std::list<TEvent> & events)
{
        TObject::TimeEvent(events);
        if (m_time_value == 20)
        {
                this->AddValue();
                m_time_value = 0;
        }
}
