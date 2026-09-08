#include "Camera.h"

Camera::Camera(const glm::vec3& position, const glm::vec3& target)
	: m_Position(position)
{
	m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::vec3 direction = target - position;
	if (glm::length(direction) < 1e-6f)
		direction = glm::vec3(0.0f, 0.0f, -1.0f);
	direction = glm::normalize(direction);

	m_Yaw = glm::degrees(glm::atan(direction.z, direction.x));
	m_Pitch = glm::degrees(glm::asin(glm::clamp(direction.y, -1.0f, 1.0f)));

	updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::move(const glm::vec3& direction, float deltaTime)
{
	m_Position += direction * (m_MoveSpeed * deltaTime);
}

void Camera::rotate(float xOffset, float yOffset)
{
	m_Yaw += xOffset * m_MouseSensitivity;
	m_Pitch += yOffset * m_MouseSensitivity;

	if (m_Pitch > 89.0f)  m_Pitch = 89.0f;
	if (m_Pitch < -89.0f) m_Pitch = -89.0f;

	updateCameraVectors();
}

void Camera::zoom(float yOffset)
{
	m_Fov -= yOffset * m_ZoomSpeed;
	if (m_Fov < 1.0f)  m_Fov = 1.0f;
	if (m_Fov > 89.0f) m_Fov = 89.0f;
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = glm::normalize(front);

	m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}
