#SHADER VERTEX
#version 400 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normals;

out vec3 v_FragPosition;
out vec3 v_Normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	
}

#SHADER FRAGMENT
#version 400 core

out vec4 FragColor;



void main()
{
	//Ambient

	//Diffuse

	//Specular

	vec3 result = (ambient + diffuse + specular) * lightColor;
	FragColor = vec4(result,1.0);
}
