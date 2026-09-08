#include "core/Window.h"
#include "core/Renderer.h"
#include "core/VBO.h"
#include "core/EBO.h"
#include "core/VAO.h"
#include "core/shader.h"
#include "core/Mesh.h"
#include "core/Texture.h"
#include "core/Camera.h"
#include "core/CameraController.h"

const int SCR_WIDTH = 1280, SCR_HEIGHT = 960;

int main() {

	Window window(SCR_WIDTH, SCR_HEIGHT, "MyWindow");
	window.setMouseMode(GLFW_CURSOR_DISABLED);
	Renderer renderer;
	glEnable(GL_DEPTH_TEST);

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3 
	};

	Mesh mesh1(vertices, indices, sizeof(vertices) / sizeof(float), sizeof(indices) / sizeof(unsigned int));

	//着色器
	Shader shader("res/shader/test1.shader");

	//VAO
	VAO vao;
	vao.bindVAO();

	//VBO
	VBO vbo;
	vbo.setVBOdata(mesh1.getVSize() * sizeof(float), mesh1.getVertex(), GL_STATIC_DRAW);

	////EBO
	//EBO ebo;
	//ebo.setEBOdata(mesh1.getISize() * sizeof(unsigned int), mesh1.getIndices(), GL_STATIC_DRAW);

	//VAO布局
	vao.setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	vao.enableAttrib(0);
	vao.setAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.enableAttrib(1);


	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f));


	CameraController cameraController(camera, window);

	//纹理
	Texture::setFlip(true);
	Texture texture1("res/textures/container.jpg");
	Texture texture2("res/textures/awesomeface.png");

	shader.useShader();
	//传纹理单元
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);

	glm::vec3 cubePositions[] = {
		glm::vec3( 0.0f,  0.0f,  0.0f),
		glm::vec3( 2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3( 2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3( 1.3f, -2.0f, -2.5f),
		glm::vec3( 1.5f,  2.0f, -2.5f),
		glm::vec3( 1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	const unsigned int cubeCount = sizeof(cubePositions) / sizeof(glm::vec3);

	//渲染前集中解绑
	vbo.unbindVBO();
	vao.unbindVAO();
	shader.unShader();

	while (!window.shouldClose()) {
		window.beginFrame();

		cameraController.update();


		glm::mat4 view = camera.getViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(camera.getFov()),
			(float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		shader.useShader();
		shader.setFloat4("view", view);
		shader.setFloat4("projection", projection);

		vao.bindVAO();
		texture1.activeTexture(GL_TEXTURE0);
		texture2.activeTexture(GL_TEXTURE1);

		for (unsigned int i = 0; i < cubeCount; ++i) {
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * (float)i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
			shader.setFloat4("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		window.endFrame();
	}

	return 0;
}
