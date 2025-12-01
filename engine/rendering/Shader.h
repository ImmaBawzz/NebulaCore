#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace nebula {

class Shader {
public:
    Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // Uniforms
    void SetUniformInt(const std::string& name, int value);
    void SetUniformFloat(const std::string& name, float value);
    void SetUniformFloat3(const std::string& name, const glm::vec3& value);
    void SetUniformFloat4(const std::string& name, const glm::vec4& value);
    void SetUniformMat4(const std::string& name, const glm::mat4& value);

private:
    uint32_t m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;

    int GetUniformLocation(const std::string& name);
    uint32_t CompileShader(uint32_t type, const std::string& source);
    uint32_t CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
};

} // namespace nebula
