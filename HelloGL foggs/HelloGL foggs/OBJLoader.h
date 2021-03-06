#pragma once
#include <Windows.h>
#include <gl/GL.h>            // openGL
#include <gl/GLU.h>            // OpenGL Utils
#include "GL\freeglut.h"    // Freeglut lib
#include "Structures.h"
#include <string>
#include <vector>

namespace OBJLoader
{
	OBJ* Load(char* path);
};

