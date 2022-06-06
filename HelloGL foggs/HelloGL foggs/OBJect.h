#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"
#include "Cube.h"

class OBJect : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
	Material* _material;

public:
	OBJect(OBJ* obj, Texture2D* texture, float x, float y, float z);
	~OBJect();

	void Method();
	void Draw();
	void Update();
	void SetRotation(float rotation);
};
