#include "ShaderProgram.h"
#include "Shader.h"

ShaderProgram::ShaderProgram(Shader *vertexShader, Shader *fragmentShader) {
    programID = glCreateProgram();
    glAttachShader(programID, vertexShader->GetID());
    glAttachShader(programID, fragmentShader->GetID());
    glLinkProgram(programID);
    
    vert = vertexShader;
    frag = fragmentShader;
}

void ShaderProgram::UseProgram() {
    glUseProgram(programID);
}

ShaderProgram::~ShaderProgram() {
    glUseProgram(0);

    glDetachShader(programID, vert->GetID());
    glDetachShader(programID, frag->GetID());

    glDeleteProgram(programID);
}
