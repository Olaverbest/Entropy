#include "enpch.h"
#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(const unsigned int* data, unsigned int count)
    : _Count(count)
{
    glGenBuffers(1, &_BufferID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _BufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer()
{
    glDeleteBuffers(1, &_BufferID);
}

void ElementBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _BufferID);
}

void ElementBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
