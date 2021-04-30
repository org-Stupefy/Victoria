#------------------------------------------------------------
#SHADER VERTEX

#version 400 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;

out vec3 v_Color;
uniform u_ViewProjection;

void main()
{
	gl_Position = u_ViewProjection * vec4(a_Position,1.0f);
	v_Color = a_Color;
}

#------------------------------------------------------------
#SHADER FRAGMENT

#version 400 core
layout(location = 0)

in vec3 v_Color;
out vec3 Color;

void main()
{
	gl_FragColor = vec4(v_Color,1.0f);
	Color = v_Color;
}
