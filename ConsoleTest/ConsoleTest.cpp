// ConsoleTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TEnergy.h"
#include "Windows.h"
#include "time.h"
#include "TPeople.h"

int main()
{
        TPeople people;
        TWeapon right_weapon("RightWeapon", 50, 70, 24);
        TWeapon left_weapon("LeftWeapon", 30, 50, 15);
        people.AddRightWeapon(&right_weapon);
        people.AddLeftWeapon(&left_weapon);
        people.SetAp(100);
        people.PropertyPrint();
        int nums = 0;
        while (1)
        {
                people.Run();
                int harm = people.GetHarm();
                //if (harm > 1000)
                //{
                //        break;
                //}
                nums++;
                if (nums%10 == 0)
                {
                        printf("�����˺� = %d\n", harm);
                }
                if (nums > 300)
                {
                        break;
                }
                Sleep(100);
        }

        printf("ս�����������˺�(%d),ʹ��ʱ��(%0.4f s)\n",people.GetHarm(), nums / 10.0);

        return 0;
}

