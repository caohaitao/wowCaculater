#pragma once
#include "string"
#include "TEvent.h"
#include "list"
class TObject
{
public:
        TObject(std::string name);
        ~TObject();
        virtual void TimeEvent(std::list<TEvent> & events);

        std::string GetName();
protected:
        int m_time_value;
        std::string m_name;
};

