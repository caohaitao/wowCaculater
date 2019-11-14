#pragma once
#include "TObject.h"
class TState :public TObject
{
public:
        TState(std::string name,int state_time);
        virtual ~TState();
        bool IsOver();
        virtual void TimeEvent(std::list<TEvent> & events) override;
protected:
        bool m_is_over;
        int m_state_time;
};


class TState_qiege :public TState
{
public:
        TState_qiege(int state_time);
        virtual void TimeEvent(std::list<TEvent> & events) override;
};

