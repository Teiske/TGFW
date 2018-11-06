#ifndef SCENE_H
#define SCENE_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/entity.h>

class Scene {
	public:
		Scene();
		virtual ~Scene();

		std::vector<Entity*> entityList;

		Entity * pencils() { return _pencils; };
		//Entity * player() { return _player; };
		//Entity * uvmapping() { return _uvmapping; };

	private:

		Entity * _pencils;
		//Entity * _player = new Entity("assets/Player_Textures/Spaceship_1/Spaceship_2_Player.tga");
		//Entity * _uvmapping = new Entity("assets/uv_mapping_grid_by_cymae.tga");

};

#endif
