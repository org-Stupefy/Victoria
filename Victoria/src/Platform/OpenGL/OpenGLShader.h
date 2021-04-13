#pragma once

#include "Victoria/Renderer/Shader.h"
#include <glm/glm.hpp>

namespace Victoria
{
    class OpenGLShader : public Shader
    {
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

		~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		void SetBool(const std::string& name, bool value) const override;
		void SetInt(const std::string& name, int value) const override;
		void SetFloat(const std::string& name, float value) const override;
		void SetVec2(const std::string& name, const glm::vec2& value) const override;
		void SetVec2(const std::string& name, float x, float y) const override;
		void SetVec3(const std::string& name, const glm::vec3& value) const override;
		void SetVec3(const std::string& name, float x, float y, float z) const override;
		void SetVec4(const std::string& name, const glm::vec4& value) const override;
		void SetVec4(const std::string& name, float x, float y, float z, float w) const override;
		void SetMat2(const std::string& name, const glm::mat2& mat) const override;
		void SetMat3(const std::string& name, const glm::mat3& mat) const override;
		void SetMat4(const std::string& name, const glm::mat4& mat) const override;

		uint32_t GetRendererID()
		{
			return m_RendererID;
		}

		virtual const std::string& GetName() const override { return m_Name; }

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<uint32_t, std::string> Process(const std::string& source);
		void Compile(std::unordered_map<uint32_t, std::string>& shaderSources);

	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
} 
