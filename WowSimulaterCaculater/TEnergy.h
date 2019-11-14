#pragma once
#include "TObject.h"
class TEnergy:public TObject
{
public:
        TEnergy();
        ~TEnergy();

        int GetValue();
        void UseValue(int v);
        void AddValue();
        virtual void TimeEvent(std::list<TEvent> & events) override;
protected:
        int m_value;
};

