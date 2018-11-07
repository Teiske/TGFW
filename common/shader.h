#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glfw3.h>

class Shader {
public:
	Shader();
	~Shader();

	GLuint LoadShaders(
		const char* vertex_file_path,
		const char* fragment_file_path
	);

private:

};

#endif
