#include "al/layout.h"
#include "al/liveactor/liveactor.h"
#include "al/util/actor.h"
#include "al/util/misc.h"
#include "al/util/input.h"
#include "al/misc/playerholder.h"
#include "fl/menu.h"
#include "sead/math/seadVector.h"
#include "sead/prim/seadStringUtil.h"

void setPaneStringLengthHook(al::IUseLayout* layout, const char* paneName, const char16_t* string, unsigned short u, int length)
{
    al::setPaneStringLength(layout, paneName, string, u, length);
    if (al::isEqualString(paneName, "TxtCounterDisable"))
    {
        char16_t sb[4096]{0};
        fl::DebugMenu::instance().show(sb, 4096);
        al::setPaneString(layout, "TxtDebug", sb, 0);
    }
}

al::LiveActor* tryGetPlayerHook(al::PlayerHolder* dis, int index)
{
    fl::DebugMenu::instance().mPlayerHolder = dis;
    return dis->tryGetPlayer(index);
}

bool isPadTriggerDownMenu(int port)
{
    return fl::DebugMenu::instance().isInputDisabled() ? false : al::isPadTriggerDown(port);
}

bool isPadTriggerUpMenu(int port)
{
    return fl::DebugMenu::instance().isInputDisabled() ? false : al::isPadTriggerUp(port);
}