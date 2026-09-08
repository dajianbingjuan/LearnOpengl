#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
	glm::vec3 m_Position;
	glm::vec3 m_front;

	glm::vec3 worldUp;

	
public:
	Camera(glm::vec3 position,glm::vec3 front);
	glm::mat4 getMat4();


};
