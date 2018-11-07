// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/shader.h>

int main(void) {
	Renderer renderer(800, 600);

	Scene* myScene = new Scene();

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render the scene
		renderer.renderScene(myScene);

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0 );

	// Delete the scene
	delete myScene;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
