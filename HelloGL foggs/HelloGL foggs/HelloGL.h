#pragma once
#define REFRESHRATE 16
#include <Windows.h> // required for OpenGl on windows
#include <gl/GL.h> //OpenGl
#include <gl/GLU.h> //OpenGl utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"

class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void InitObjects();
	void InitGL(int argc, char* argv[]);
private:
	float rotation;
	Camera* camera;
	SceneObject* objects[1000];

};

