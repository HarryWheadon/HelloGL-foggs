#include "OBJect.h"
#include <fstream>
#include <iostream>

OBJect::OBJect(OBJ* obj, Texture2D* texture, float x, float y, float z) : SceneObject(nullptr, obj, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;
	_texture = texture;
	_material = new Material();
}

OBJect::~OBJect()
{
}


void OBJect::Method()
{
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

}

void OBJect::Draw()
{


		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		Method();

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_material->Diffuse.x));
		glLightfv(GL_LIGHT0, GL_SPECULAR, &(_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 0.0f, 0.0f, -1.0f);

		glBegin(GL_TRIANGLES);
		for (size_t i = 0; i < _obj->vertices.size(); i++)
		{
			glTexCoord2f(_obj->texCoord[i].u, _obj->texCoord[i].v);
			glVertex3f(_obj->vertices[i].x, _obj->vertices[i].y, _obj->vertices[i].z);
			glNormal3f(_obj->normals[i].x, _obj->normals[i].y, _obj->normals[i].z);
		}
		glEnd();
}

void OBJect::Update()
{
	_rotation += (rand() % 2 + 1);
}

void OBJect::SetRotation(float rotation)
{
}
