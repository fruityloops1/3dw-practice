#pragma once

#include <fl/efun>

namespace al
{

EFUN(0x00941CA0, bool, isPadTriggerLeft, EFUN_ARGS(int port));
EFUN(0x00941D90, bool, isPadTriggerRight, EFUN_ARGS(int port));
EFUN(0x00941BB0, bool, isPadTriggerDown, EFUN_ARGS(int port));
EFUN(0x00941AC0, bool, isPadTriggerUp, EFUN_ARGS(int port));
EFUN(0x00942F70, bool, isPadHoldA, EFUN_ARGS(int port));
EFUN(0x00943510, bool, isPadHoldL, EFUN_ARGS(int port));
EFUN(0x00943600, bool, isPadHoldR, EFUN_ARGS(int port));

}