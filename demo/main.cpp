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


//std::string readFile(const char *filePath) {
//	std::string content;
//	std::ifstream fileStream(filePath, std::ios::in);
//
//	if (!fileStream.is_open()) {
//		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
//		return "";
//	}
//
//	std::string line = "";
//	while (!fileStream.eof()) {
//		std::getline(fileStream, line);
//		content.append(line + "\n");
//	}
//
//	fileStream.close();
//	return content;
//}

int main(void) {
	Renderer renderer(800, 600);

	static const GLfloat g_vertex_buffer_data[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	GLuint programID = LoadShaders("shaders/vertex.vert", "shaders/fragment.frag");

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);

	// 1. bind Vertex Array Object
	glBindVertexArray(VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	//Sprite* pencils = new Sprite("assets/pencils.tga");
	//Sprite* kingkong = new Sprite("assets/kingkong.tga");
	//Sprite* rgba = new Sprite("assets/rgba.tga");
	//float rot_z = 0.0f;

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window());

		// 4. draw the object
		glUseProgram(programID);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		//renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		//renderer.renderSprite(kingkong, 900, 400, 1.0f, 1.0f, 0.0f);
		//renderer.renderSprite(rgba, renderer.width()/2, renderer.height()/2, 3.0f, 3.0f, rot_z);
		//rot_z += 0.03f;

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0 );

	//delete pencils;
	//delete kingkong;
	//delete rgba;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
