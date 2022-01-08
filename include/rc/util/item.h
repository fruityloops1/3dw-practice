#pragma once

#include "al/liveactor/liveactor.h"
#include <fl/efun>

namespace rc
{

EFUN(0x0080f3a0, void, dropBufferItem, EFUN_ARGS(al::LiveActor* player, const char* itemName, const sead::Vector3f& dropPos, void* unknown));

}