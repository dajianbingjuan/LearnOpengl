#include "core/Window.h"
#include "core/Renderer.h"
#include "core/VBO.h"
#include "core/EBO.h"
#include "core/VAO.h"
#include "core/shader.h"
#include "core/Mesh.h"
#include "core/Texture.h"
#include "core/Camera.h"

const int SCR_WIDTH=1280, SCR_HEIGHT=960;
int main() {
	
	//创建窗口,创建上下文
	Window window(SCR_WIDTH, SCR_HEIGHT,"MyWindow");
	Renderer renderer;
	glEnable(GL_DEPTH_TEST);

	//顶点数据
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

	//索引数据
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	Mesh mesh1(vertices, indices, sizeof(vertices) / sizeof(float), sizeof(indices) / sizeof(unsigned int));

	//着色器
	Shader shader("res/shader/test1.shader");

	//VAO
	VAO vao;
	vao.bindVAO();

	//VBO
	VBO vbo;
	vbo.setVBOdata(mesh1.getVSize() * sizeof(float),mesh1.getVertex(), GL_STATIC_DRAW);

	for (int i = 0; i < mesh1.getVSize(); i++) {
		mesh1.getVertex()[i];
	}

	////EBO
	//EBO ebo;
	//ebo.setEBOdata(mesh1.getISize() * sizeof(float), mesh1.getIndices(), GL_STATIC_DRAW);


	//VAO布局
	vao.setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	vao.enableAttrib(0);
	vao.setAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.enableAttrib(1);


	Camera camera(glm::vec3(0.0f,0.0f,3.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	glm::mat4 model=glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	view = camera.getMat4();

	//纹理
	Texture::setFlip(true);
	Texture texure1("res/textures/container.jpg");
	Texture texure2("res/textures/awesomeface.png");
	
	shader.useShader();
	//传纹理
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);
	//传矩阵
	shader.setFloat4("model",model);
	shader.setFloat4("projection", projection);
	shader.setFloat4("view",view);

	//渲染前集中解绑
	vbo.unbindVBO();
	vao.unbindVAO();
	shader.unShader();
	
	

	while (!window.shouldClose()) {
		window.beginFrame();


		shader.useShader();
		vao.bindVAO();
		texure1.activeTexture(GL_TEXTURE0);
		texure2.activeTexture(GL_TEXTURE1);

		

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		

		window.endFrame();
	}
}

