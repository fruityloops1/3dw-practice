#pragma once

#include <fl/efun>
#include <sead/math/seadVector.h>
#include <types>

namespace al
{

class ActorPoseKeeper
{
public:
    spad(gap, 0x8);
    sead::Vector3f mTrans;
};

class LiveActor
{
public:
    virtual void* getNerveKeeper() const;
    virtual void init(const void*&);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAlive();
    virtual void kill();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void draw() const;
    virtual void startClipped();
    virtual void endClipped();
    virtual void attackSensor(void*, void*);
    virtual bool receiveMsg(const void*, void*, void*);
    virtual bool receiveMsgScreenPoint(const void*, void*, void*);
    virtual const char* getName() const;
    virtual void* getBaseMtx() const;
    virtual void* getEffectKeeper() const;
    virtual void* getAudioKeeper() const;
    virtual void* getStageSwitchKeeper() const;
    virtual void* getRailRider() const;
    virtual void* getSceneObjHolder() const;
    virtual void* getCollisionDirector() const;
    virtual void* getAreaObjDirector() const;
    virtual void* getCameraDirector() const;
    virtual void initStageSwitchKeeper();
    virtual void control();
    virtual void updateCollider();
    spad(gap, 0x50);
    ActorPoseKeeper* mActorPoseKeeper;
}; // unknown size

} // namespace al