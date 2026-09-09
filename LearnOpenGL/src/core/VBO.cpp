#include "VBO.h"

VBO::VBO()
{
	glGenBuffers(1, &m_id);
    VBO::bindVBO();
}

VBO::~VBO()
{
	VBO::destroy();
}

void VBO::bindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VBO::unbindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
                                        //数组内存大小    //数组            //绘制模式
void VBO::setVBOdata(unsigned int size, float data[], unsigned int mode)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, mode);
}

void VBO::destroy()
{
    if (m_id != 0)
    {
        glDeleteBuffers(1, &m_id);
        m_id = 0;
    }
}
