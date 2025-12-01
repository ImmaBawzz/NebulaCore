#pragma once
#include <functional>
#include <vector>
#include <memory>
#include "Module.h"

namespace nebula {

using PluginFactory = std::function<std::shared_ptr<IModule>()>;

class PluginRegistry {
public:
    static PluginRegistry& Instance();
    void RegisterFactory(const PluginFactory& factory);
    std::vector<std::shared_ptr<IModule>> CreateAllModules();

private:
    std::vector<PluginFactory> m_Factories;
};

} // namespace nebula
