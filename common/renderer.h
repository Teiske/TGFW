#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/entity.h>
#include <common/scene.h>

class Renderer {
	public:
		Renderer(/*unsigned int w, unsigned int h*/);
		virtual ~Renderer();

		void renderScene(Scene* scene);
		void renderEntity(Entity* entity/*, float px, float py, float sx, float sy, float rot*/);
		
		GLFWwindow* window() { return _window; };

		unsigned int width() { return _window_width; };
		unsigned int height() { return _window_height; };

	private:
		int init();

		GLFWwindow* _window;
		unsigned int _window_width;
		unsigned int _window_height;

		GLuint _programID;

		glm::mat4 _projectionMatrix;
};

#endif /* RENDERER_H */
