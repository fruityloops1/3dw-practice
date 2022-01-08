#pragma once

#include "al/util/math.h"
#include "sead/math/seadVector.h"
#include <al/liveactor/liveactor.h>
#include <fl/efun>
#include <math.h>

namespace al
{

EFUN(0x00839750, void, setTrans, EFUN_ARGS(al::LiveActor* actor, const sead::Vector3f& trans));
EFUN(0x00839EC0, void, setVelocity, EFUN_ARGS(al::LiveActor* actor, const sead::Vector3f& vel));
EFUN(0x00839830, const sead::Vector3f&, getTrans, EFUN_ARGS(al::LiveActor* actor));
EFUN(0x00839820, const sead::Vector3f&, getGravity, EFUN_ARGS(al::LiveActor* actor));
EFUN(0x00836350, const sead::Vector3f&, getVelocity, EFUN_ARGS(al::LiveActor* actor));
EFUN(0x00429bb0, void*, unknownGetter1, al::LiveActor*);

inline float calcSpeedH(al::LiveActor* actor)
{
    sead::Vector3f verticalized;
    verticalizeVec(verticalized, getGravity(actor), getVelocity(actor));
    return sqrtf(verticalized.x*verticalized.x + verticalized.y*verticalized.y + verticalized.z*verticalized.z);
}
inline float calcSpeedV(al::LiveActor* actor)
{
    const sead::Vector3f& velocity = getVelocity(actor);
    const sead::Vector3f& gravity = getGravity(actor);
    return -(velocity.y * gravity.y);
}
inline float calcSpeed(al::LiveActor* actor)
{
    const sead::Vector3f& velocity = getVelocity(actor);
    return sqrtf(velocity.x*velocity.x + velocity.y*velocity.y + velocity.z*velocity.z);
}

}