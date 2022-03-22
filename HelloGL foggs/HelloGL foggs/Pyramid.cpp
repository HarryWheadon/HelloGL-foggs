#include "Pyramid.h"
#include <iostream>
#include <fstream>
using namespace std;

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;

}

Pyramid::~Pyramid()
{
}

void Pyramid::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glPushMatrix();

		if (_position.z < 0.0f)
			_position.z += 0.1f;
		else
			_position.z = -100;

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 0.0f, 0.0f, -1.0f);
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 18; i++)
		{
			glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}
		glEnd();
		glPopMatrix();
	}
}

void Pyramid::Update()
{
	_rotation += (rand() % 2 + 1);
}