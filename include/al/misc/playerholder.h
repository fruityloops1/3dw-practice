#pragma once

#include "al/liveactor/liveactor.h"
#include <fl/efun>

namespace al
{

class PlayerHolder
{
public:
    CEFUN(PlayerHolder, 0x008875A0, al::LiveActor*, tryGetPlayer, EFUN_ARGS(int index), EFUN_ARGS(index));
    CVEFUN(PlayerHolder, 0x008161C0, int, getPlayerNum);
};

}