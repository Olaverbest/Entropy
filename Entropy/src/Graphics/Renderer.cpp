#include "enpch.h"
#include "Renderer.h"

void Renderer::Draw(const VertexArray& va, const ElementBuffer& eb, const Shader& shader) const
{
	shader.use();

	va.Bind();
	eb.Bind();

	glDrawElements(GL_TRIANGLES, eb.GetCount(), GL_UNSIGNED_INT, nullptr);
}