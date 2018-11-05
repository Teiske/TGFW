#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <glfw3.h>

#include <iostream>
#include <vector>

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
