#include "Shader.h"

Shader::Shader(const char* Shaderfile)
{
	Shader::CompileShader(Shaderfile);
	unsigned int vertexShader;
	const char* vs = source.VertexSource.c_str();
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1,&vs, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	const char* fs = source.FragmentSource.c_str();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fs, NULL);
	glCompileShader(fragmentShader);


	unsigned int ShaderProgram = glCreateProgram();
	m_id = ShaderProgram;
	glAttachShader(ShaderProgram, vertexShader);
	glAttachShader(ShaderProgram, fragmentShader);
	glLinkProgram(ShaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}


Shader::~Shader()
{
	glDeleteProgram(m_id);
}

void Shader::CompileShader(const char* Shaderfile) {
	std::ifstream stream(Shaderfile);
	std::string line;
	std::stringstream ss[2];
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}
	source.VertexSource = ss[0].str();
	source.FragmentSource = ss[1].str();
}

void Shader::useShader()
{
	glUseProgram(m_id);
}

void Shader::unShader() {
	glUseProgram(0);
}
void Shader::setBool(const char* name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_id, name),value);
}

void Shader::setInt(const char* name, int value) const
{
	glUniform1i(glGetUniformLocation(m_id, name), value);
}

void Shader::setFloat(const char* name, float value) const
{
	glUniform1f(glGetUniformLocation(m_id, name), value);
}

void Shader::setFloat4(const char* name, float value0, float value1, float value2, float value3) const
{
	glUniform4f(glGetUniformLocation(m_id, name), value0, value1, value2, value3);
}

void Shader::setFloat4(const char* name, glm::mat4& mat4) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_id, name),1, GL_FALSE, glm::value_ptr(mat4));
}
