#version 400

in vec3 ex_Normal;
in vec2 ex_Tex;
in float ex_Face;
out vec4 out_Color;

void main(void)
{    
    float f = ex_Face;
    out_Color = vec4(1.0 - (f/8.0), f/8.0, 0.0, 1.0);
}
