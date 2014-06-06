#ifndef __SHADERPROGRAM_H__
#define __SHADERPROGRAM_H__

#include "../common/pbn.h"
#include "Shader.h"

class ShaderProgram {

    public:
        ShaderProgram(Shader *vertexShader, Shader *fragmentShader);
        
        GLuint GetID() { return programID; }
        void UseProgram();
        
        ~ShaderProgram();
        
    private:
        GLuint programID;
        Shader* vert;
        Shader* frag;
};

#endif // SHADERPROGRAM
