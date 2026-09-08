#pragma once
#include<glad/glad.h>
class EBO {
private:
	unsigned int m_id;

public:
	EBO();
	~EBO();
	void bindEBO();
	void unbindEBO();
	void setEBOdata(unsigned int size,unsigned int data[], unsigned int mode);
	void destroy();
};