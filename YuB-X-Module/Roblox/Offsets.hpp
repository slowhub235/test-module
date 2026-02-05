#pragma once

#include <cstdint>
#include <Windows.h>

struct lua_State;
struct WeakThreadRef;
struct DebuggerResult;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    const uintptr_t Print = REBASE(0x1A986C0);
    const uintptr_t TaskDefer = REBASE(0x1A7E540);
    const uintptr_t RawScheduler = REBASE(0x7D33708);
    const uintptr_t OpcodeLookupTable = REBASE(0x5CDA330);
    const uintptr_t ScriptContextResume = REBASE(0x19B0650);

    namespace Luau
    {
        const uintptr_t Luau_Execute = REBASE(0x3978150);
        const uintptr_t LuaO_NilObject = REBASE(0x57F3768);
        const uintptr_t LuaH_DummyNode = REBASE(0x57F2E58);
    }

    namespace DataModel
    {
        const uintptr_t Children = 0x70;
        const uintptr_t GameLoaded = 0x5F8;
        const uintptr_t ScriptContext = 0x3F0;
        const uintptr_t FakeDataModelToDataModel = 0x1C0;

        const uintptr_t FakeDataModelPointer = REBASE(0x7C75728);
    }

    namespace ExtraSpace
    {
        const uintptr_t RequireBypass = 0x8F8;
        const uintptr_t InstanceToLuaState = 0x2E8;
        const uintptr_t ScriptContextToResume = 0x838;
    }
}

namespace Roblox
{
    inline auto TaskDefer = (int(__fastcall*)(lua_State*))Offsets::TaskDefer;
    inline auto Print = (uintptr_t(__fastcall*)(int, const char*, ...))Offsets::Print;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
    inline auto ScriptContextResume = (int(__fastcall*)(int64_t, DebuggerResult*, WeakThreadRef**, int32_t, bool, const char*))Offsets::ScriptContextResume;
}

// Dont forget to update TaskScheduler::GetGlobalStateForInstance, Encryptions and Structs
