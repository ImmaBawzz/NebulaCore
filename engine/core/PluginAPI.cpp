#include "PluginAPI.h"

namespace nebula {

PluginRegistry& PluginRegistry::Instance() {
    static PluginRegistry instance;
    return instance;
}

void PluginRegistry::RegisterFactory(const PluginFactory& factory) {
    m_Factories.push_back(factory);
}

std::vector<std::shared_ptr<IModule>> PluginRegistry::CreateAllModules() {
    std::vector<std::shared_ptr<IModule>> modules;
    for (auto& f : m_Factories) {
        modules.push_back(f());
    }
    return modules;
}

} // namespace nebula
