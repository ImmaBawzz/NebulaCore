#pragma once
#include "PluginAPI.h"

#define NEBULA_REGISTER_MODULE(ModuleType) \
    namespace { \
        struct ModuleType##AutoRegister { \
            ModuleType##AutoRegister() { \
                nebula::PluginRegistry::Instance().RegisterFactory([](){ \
                    return std::make_shared<ModuleType>(); \
                }); \
            } \
        }; \
        static ModuleType##AutoRegister s_##ModuleType##AutoRegister; \
    }
