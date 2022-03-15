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

struct Mesh
{
	Vertex* Vertices = nullptr;
	Color* Colors = nullptr;
	GLushort* Indices = nullptr;
	TexCoord* TexCoords = nullptr;
	int VertexCount = 0, ColorCount = 0, IndexCount = 0, TexCoordCount = 0;
};