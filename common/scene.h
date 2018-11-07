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

#include <common/sprite.h>

class Scene {
	public:
		Scene();
		virtual ~Scene();

		std::vector<Sprite*> spritelist;		

	private:
		Sprite* player_1 = new Sprite("assets/Player_Textures/Spaceship_1/Spaceship_1_Player.tga");
		Sprite* player_2 = new Sprite("assets/Player_Textures/Spaceship_1/Spaceship_2_Player.tga");
		Sprite* player_3 = new Sprite("assets/Player_Textures/Spaceship_1/Spaceship_3_Player.tga");
		Sprite* player_4 = new Sprite("assets/Player_Textures/Spaceship_1/Spaceship_4_Player.tga");

		float rot_z = 0.0f;
};

#endif
