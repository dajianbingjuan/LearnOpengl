#include "Window.h"

int Window::m_window_Count = 0;


Window::Window()
{
	Window::createWindow(1280, 960, "MyWindow");
}


Window::Window(int width, int height,const char* windowTitle)
{
	Window::createWindow(width,height,windowTitle);
}

void Window::createWindow(int width, int height, const char* windowTitle) {
	if (m_window_Count == 0) {
		if (!glfwInit()) {
			std::cout << "[Window类 Warning]  初始化glfw失败" <<std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
	if (!window)
	{
		std::cout << "[Window类 Warning]  创建窗口失败" << std::endl;
		std::exit(EXIT_FAILURE);

	}
	m_window = window;
	glfwMakeContextCurrent(m_window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[Window类 Warning]  初始化glad失败" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	m_window_Count++;
}

void Window::beginFrame() {
	glfwPollEvents();
	glfwMakeContextCurrent(m_window);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Window::endFrame() {
	glfwSwapBuffers(m_window);
}

float Window::getDelta()
{
	return deltaTime;
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}

int Window::getCount()
{
	return m_window_Count;
}


Window::~Window()
{
	if (m_window) {
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
	if (--m_window_Count == 0) {
		glfwTerminate();
	}
}
