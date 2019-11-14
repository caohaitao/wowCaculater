// ConsoleTest.cpp : 定义控制台应用程序的入口点。
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
                        printf("总体伤害 = %d\n", harm);
                }
                if (nums > 300)
                {
                        break;
                }
                Sleep(100);
        }

        printf("战斗结束，总伤害(%d),使用时间(%0.4f s)\n",people.GetHarm(), nums / 10.0);

        return 0;
}

