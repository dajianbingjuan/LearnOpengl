#shader vertex
#version 330 core  
layout (location=0) in vec3 position;  
layout (location=1) in vec2 texcoord;  

 uniform mat4 model;
 uniform mat4 projection;
 uniform mat4 view;

out vec2 TexCoord;
void main()  
{  
	gl_Position=projection * view * model *vec4(position,1.0f);  
	TexCoord=texcoord;
};

#shader fragment
#version 330 core  
out vec4 FragColor;

in vec2 TexCoord;

 uniform sampler2D texture1;
 uniform sampler2D texture2;

void main()
{
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}