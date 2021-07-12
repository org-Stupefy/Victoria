#pragma once

#include "Victoria/Renderer/Buffer.h"
#include "Victoria/Renderer/Shader.h"
#include "Victoria/Renderer/Material.h"
#include <glm/glm.hpp>

struct aiMesh;
struct aiNode;
struct aiMaterial;
enum aiTextureType;

namespace Victoria
{
	struct Vertices
	{
		glm::vec3 Position;
		glm::vec3 Normals;
		glm::vec2 Textures;
	};

    class Mesh
    {
    public:
		Mesh(const std::string& filepath);
		Mesh(const std::vector<Vertices>& vertices, const std::vector<uint32_t>& indices, const glm::mat4& transform);

		const std::vector<Vertices>& GetVertices() { return m_Vertices; }
		const std::vector<uint32_t>& GetIndices() { return m_Indices; }
		Ref<Shader>& GetShader() { return m_Shader; }

		const std::string& GetFilePath() const { return m_Filepath; }
		static Ref<Mesh> Create(const std::string& filepath);

	private: 
		void procesNode(aiNode* node, const glm::mat4& parentTransform = glm::mat4(1.0f), uint32_t level = 0);
    private:
		std::vector<Vertices> m_Vertices;
		std::vector<uint32_t> m_Indices;
		std::string m_Filepath;
		Ref<Shader>m_Shader;
    };
}
