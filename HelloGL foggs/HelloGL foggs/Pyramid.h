#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"
#include "Cube.h"

class Pyramid : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
	Material* _material;

public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	virtual void Update();
	virtual void Draw();
};

