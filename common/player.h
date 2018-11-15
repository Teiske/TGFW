#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
#include <common/renderer.h>

class Player : public Sprite {
public:
	
	Player();

	virtual void UpdatePlayer(GLFWwindow* window);

	virtual ~Player();

protected:

private:
	glm::vec3 position;
	
	float speed = 300.0f; // 300 units / second

};

#endif // !PLAYER_H
