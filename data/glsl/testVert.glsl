#version 400

layout(location=0) in vec3 in_Position;
layout(location=1) in vec3 in_Normal;
layout(location=2) in vec2 in_Tex;
layout(location=3) in float in_Face;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 ex_Normal;
out vec2 ex_Tex;
out float ex_Face;

void main(void)
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
    ex_Normal = in_Normal;
    ex_Tex = in_Tex;
    ex_Face = in_Face;
}
