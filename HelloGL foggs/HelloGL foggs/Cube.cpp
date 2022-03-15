#include "Cube.h"
#include <fstream>
#include <iostream>

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y; 
		_position.z = z; 
	_rotation = 0;
	_texture = texture;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{ 

		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glPushMatrix();

	if (_position.z < 0.0f)
		_position.z += 0.1f;
	else
		_position.z = -100;

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
		glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
	}
	glEnd();
	glPopMatrix();
	}
}

void Cube::Update()
{
	_rotation += (rand() % 2 + 1);
}

void Cube::SetRotation(float rotation)
{
}
