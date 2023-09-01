#ifndef VertexBuffer_h
#define VertexBuffer_h
#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
private:
	unsigned int _BufferID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

#endif
