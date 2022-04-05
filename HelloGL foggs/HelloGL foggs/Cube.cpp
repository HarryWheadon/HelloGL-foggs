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
	_material = new Material();
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Indices != nullptr && _mesh->TexCoords != nullptr)
	{ 
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glEnable(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		Method();

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

	for (int i = 0; i < 36; i++)
	{
		glTexCoord2f(_mesh->TexCoords[_mesh->Indices[i]].u, _mesh->TexCoords[_mesh->Indices[i]].v);
		glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		glNormal3f(_mesh->Normals[i].x, _mesh->Normals[i].y, _mesh->Normals[i].z);
	}

	glEnd();
	glPopMatrix();
	}
}

void Cube::Method()
{
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

}

void Cube::Update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	_rotation += (rand() % 2 + 1);
	//aa++;
	//std::cout << aa << std::endl;
	//std::cout << cos(aa) << std::endl;
	//_rotation += (float)cos(pow(aa, atan(1)*4));
}

void Cube::SetRotation(float rotation)
{
}
