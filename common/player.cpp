#include <common/player.h>

Player::Player() {
	this->position = glm::vec3(0, 0, 0);
	this->Setup("assets/Player_Textures/Spaceship_1/Spaceship_2_Player.tga");
}

void Player::UpdatePlayer(GLFWwindow* window) {
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);

	// Move up
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		this->position += up * deltaTime * speed;
		printf("Arrow up pressed. \n");
	}
	// Move down
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		this->position -= up * deltaTime * speed;
		printf("Arrow down pressed. \n");
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		this->position += right * deltaTime * speed;
		printf("Arrow right pressed. \n");
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		this->position -= right * deltaTime * speed;
		printf("Arrow left pressed. \n");
	}
}


Player::~Player() {

}
