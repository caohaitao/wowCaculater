#include "stdafx.h"
#include "TObject.h"


TObject::TObject(std::string name)
        :m_name(name)
        ,m_time_value(0)
{
}


TObject::~TObject()
{
}

void TObject::TimeEvent(std::list<TEvent> & events)
{
        m_time_value++;
}

std::string TObject::GetName()
{
        return m_name;
}
