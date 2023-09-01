#ifndef ElementBuffer_h
#define ElementBuffer_h
#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>

class ElementBuffer
{
private:
	unsigned int _BufferID;
	unsigned int _Count;
public:
	ElementBuffer(const unsigned int* data, unsigned int count);
	~ElementBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return _Count; }
};

#endif
