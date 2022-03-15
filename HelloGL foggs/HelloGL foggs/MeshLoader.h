#pragma once
#include <Windows.h>
#include <gl/GL.h>            // openGL
#include <gl/GLU.h>            // OpenGL Utils
#include "GL\freeglut.h"    // Freeglut lib
#include "Structures.h"

namespace MeshLoader
{
	Mesh* Load(char* path);
};

