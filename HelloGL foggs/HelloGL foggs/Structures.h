#pragma once
#include <Windows.h> // required for OpenGl on windows
#include <gl/GL.h> //OpenGl
#include <gl/GLU.h> //OpenGl utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u;
	GLfloat v;
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;
};

struct Lighting
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

struct Material
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
};
struct Mesh
{
	Vertex* Vertices = nullptr;
	Vector3* Normals;
	TexCoord* TexCoords = nullptr;
	GLushort* Indices = nullptr;
	int VertexCount = 0, NormalCount = 0, IndexCount = 0, TexCoordCount = 0;
};