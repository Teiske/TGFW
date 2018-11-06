#include <iostream>
#include <ostream>
#include <cstdio>

#include <common/scene.h>

Scene::Scene() {

	_pencils = new Entity("assets/pencils.tga");

	entityList.push_back(_pencils);

	_pencils->setupEntity(/*"assets/pencils.tga",*/ 940, 360, 1.0f, 1.0f, 0.0f);

	printf("load scene.\n");
}

Scene::~Scene() {

	delete _pencils;

	printf("delete scene.\n");
}
