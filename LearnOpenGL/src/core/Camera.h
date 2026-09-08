#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
	glm::vec3 m_Position;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
	glm::vec3 m_WorldUp;

	float m_Yaw = -90.0f;
	float m_Pitch = 0.0f;
	float m_Fov = 45.0f;

	float m_MoveSpeed = 5.0f; 
	float m_MouseSensitivity = 0.1f;
	float m_ZoomSpeed = 1.0f;

public:

	Camera(const glm::vec3& position, const glm::vec3& target);

	glm::mat4 getViewMatrix() const;


	void move(const glm::vec3& direction, float deltaTime);

	void rotate(float xOffset, float yOffset);

	void zoom(float yOffset);

	glm::vec3 getPosition() const { return m_Position; }
	glm::vec3 getFront()    const { return m_Front; }
	glm::vec3 getRight()    const { return m_Right; }
	glm::vec3 getUp()       const { return m_Up; }
	glm::vec3 getWorldUp()  const { return m_WorldUp; }
	float getFov()          const { return m_Fov; }

private:

	void updateCameraVectors();
};
