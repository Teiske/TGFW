#include <iostream>
#include <cstdio>

#include <common/scene.h>
#include <common/renderer.h>

Scene::Scene() {

	printf("load scene.\n");
}

Scene::~Scene() {
	glDeleteProgram(programID);

	printf("delete scene");
}
