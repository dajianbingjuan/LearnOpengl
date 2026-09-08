#include "EBO.h"

EBO::EBO()
{
	glGenBuffers(1, &m_id);
    EBO::bindEBO();
}

EBO::~EBO()
{
	EBO::destroy();
}

void EBO::bindEBO()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void EBO::unbindEBO()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void EBO::setEBOdata(unsigned int size, unsigned int data[], unsigned int mode)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, mode);
}

void EBO::destroy()
{
    if (m_id != 0)
    {
        glDeleteBuffers(1, &m_id);
        m_id = 0;
    }
}
