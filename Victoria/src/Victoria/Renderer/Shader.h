#pragma once

#include "Victoria/Core/Base.h"
#include <glm/glm.hpp>

#include <string>
#include <unordered_map>

namespace Victoria
{
    class Shader
    {
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetBool(const std::string& name, bool value) const = 0;
		virtual void SetInt(const std::string& name, int value) const = 0;
		virtual void SetFloat(const std::string& name, float value) const = 0;
		virtual void SetVec2(const std::string& name, const glm::vec2& value) const = 0;
		virtual void SetVec2(const std::string& name, float x, float y) const = 0;
		virtual void SetVec3(const std::string& name, const glm::vec3& value) const = 0;
		virtual void SetVec3(const std::string& name, float x, float y, float z) const = 0;
		virtual void SetVec4(const std::string& name, const glm::vec4& value) const = 0;
		virtual void SetVec4(const std::string& name, float x, float y, float z, float w) const = 0;
		virtual void SetMat2(const std::string& name, const glm::mat2& mat) const = 0;
		virtual void SetMat3(const std::string& name, const glm::mat3& mat) const = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& mat) const = 0;
		virtual void UploadUniformIntArray(const std::string& name, int* values, uint32_t count) = 0;

		virtual const std::string& GetName() const = 0;

		static Ref<Shader> Create(const std::string & filepath);
		static Ref<Shader> Create(const std::string & name, const std::string & vertexSrc, const std::string & fragmentSrc);
	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string& name, const Ref<Shader>& shader);
		void Add(const Ref<Shader>& shader);
		Ref<Shader> Load(const std::string& filepath);
		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};

} 
