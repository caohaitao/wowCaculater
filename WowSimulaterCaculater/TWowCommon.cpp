#include "stdafx.h"
#include "TWowCommon.h"
#include <stdlib.h>

int RandInt(int from, int to)
{
        int sub = to - from;
        int v = rand() % sub;
        return v + from;
}
