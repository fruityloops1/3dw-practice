#pragma once

#include "al/liveactor/liveactor.h"

namespace rc
{

class PlayerActor : public al::LiveActor
{
public:
    spad(gap, 0x168);
    sead::Vector3f** mUnkBufferPos;
};

}