#pragma once

#include "Victoria/Renderer/Buffer.h"
#include "Victoria/Renderer/Shader.h"
#include "Victoria/Renderer/Material.h"


namespace Victoria
{
	struct Vertices
	{
		glm::vec3 Position;
		glm::vec3 Normals;
		glm::vec2 Textures;
	};

	struct Indices
	{
		
	};

    class Mesh
    {
    public:
		Mesh(const std::string& filepath);
		Mesh(const std::vector<Vertices>& vertices, const std::vector<Indices>& indices, const glm::mat4& transform);


		const std::vector<Vertices>& GetVertices() { return m_Vertices; }
		const std::vector<Indices>& GetIndices() { return m_Indices; }

		const std::string& GetFilePath() const { return m_Filepath; }
		static Ref<Mesh> Create(const std::string& filepath);
    private:
		std::vector<Vertices> m_Vertices;
		std::vector<Indices> m_Indices;
		std::string m_Filepath;
    };
}
