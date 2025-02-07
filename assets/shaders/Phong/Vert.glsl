#version 460 core
			
layout(location = 0) in vec3 a_vertexPosition;
layout(location = 1) in vec3 a_vertexNormal;
layout(location = 2) in vec2 a_texCoord;

out vec4 fragmentPosLightSpace;
out vec3 fragmentPos;
out vec3 normal;
out vec2 texCoord;

layout (std140, binding = 0) uniform b_camera
{
	uniform mat4 u_view;
	uniform mat4 u_projection;
	uniform vec3 u_viewPos;
};

uniform mat4 u_model;
uniform mat4 u_lightSpaceTranform;

void main()
{
	fragmentPos = vec3(u_model * vec4(a_vertexPosition, 1.0));
	normal = normalize(mat3(transpose(inverse(u_model))) * a_vertexNormal);
	fragmentPosLightSpace = u_lightSpaceTranform * vec4(fragmentPos, 1.0);
	texCoord = a_texCoord;
	gl_Position = u_projection * u_view * vec4(fragmentPos,1.0);
}