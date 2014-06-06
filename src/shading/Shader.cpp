#ifndef __SHADER_CPP__
#define __SHADER_CPP__

#include "Shader.h"
#include "../common/pbn.h"

Shader::Shader(GLenum type, const std::string &filename) {
    this->type = type;
    this->filename = filename;
    
    char* source = _ReadShaderSource(filename);
    printf("%s", source);
    if (source == NULL) {
        std::cerr << "Failed to read " << filename << std::endl;
        exit( EXIT_FAILURE );
    }

    shaderID = glCreateShader(type);
    
    // length arg is null since the source is null terminated
    glShaderSource( shaderID, 1, (const GLchar**) &source, NULL );
    
    _Compile();
    
    delete [] source;
}

char* Shader::_ReadShaderSource(const std::string &shaderFile) {
    FILE* fp = fopen(shaderFile.c_str(), "r");

    if ( fp == NULL ) { return NULL; }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}

void Shader::_Compile() {
    glCompileShader(shaderID);

    GLint compiledFlag;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiledFlag);
    compiled = static_cast<bool>(compiledFlag);
    if (!compiled) {
        std::cerr << filename << " failed to compile:" << std::endl;
        GLint logSize;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetShaderInfoLog(shaderID, logSize, NULL, logMsg);
        std::cerr << logMsg << std::endl;
        delete [] logMsg;

        exit( EXIT_FAILURE );
    }
}

Shader::~Shader() {
    std::cout << "Deleting shader " << shaderID << "\n";
    glDeleteShader(shaderID);
}

#endif // SHADER_CPP
