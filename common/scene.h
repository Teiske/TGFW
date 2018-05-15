#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <glfw3.h>

#include <common/shader.h>

class Scene {
	public:
		Scene();
		virtual ~Scene();

		GLuint programID = LoadShaders("shaders/vertex.vert", "shaders/fragment.frag");

	private:

};

#endif