#pragma once
#include "string"
class TEvent
{
public:
        TEvent();
        ~TEvent();

        enum EnvenType
        {
                SpeedAdd,
                SpeedOver,
                Attack
        };

        EnvenType m_type;
        int value;
        std::string m_owner;
};

