#include "Window.h"

int Window::m_window_Count = 0;

Window::Window()
{
	createWindow(1280, 960, "MyWindow");
}

Window::Window(int width, int height, const char* windowTitle)
{
	createWindow(width, height, windowTitle);
}

void Window::createWindow(int width, int height, const char* windowTitle)
{
	if (m_window_Count == 0) {
		if (!glfwInit()) {
			std::cout << "[Window Warning] 初始化 glfw 失败" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, windowTitle, nullptr, nullptr);
	if (!m_window) {
		std::cout << "[Window Warning] 创建窗口失败" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "[Window Warning] 初始化 glad 失败" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	m_window_Count++;

	glfwSetWindowUserPointer(m_window, this);
	glfwSetCursorPosCallback(m_window, mousePosCallback);
	glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
	glfwSetScrollCallback(m_window, scrollCallback);
}

void Window::beginFrame()
{
	glfwPollEvents();
	glfwMakeContextCurrent(m_window);

	updateInput();

	float currentFrame = (float)glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::endFrame()
{
	glfwSwapBuffers(m_window);
}

float Window::getDelta()
{
	return deltaTime;
}

bool Window::shouldClose()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return true;
	return glfwWindowShouldClose(m_window);
}

InputState& Window::getKeyInput()
{
	return m_inputState;
}

void Window::updateInput()
{
	m_inputState.keyW = (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS);
	m_inputState.keyA = (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS);
	m_inputState.keyS = (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS);
	m_inputState.keyD = (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS);
	m_inputState.keySpace = (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS);
	m_inputState.keyShift = (glfwGetKey(m_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS);
}

void Window::getMouseOffset(double& xOffset, double& yOffset)
{
	xOffset = m_mouseOffsetX;
	yOffset = m_mouseOffsetY;

	m_mouseOffsetX = 0.0;
	m_mouseOffsetY = 0.0;
}

float Window::getScrollOffset()
{
	float offset = (float)m_scrollOffset;
	m_scrollOffset = 0.0;
	return offset;
}

void Window::setMouseMode(unsigned int mode)
{
	glfwSetInputMode(m_window, GLFW_CURSOR, mode);
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}

int Window::getCount()
{
	return m_window_Count;
}

void Window::mousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (win)
		win->onMouseMove(xpos, ypos);
}

void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (win)
		win->onMouseButton(button, action, mods);
}

void Window::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (win)
		win->onScroll(xoffset, yoffset);
}

void Window::onMouseMove(double xpos, double ypos)
{
	if (m_firstMouse) {
		m_mouseLastX = xpos;
		m_mouseLastY = ypos;
		m_firstMouse = false;
		return;
	}

	m_mouseOffsetX += xpos - m_mouseLastX;
	m_mouseOffsetY += (m_mouseLastY - ypos);

	m_mouseLastX = xpos;
	m_mouseLastY = ypos;
}

void Window::onMouseButton(int button, int action, int mods)
{
	(void)button;
	(void)action;
	(void)mods;
}

void Window::onScroll(double xoffset, double yoffset)
{
	(void)xoffset;
	m_scrollOffset += yoffset;
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
