#pragma once

#include <fl/efun>

namespace al
{

class IUseLayout
{

};

class LayoutActor : public IUseLayout
{
public:
    spad(gap, 0x58);
    const char* mActorName;
};

EFUN(0x00967F10, void, setPaneString, EFUN_ARGS(al::IUseLayout* layout, const char* paneName, const char16_t* string, unsigned short));
EFUN(0x00968540, void, setPaneStringFormat, EFUN_ARGS(al::IUseLayout* layout, const char* paneName, const char* format, ...));
EFUN(0x00967DC0, void, setPaneStringLength, EFUN_ARGS(al::IUseLayout* layout, const char* paneName, const char16_t* string, unsigned short u, int length));

} // namespace al