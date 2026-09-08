#pragma once
#include "Camera.h"

class Window; 


class CameraController {
public:
	CameraController(Camera& camera, Window& window);

	void update();

private:
	Camera* m_Camera;
	Window* m_Window;
};
