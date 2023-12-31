#ifndef VertexBufferLayout_h
#define VertexBufferLayout_h
#pragma once
#include <GLFW/glfw3.h>
#include <glad.h>
#include <vector>

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	
	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:   return 4;
			case GL_UNSIGNED_BYTE:  return 1;
		}
		return 0;
	}

	VertexBufferElement(unsigned int type, unsigned int count, unsigned char normalized)
		: type(type), count(count), normalized(normalized)
	{
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> _Elements;
	unsigned int _Stride;

public:
	VertexBufferLayout()
		: _Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		//static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_BYTE);
	}


	inline const std::vector<VertexBufferElement> GetElements() const& { return _Elements; }
	inline unsigned int GetStride() const { return _Stride; }
};

#endif