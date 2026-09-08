#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 front)
{
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	m_Position = position;
	m_front = front;
}

glm::mat4 Camera::getMat4()
{
	return glm::lookAt(m_Position, m_front, worldUp);
}
