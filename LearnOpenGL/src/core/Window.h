#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "InputState.h"


class Window {
private:
	static int m_window_Count;
	GLFWwindow* m_window = nullptr;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;


	InputState m_inputState;


	double m_mouseLastX = 0.0;
	double m_mouseLastY = 0.0;
	bool m_firstMouse = true;
	double m_mouseOffsetX = 0.0;
	double m_mouseOffsetY = 0.0;
	double m_scrollOffset = 0.0;

	void createWindow(int width, int height, const char* windowTitle);

	void onMouseMove(double xpos, double ypos);
	void onMouseButton(int button, int action, int mods);
	void onScroll(double xoffset, double yoffset);

	static void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

public:
	Window();
	Window(int width, int height, const char* windowTitle);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void beginFrame();
	void endFrame();
	bool shouldClose();
	float getDelta();

	InputState& getKeyInput();
	void updateInput();
	void getMouseOffset(double& xOffset, double& yOffset);
	float getScrollOffset(); 


	void setMouseMode(unsigned int mode); 
	GLFWwindow* getWindow();
	int getCount();
};
