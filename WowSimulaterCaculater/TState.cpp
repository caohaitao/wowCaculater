#include "stdafx.h"
#include "TState.h"

TState::TState(std::string name, int state_time)
        :TObject(name)
        ,m_is_over(false)
        ,m_state_time(state_time)
{

}

TState::~TState()
{

}

bool TState::IsOver()
{
        return m_is_over;
}

void TState::TimeEvent(std::list<TEvent> & events)
{
        TObject::TimeEvent(events);
        if (m_time_value > m_state_time)
        {
                m_is_over = true;
        }
}

TState_qiege::TState_qiege(int state_time)
        :TState("SpeedAdd",state_time)
{

}

void TState_qiege::TimeEvent(std::list<TEvent> & events)
{
        TState::TimeEvent(events);
        if (m_time_value == 1)
        {
                TEvent eve;
                eve.m_type = TEvent::SpeedAdd;
                eve.value = 20;
                eve.m_owner = m_name;
                events.push_back(eve);
        }
        else if (m_is_over)
        {
                TEvent eve;
                eve.m_type = TEvent::SpeedOver;
                eve.m_owner = m_name;
                events.push_back(eve);
        }
}
