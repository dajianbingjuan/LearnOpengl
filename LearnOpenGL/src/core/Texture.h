#pragma once
#include<glad/glad.h>
#include "../include/stb_image.h"
#include<iostream>
class Texture {
private:
	unsigned int m_id;

public:
	Texture(const char* texturepath);
	~Texture();
	static void setFlip(bool n);
	void activeTexture(unsigned int texureslot);


};