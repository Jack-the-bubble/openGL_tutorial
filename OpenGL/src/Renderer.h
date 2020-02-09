#pragma once

#include <GL/glew.h>

#define ASSERT(x) if (!(x))  __debugbreak()
#define GLcall(x) GLClearError();\
	x;\
	ASSERT(GLCheckError(#x, __FILE__, __LINE__))

void GLClearError();

bool GLCheckError(const char* function, const char* file, int line);