#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

class Window {
private:
	static int m_window_Count;
	GLFWwindow* m_window;
	float deltaTime;
	float lastFrame=0.0f;
	void createWindow(int width, int height, const char* windowTitle);
	
public:
	Window();
	Window(int width,int height,const char* windowTitle);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	
	void beginFrame();

	void endFrame();
	float getDelta();
	bool shouldClose();
	GLFWwindow* getWindow();
	int getCount();
};
