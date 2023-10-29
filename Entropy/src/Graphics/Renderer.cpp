#include "enpch.h"
#include "Renderer.h"

void Renderer::Draw(const VertexArray& va, const ElementBuffer& eb, const Shader& shader) const
{
	shader.use();

	va.Bind();
	eb.Bind();

	glDrawElements(GL_TRIANGLES, eb.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::DrawModel(Model& model, Shader& shader, glm::vec3 position, glm::vec3 scale)
{
	glm::mat4 mModel = glm::mat4(1.0f);
	mModel = glm::translate(mModel, position);
	mModel = glm::scale(mModel, scale);
	shader.setMat4("model", mModel);
	model.ModelDraw(shader);
}