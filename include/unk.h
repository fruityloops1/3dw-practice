#pragma once

#include "al/layout.h"
#include <al/liveactor/liveactor.h>
#include <fl/efun>
#include <types>

namespace rc
{
EFUN(0x0035BD90, void, initPlayerActor, EFUN_ARGS(al::LiveActor *playerActor, void* param_2,undefined4 param_3, const char *playerName,
                        undefined8 param_5,undefined *param_6, void* param_7,undefined8 param_8
                        ,undefined4 param_9,undefined4 param_10,int param_11,undefined4 param_12,
                        char *param_13));
}