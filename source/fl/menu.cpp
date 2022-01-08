#include "al/liveactor/liveactor.h"
#include "al/sensor/hitsensor.h"
#include "al/util/actor.h"
#include "al/util/input.h"
#include "rc/player/playeractor.h"
#include "rc/util/item.h"
#include "sead/math/seadVector.h"
#include "sead/prim/seadStringUtil.h"
#include <fl/menu.h>

#define printf(FORMAT, ...) {sprintfRv = sead::StringUtil::sw16printf(paneTxt + printPos, 4096 - printPos, FORMAT, ##__VA_ARGS__); printPos += sprintfRv;}

#define NUM_PAGES 4

#define CURSOR(LINE) printf(mCurLine == LINE ? u">" : u"")
#define CHANGE_PAGE() printf(u"Change Page (%d/%d) %s\n", +mCurPage + 1, NUM_PAGES, mInputDisabled ? u"[Input Locked]" : u"")

// Sets max amount of lines for a page
#define MAX_LINE(LINE) if (mCurLine > LINE) mCurLine = 0;

#define TOGGLE(FORMAT, BOOL, LINE) CURSOR(LINE);\
                                   printf(FORMAT u": %s\n", BOOL ? u"Enabled" : u"Disabled");\
                                   if (mCurLine == LINE && inputEnabled && (al::isPadTriggerLeft(-1) || al::isPadTriggerRight(-1))) BOOL = !BOOL;

#define TRIGGER(NAME, LINE, ACTION) CURSOR(LINE);\
                              printf(NAME u"\n");\
                              if (mCurLine == LINE && inputEnabled && al::isPadTriggerRight(-1)) {ACTION;}

fl::DebugMenu& fl::DebugMenu::instance() {static DebugMenu menu; return menu;}

void fl::DebugMenu::show(char16_t* paneTxt, const u32 len)
{
    bool inputEnabled = !al::isPadHoldL(-1);
    if (al::isPadHoldL(-1) && al::isPadTriggerLeft(-1)) mShowMenu = !mShowMenu;
    if (!mShowMenu)
    {
        sead::StringUtil::sw16printf(paneTxt, len, u"\n");

        rc::PlayerActor* player = (rc::PlayerActor*) mPlayerHolder->tryGetPlayer(mCurPlayer);
        if (!player || !mTeleportEnabled) return;
        const sead::Vector3f& pos = al::getTrans(player);
        if (al::isPadTriggerLeft(-1) && inputEnabled && mTeleportEnabled)
            mTpPos = pos;
        else if (al::isPadTriggerRight(-1))
        {
            al::setTrans(player, mTpPos);
            **player->mUnkBufferPos = mTpPos;
        }
        return;
    }
    if (al::isPadHoldL(-1) && al::isPadTriggerRight(-1)) mInputDisabled = !mInputDisabled;
    if (mInputDisabled) inputEnabled = false;

    u32 printPos = 0;
    s32 sprintfRv;
    
    for (u8 playerIndex = 0; playerIndex < mPlayerHolder->getPlayerNum(); playerIndex++)
    {
        rc::PlayerActor* lplayer = (rc::PlayerActor*) mPlayerHolder->tryGetPlayer(playerIndex);
        if (lplayer)
        {
            const sead::Vector3f& vel = al::getVelocity(lplayer);
            if (vel.x != 0.0f || vel.y != 0.0f || vel.z != 0.0f)
                mCurPlayer = playerIndex;
        }
    }

    rc::PlayerActor* player = (rc::PlayerActor*) mPlayerHolder->tryGetPlayer(mCurPlayer);
    if (!player) return;
    
    if (al::isPadTriggerDown(-1) && inputEnabled) mCurLine++;
    if (al::isPadTriggerUp(-1) && inputEnabled) mCurLine--;

    if (mCurLine == 0)
    {
        if (al::isPadTriggerRight(-1) && inputEnabled)
        {
            if (mCurPage == About) mCurPage = Info;
            else if (mCurPage == Info) mCurPage = Options;
            else if (mCurPage == Options) mCurPage = Item;
            else if (mCurPage == Item) mCurPage = About;
        }
        else if (al::isPadTriggerLeft(-1) && inputEnabled)
        {
            if (mCurPage == About) mCurPage = Item;
            else if (mCurPage == Info) mCurPage = About;
            else if (mCurPage == Options) mCurPage = Info;
            else if (mCurPage == Item) mCurPage = Options;
        }
    }

    switch (mCurPage)
    {
        case About:
        {
            printf(u"Welcome to the Practice Mod!\n");
            MAX_LINE(0);
            CURSOR(0);
            CHANGE_PAGE();
            printf(u"Made by Fruityloops#8500\n");
            printf(u"L+DPad Left to toggle menu\n");
            break;
        }
        case Info:
        {
            printf(u"Info\n");
            MAX_LINE(0);
            CURSOR(0);
            CHANGE_PAGE();

            const sead::Vector3f& pos = al::getTrans(player);
            const sead::Vector3f& vel = al::getVelocity(player);
            float hSpeed = al::calcSpeedH(player), vSpeed = al::calcSpeedV(player), speed = al::calcSpeed(player);
            printf(u"Pos: (X: %.3f Y: %.3f Z: %.3f)\n", pos.x, pos.y, pos.z);
            printf(u"Vel: (X: %.3f Y: %.3f Z: %.3f)\n", vel.x, vel.y, vel.z);
            printf(u"Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
            break;
        }
        case Options:
        {
            printf(u"Options\n");
            MAX_LINE(1);
            CURSOR(0);
            CHANGE_PAGE();

            TOGGLE(u"Teleport", mTeleportEnabled, 1);

            break;
        }
        case Item:
        {
            printf(u"Items\n");
            MAX_LINE(7);
            CURSOR(0);
            CHANGE_PAGE();

            void* unknownPtr = al::unknownGetter1(player);

            TRIGGER(u"Super Mushroom", 1, rc::dropBufferItem(player, "スーパーキノコ", al::getTrans(player), unknownPtr));
            TRIGGER(u"Super Bell", 2, rc::dropBufferItem(player, "スーパーベル", al::getTrans(player), unknownPtr));
            TRIGGER(u"Fire Flower", 3, rc::dropBufferItem(player, "ファイアフラワー", al::getTrans(player), unknownPtr));
            TRIGGER(u"Super Leaf", 4, rc::dropBufferItem(player, "スーパーこのは", al::getTrans(player), unknownPtr));
            TRIGGER(u"Boomerang Flower", 5, rc::dropBufferItem(player, "ブーメランフラワー", al::getTrans(player), unknownPtr));
            TRIGGER(u"Invincibility Leaf", 6, rc::dropBufferItem(player, "無敵このは", al::getTrans(player), unknownPtr));
            TRIGGER(u"Lucky Bell", 7, rc::dropBufferItem(player, "まねきネコベル", al::getTrans(player), unknownPtr));

            break;
        }
    }
}