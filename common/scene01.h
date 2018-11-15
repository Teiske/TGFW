#ifndef SCENE01_H
#define SCENE01_H

#include<common/scene.h>

#include <common/player.h>

class Scene01 : public Scene {

public:
	Scene01();
	virtual ~Scene01();

private:
	Player* player;

};

#endif // !SCENE01_H
