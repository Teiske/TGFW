#include <common/scene01.h>

Scene01::Scene01() {
	player = new Player();

	player->setupSprite(400, 300, 1.0f, 1.0f, 0.0f);

	this->addSprite(player);
}

Scene01::~Scene01() {

	delete player;
}
