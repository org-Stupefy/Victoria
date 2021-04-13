#pragma once

#include <glm/glm.hpp>

namespace Victoria
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetProjection(float left, float right, float bottom, float top);
		const glm::vec3& GetPosition() const { return m_Position; }
		//const glm::vec3& GetRotation() const { return m_Rotation; }
		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		float GetRotation() const { return m_Rotation; }

		void SetPosition(const glm::vec3& position)
		{
			m_Position = position;
			RecalculateViewMatrix();
		}

		/*void SetRotation(const glm::vec3& rotation) {
			m_Rotation = rotation;
			RecalculateViewMatrix();
		}*/

		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

	private:
		void RecalculateViewMatrix();

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;	// For 2D
		//glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };	//FOR 3D
	};
}
