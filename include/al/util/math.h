#pragma once

#include "sead/math/seadVector.h"
#include <fl/efun>

namespace al
{

EFUN(0x00863700, void, verticalizeVec, EFUN_ARGS(sead::Vector3f& dst, const sead::Vector3f& v1, const sead::Vector3f& v2));

}