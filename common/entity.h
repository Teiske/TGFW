#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>

class Entity {
public:
	Entity();

	void Setup(std::string image_path);

	virtual void UpdateEntity(float deltaTime) = 0;
	virtual ~Entity();

	Sprite* sprite() { return _sprite; };


private:

	Sprite * _sprite;

};

#endif // !ENTITY_H
