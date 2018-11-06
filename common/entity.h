#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <GL/glew.h>

class Entity{
	public:
		Entity(const std::string image_path);
		virtual ~Entity();

		void setupEntity(/*const std::string image_path,*/ float px, float py, float uvwidth, float uvheight, float rot);

		GLuint texture() { return _texture; };
		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint uvbuffer() { return _uvbuffer; };

		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

		//Float used for setting the position, scale and rotation
		float posx() { return _posx; };
		float posy() { return _posy; };
		float scalex() { return _scalex; };
		float scaley() { return _scaley; };
		float rot() { return _rot; };

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		unsigned int _width;
		unsigned int _height;

		float _posx;
		float _posy;
		float _scalex;
		float _scaley;
		float _rot;
};

#endif /* ENTITY_H */
