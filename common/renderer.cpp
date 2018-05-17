#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <common/camera.h>
#include <common/renderer.h>
#include <common/shader.h>

Renderer::Renderer(/*unsigned int w, unsigned int h*/) {
	_window_width = 800;
	_window_height = 600;

	this->init();
}

Renderer::~Renderer() {
	// Cleanup VBO and shader
	glDeleteProgram(_programID);
}

int Renderer::init() {

	// Initialise GLFW
	if(!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Open a window and create its OpenGL context
	_window = glfwCreateWindow( _window_width, _window_height, "TGFW", NULL, NULL);
	if(_window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// Create and compile our GLSL program from the shaders
	//GLuint _programID = loadShaders("shaders/vertex.vert", "shaders/fragment.frag");

	_projectionMatrix = glm::ortho(0.0f, (float)_window_width, (float)_window_height, 0.0f, 0.1f, 100.0f);

	// Use our shader
	glUseProgram(_programID);

	return 0;
}

void Renderer::renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot) {
	glm::mat4 viewMatrix  = getViewMatrix(); // get from Camera (Camera position and direction)
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(px, py, 0.0f));
	glm::mat4 rotationMatrix	= glm::eulerAngleYXZ(0.0f, 0.0f, rot);
	glm::mat4 scalingMatrix	 = glm::scale(glm::mat4(1.0f), glm::vec3(sx, sy, 1.0f));

	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = _projectionMatrix * viewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint matrixID = glGetUniformLocation(_programID, "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sprite->texture());
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	GLuint textureID  = glGetUniformLocation(_programID, "myTextureSampler");
	glUniform1i(textureID, 0);

	// 1st attribute buffer : vertices
	GLuint vertexPosition_modelspaceID = glGetAttribLocation(_programID, "vertexPosition_modelspace");
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexbuffer());
	glVertexAttribPointer(
		vertexPosition_modelspaceID,  // The attribute we want to configure
		3,							  // size : x+y+z => 3
		GL_FLOAT,					  // type
		GL_FALSE,					  // normalized?
		0,							  // stride
		(void*)0					  // array buffer offset
	);

	// 2nd attribute buffer : UVs
	GLuint vertexUVID = glGetAttribLocation(_programID, "vertexUV");
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, sprite->uvbuffer());
	glVertexAttribPointer(
		vertexUVID,				      // The attribute we want to configure
		2,							  // size : U+V => 2
		GL_FLOAT,					  // type
		GL_FALSE,					  // normalized?
		0,							  // stride
		(void*)0					  // array buffer offset
	);

	// Draw the triangles !
	glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

	glDisableVertexAttribArray(vertexPosition_modelspaceID);
	glDisableVertexAttribArray(vertexUVID);
}

void Renderer::renderScene(Scene* scene) {
	//Clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Get camera view
	computeMatricesFromInputs(_window);

	glfwSwapBuffers(_window);
	glfwPollEvents();
}
