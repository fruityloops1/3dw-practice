#pragma once

#include "al/liveactor/liveactor.h"
#include "al/misc/playerholder.h"
#include "sead/math/seadVector.h"
#include "unk.h"
#include <types>

namespace fl
{

class DebugMenu
{
public:
    static DebugMenu& instance();
    void show(char16_t* paneTxt, const u32 len);
    al::PlayerHolder* mPlayerHolder = nullptr;
    inline bool isInputDisabled() {if (mInputDisabled && mShowMenu) return false; return mShowMenu;}
private:
    sead::Vector3f mTpPos{0, 0, 0};
    u8 mCurPlayer = 0;
    bool mShowMenu = true;
    bool mInputDisabled = false;
    u8 mCurLine = 0;

    enum Page : u8
    {
        About = 0, Info = 1, Options = 2, Item = 3
    } mCurPage;

    bool mTeleportEnabled = false;
};

}