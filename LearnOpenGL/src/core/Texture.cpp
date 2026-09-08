#include "Texture.h"

Texture::Texture(const char* texturepath)
{

	

	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned int internalFormat = 0, format = 0;
	unsigned char* data = stbi_load(texturepath, &width, &height, &nrChannels, 0);
	if (nrChannels == 4)
	{
		internalFormat = GL_RGBA;
		format = GL_RGBA;
	}
	else if (nrChannels == 3)
	{
		internalFormat = GL_RGB;
		format = GL_RGB;
	}

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

}
Texture::~Texture()
{

}
void Texture::setFlip(bool n)
{
	stbi_set_flip_vertically_on_load(n);
}

void Texture::activeTexture(unsigned int texureslot)
{
	glActiveTexture(texureslot);
	glBindTexture(GL_TEXTURE_2D, m_id);

}

