#pragma once

#include "Victoria/Renderer/Shader.h"
#include <glad/glad.h>
#include <string>
#include <fstream>

namespace Victoria
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string &filepath);
        OpenGLShader(const std::string &name, const std::string &vertexSource, const std::string &fragmentSource);
        ~OpenGLShader();

        void Bind() const;
        void Unbind() const;

    private:
        std::string ReadFile(const std::string &filepath);
        std::unordered_map<unsigned int, std::string> PreProcess(const std::string &source);
        void Compile(const std::unordered_map<unsigned int, std::string> &shaderSources);

    private:
        uint32_t m_RendererID;
        std::string m_Name;
    };
} 
