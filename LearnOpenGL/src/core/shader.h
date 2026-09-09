#pragma once
#include<glad/glad.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>     

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};
class Shader {
	private:
		unsigned int m_id;
		ShaderProgramSource source;
	public:
		Shader(const char* shader);
		~Shader();
		void CompileShader(const char* shaderfile);
		void useShader();
		void unShader();
		void setBool(const char* name, bool value) const;
		void setInt(const char* name, int value) const;
		void setFloat(const char* name, float value) const;
		void setFloat3(const char* name, float value0, float value1, float value2) const;
		void setFloat4(const char* name, float value0,float value1, float value2, float value3) const;
		void setVec3(const char* name, glm::vec3 value) const;
		void setMat4(const char* name, glm::mat4& mat4) const;
};