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
        printf("ʹ������(%d),��ǰ����(%d)\n", v, m_value);
}


void TEnergy::AddValue()
{
        m_value += 20;
        if (m_value > 100)
        {
                m_value = 100;
        }
        printf("�ָ���������ǰ����Ϊ%d\n", m_value);
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
