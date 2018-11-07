#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>

class Sprite {
	public:
		Sprite(std::string image_path);
		virtual ~Sprite();

		void setupSprite(/*const std::string image_path,*/ float px = 0.0f, float py = 0.0f, float sx = 1.0f, float sy = 1.0f, float rot = 0.0f);

		GLuint texture() { return _texture; };
		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint uvbuffer() { return _uvbuffer; };

		float px() { return _px; };
		float py() { return _py; };
		float sx() { return _sx; };
		float sy() { return _sy; };
		float rot() { return _rot; };
		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		float _px;
		float _py;
		float _sx;
		float _sy;
		float _rot;

		unsigned int _width;
		unsigned int _height;
};

#endif /* SPRITE_H */
