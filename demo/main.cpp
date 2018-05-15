// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>

const char* vertexShaderSource = /*"shaders/vertex.vert";*/
	"#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";

int main(void) {
	Renderer renderer(1280, 720);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	// 1. bind Vertex Array Object
	glBindVertexArray(VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	/*Sprite* pencils = new Sprite("assets/pencils.tga");
	Sprite* kingkong = new Sprite("assets/kingkong.tga");
	Sprite* rgba = new Sprite("assets/rgba.tga");

	float rot_z = 0.0f;*/

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window());

		// ..:: Drawing code (in render loop) :: ..
		// 4. draw the object
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		/*renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(kingkong, 900, 400, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(rgba, renderer.width()/2, renderer.height()/2, 3.0f, 3.0f, rot_z);
		rot_z += 0.03f;*/

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0 );

	/*delete pencils;
	delete kingkong;
	delete rgba;*/

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
