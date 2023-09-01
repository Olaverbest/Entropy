#ifndef Renderer_h
#define Renderer_h
#pragma once

#include <glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "../Buffers/VertexArray.h"
#include "../Buffers/ElementBuffer.h"
#include "Shaders/Shader.h"

class Renderer
{
public:
	void Draw(const VertexArray& va, const ElementBuffer& eb, const Shader& shader) const;
};

#endif