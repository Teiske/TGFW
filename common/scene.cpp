#include <iostream>
#include <cstdio>

#include <common/scene.h>

Scene::Scene() {
	// Get the sprites from the list
	spritelist.push_back(player_1);
	spritelist.push_back(player_2);
	spritelist.push_back(player_3);

	// Give the sprites a positon, scale and a rotation
	player_1->setupSprite(400, 300, 1.0f, 1.0f, 0.0f);
	player_2->setupSprite(900, 400, 1.0f, 1.0f, 0.0f);
	player_3->setupSprite(640, 360, 1.0f, 1.0f, 0.0f);

	rot_z += 0.03f;

	printf("Load scene. \n");
}

Scene::~Scene() {
	// Delete the sprites
	delete player_1;
	delete player_2;
	delete player_3;
	delete player_4;

	printf("Delete scene. \n");
}
