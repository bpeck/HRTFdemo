#ifndef __SHADER_H__
#define __SHADER_H__

#include "../common/pbn.h"

class Shader {

    public:
        Shader(GLenum type, const std::string &filename);
        GLuint GetID() { return shaderID; }
        GLenum GetType() { return type; }
        bool IsCompiled() { return compiled; }
        
        ~Shader();

    private:
        std::string filename;
        GLuint shaderID;
        GLenum type;
        bool compiled;
        
        char* _ReadShaderSource(const std::string &shaderFile);
        void _Compile();
};

#endif // SHADER_H
