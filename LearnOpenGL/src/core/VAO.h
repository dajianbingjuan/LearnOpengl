#pragma once
#include<glad/glad.h>


class VAO {
private:
	unsigned int m_id;
public:
	VAO();
	~VAO();

	void bindVAO();
	void unbindVAO();
	void setAttribPointer(int index, int size, float type, bool normalized, unsigned int stride, const void* offset);
	void enableAttrib(int index);
	void diableAttrib(int index);


};