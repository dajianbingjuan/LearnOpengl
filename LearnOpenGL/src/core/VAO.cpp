#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &m_id);
}

VAO::~VAO()
{
	if (m_id != 0) {
		glDeleteVertexArrays(1, &m_id);
	}
}

void VAO::bindVAO()
{
	glBindVertexArray(m_id);
}

void VAO::unbindVAO()
{
	glBindVertexArray(0);
}

void VAO::setAttribPointer(int index, int size, float type,bool normalized,unsigned int stride,const void* offset)
{
	glVertexAttribPointer(index, size, type, normalized, stride, offset);

}

void VAO::enableAttrib(int index)
{
	glEnableVertexAttribArray(index);
}

void VAO::diableAttrib( int index)
{
	glDisableVertexAttribArray(0);
}
