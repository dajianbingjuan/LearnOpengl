#pragma once
#include<glad/glad.h>
class VBO {
private:
	unsigned int m_id;

public:
	VBO();
	~VBO();
	void bindVBO();
	void unbindVBO();
	void setVBOdata(unsigned int size,float data[], unsigned int mode);
	void destroy();
};