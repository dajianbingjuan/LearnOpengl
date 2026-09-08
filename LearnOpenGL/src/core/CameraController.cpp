#include "CameraController.h"
#include "Window.h"

CameraController::CameraController(Camera& camera, Window& window)
	: m_Camera(&camera), m_Window(&window)
{
}

void CameraController::update()
{

	const InputState& input = m_Window->getKeyInput();

	glm::vec3 front = m_Camera->getFront();
	glm::vec3 horizontalFront = glm::normalize(glm::vec3(front.x, 0.0f, front.z));

	glm::vec3 direction(0.0f);
	if (input.keyW)     direction += horizontalFront;
	if (input.keyS)     direction -= horizontalFront;
	if (input.keyA)     direction -= m_Camera->getRight();
	if (input.keyD)     direction += m_Camera->getRight();
	if (input.keySpace) direction += m_Camera->getWorldUp();
	if (input.keyShift) direction -= m_Camera->getWorldUp();

	if (glm::length(direction) > 1e-6f)
		m_Camera->move(glm::normalize(direction), m_Window->getDelta());


	double xOffset = 0.0, yOffset = 0.0;
	m_Window->getMouseOffset(xOffset, yOffset);
	m_Camera->rotate((float)xOffset, (float)yOffset);

	m_Camera->zoom(m_Window->getScrollOffset());
}
