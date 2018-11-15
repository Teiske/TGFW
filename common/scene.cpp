#include <iostream>
#include <cstdio>

#include <common/scene.h>
#include <common/player.h>

Scene::Scene() {
	// Get the sprites from the list
	//spritelist.push_back(player_1);
	//spritelist.push_back(player_2);
	//spritelist.push_back(player_3);

	//spritelist.push_back(player_4);

	// Give the sprites a positon, scale and a rotation
	//player_1->setupSprite(200, 300, 1.0f, 1.0f, rot_z);
	//player_2->setupSprite(400, 300, 1.0f, 1.0f, 0.0f);
	//player_3->setupSprite(600, 300, 1.0f, 1.0f, 0.0f);

	//player_4->setupSprite(400, 300, 1.0f, 1.0f, 0.0f);


	printf("Load scene. \n");
}

void Scene::UpdateScene(Scene* scene) {

	//printf("Updating Scene. \n");
}

void Scene::addSprite(Sprite* s) {
	this->spritelist.push_back(s);
}

Scene::~Scene() {
	// Delete the sprites
	//delete player_1;
	//delete player_2;
	//delete player_3;

	//delete player_4;
	
	printf("Delete scene. \n");
}
