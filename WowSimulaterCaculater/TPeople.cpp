#include "stdafx.h"
#include "TPeople.h"


TPeople::TPeople()
        :m_right_weapon(0)
        ,m_left_weapon(0)
        , m_harm(0)
        , m_ap(0)
        , m_left_weapon_rate(0.5)
        ,m_star(0)
{
}


TPeople::~TPeople()
{
}

void TPeople::Run()
{

        if (!HasState("SpeedAdd"))
        {
                //if (m_star == 1)
                //{
                        if (m_energy.GetValue() >= 25)
                        {
                                if (m_star > 0)
                                {
                                        int t = (6 + m_star * 3) * 10;
                                        printf("产生切割状态,使用星数(%d),持续时间(%d s)\n", m_star, t / 10);
                                        TState_qiege * state = new TState_qiege(t);
                                        m_states.push_back(state);
                                        m_energy.UseValue(25);
                                        m_star = 0;
                                }
                        }
                //}
        }
        if (m_energy.GetValue() >= 45)
        {
                int harm = m_right_weapon->GetARandomHarm() + 3;
                m_harm += harm;
                m_energy.UseValue(45);
                m_star++;
                printf("邪恶攻击(%d),当前星数(%d)\n", harm,m_star);
        }

        //if (m_star == 5 && m_energy>=)

        if (m_right_weapon)
        {
                m_right_weapon->TimeEvent(m_events);
        }
        if (m_left_weapon)
        {
                m_left_weapon->TimeEvent(m_events);
        }
        std::list<TState*>::iterator it = m_states.begin();
        for (it; it != m_states.end();)
        {
                (*it)->TimeEvent(m_events);
                if ((*it)->IsOver())
                {
                        delete *it;
                        it = m_states.erase(it);
                }
                else {
                        it++;
                }
        }

        std::list<TEvent>::iterator eve_it = m_events.begin();
        for (eve_it; eve_it != m_events.end();)
        {
                if (eve_it->m_type == TEvent::Attack)
                {
                        if (eve_it->m_owner == "LeftWeapon")
                        {
                                float attach_harm = m_ap / 14.0f*m_left_weapon->GetSpeed()/10.0;
                                int whole_harm = round( (attach_harm + eve_it->value)*m_left_weapon_rate);
                                m_harm += whole_harm;
                                printf("副手伤害:%d\n", whole_harm);
                        }
                        else if (eve_it->m_owner == "RightWeapon")
                        {
                                float attach_harm = m_ap / 14.0f*m_left_weapon->GetSpeed() / 10.0;
                                int whole_harm = round(attach_harm + eve_it->value);
                                m_harm += whole_harm;
                                printf("主手伤害:%d\n", whole_harm);
                        }
                        eve_it = m_events.erase(eve_it);
                }
                else if (eve_it->m_type == TEvent::SpeedAdd)
                {
                        printf("切割开始\n");
                        if (m_left_weapon)
                        {
                                int lspeed = m_left_weapon->GetSpeed();
                                int lnew_speed = round(lspeed*0.8);
                                m_left_weapon->ChangeSpeed(lnew_speed);
                        }

                        if (m_right_weapon)
                        {
                                int rspeed = m_right_weapon->GetSpeed();
                                int rnew_speed = round(rspeed*0.8);
                                m_right_weapon->ChangeSpeed(rnew_speed);
                        }
                        eve_it = m_events.erase(eve_it);
                }
                else if (eve_it->m_type == TEvent::SpeedOver)
                {
                        printf("切割结束\n");
                        if (m_left_weapon)
                        {
                                m_left_weapon->RegainSpeed();
                        }
                        if (m_right_weapon)
                        {
                                m_right_weapon->RegainSpeed();
                        }
                        eve_it = m_events.erase(eve_it);
                }
                else {
                        eve_it++;
                }
        }
        m_energy.TimeEvent(m_events);
}

void TPeople::AddRightWeapon(TWeapon * weapon)
{
        m_right_weapon = weapon;
}

void TPeople::AddLeftWeapon(TWeapon * weapon)
{
        m_left_weapon = weapon;
}

int TPeople::GetHarm()
{
        return m_harm;
}

void TPeople::SetAp(int ap)
{
        m_ap = ap;
}

bool TPeople::HasState(std::string name)
{
        std::list<TState*>::iterator it = m_states.begin();
        for (it; it != m_states.end(); it++)
        {
                if ((*it)->GetName() == name)
                {
                        return true;
                }
        }
        return false;
}

void TPeople::PropertyPrint()
{
        printf("属性通报:\n");
        printf("攻击强度%d\n", m_ap);
        printf("主手武器 伤害(%d-%d) 速度(%0.2f s)\n",
                m_right_weapon->GetHarmMin(),
                m_right_weapon->GetHarmMax(),
                m_right_weapon->GetSpeed() / 10.0f);

        printf("副手武器 伤害(%d-%d) 速度(%0.2f s)\n",
                m_left_weapon->GetHarmMin(),
                m_left_weapon->GetHarmMax(),
                m_left_weapon->GetSpeed() / 10.0f);
}
