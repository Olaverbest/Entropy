#ifndef Renderer_h
#define Renderer_h
#pragma once

#include <glad.h>
#include <GLFW/glfw3.h>

#include <Entropy/Math.h>

#include <iostream>

#include "../Buffers/VertexArray.h"
#include "../Buffers/ElementBuffer.h"
#include "Shaders/Shader.h"
#include "Models/Model.h"

class Renderer
{
public:
	void Draw(const VertexArray& va, const ElementBuffer& eb, const Shader& shader) const;
	void DrawModel(Model& model, Shader& shader, glm::vec3 position, glm::vec3 scale);
};

#endif