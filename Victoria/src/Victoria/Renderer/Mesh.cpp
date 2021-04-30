#include "vcpch.h"

#include "Victoria/Renderer/Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Victoria
{
	glm::mat4 AssimpMat4ToGlmMat4(const aiMatrix4x4& matrix)
	{
		glm::mat4 result;
		result[0][0] = matrix.a1; result[1][0] = matrix.a2; result[2][0] = matrix.a3; result[3][0] = matrix.a4;
		result[0][1] = matrix.b1; result[1][1] = matrix.b2; result[2][1] = matrix.b3; result[3][1] = matrix.b4;
		result[0][2] = matrix.c1; result[1][2] = matrix.c2; result[2][2] = matrix.c3; result[3][2] = matrix.c4;
		result[0][3] = matrix.d1; result[1][3] = matrix.d2; result[2][3] = matrix.d3; result[3][3] = matrix.d4;
		return result;
	}

	const uint32_t s_MeshImportFlags = aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_GenUVCoords | aiProcess_OptimizeMeshes | aiProcess_ValidateDataStructure | aiProcess_JoinIdenticalVertices;

	Mesh::Mesh(const std::string& filepath)
		:m_Filepath(filepath)
	{
		auto importer = CreateScope<Assimp::Importer>();
		const aiScene* scene = importer->ReadFile(filepath, s_MeshImportFlags);
		if (!scene || !scene->HasMeshes()) VC_CORE_ERROR("Failed to load mesh file: %s", filepath.c_str());


	}

	Mesh::Mesh(const std::vector<Vertices>& vertices, const std::vector<uint32_t>& indices, const glm::mat4& transform)
	{


	}

	Victoria::Ref<Victoria::Mesh> Mesh::Create(const std::string& filepath)
	{
		return 0;
	}
}
