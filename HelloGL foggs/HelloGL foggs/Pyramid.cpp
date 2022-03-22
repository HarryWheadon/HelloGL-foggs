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
	if (_mesh->Vertices != nullptr && _mesh->Indices != nullptr)
	{
		_material = new Material();
		_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
		_material->Ambient.w = 1.0;
		_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
		_material->Diffuse.w = 1.0;
		_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
		_material->Specular.w = 1.0;
		_material->Shininess = 100.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_material->Diffuse.x));
		glLightfv(GL_LIGHT0, GL_SPECULAR, &(_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

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
			glTexCoord2f(_mesh->TexCoords[_mesh->Indices[i]].u, _mesh->TexCoords[_mesh->Indices[i]].v);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
			/*glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);*/
		}
		glEnd();
		glPopMatrix();
	}
}

void Pyramid::Update()
{
	_rotation += (rand() % 2 + 1);
}