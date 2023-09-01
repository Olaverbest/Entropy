#include "Application.h"

#include <Entropy/Core.h>
#include <Entropy/Graphics.h>
#include <Entropy/Buffers.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#define WIDTH 1280
#define HEIGTH 720

Application::Application(const char* title, int width, int height) : Window(title, width, height) { }

int main()
{
	Application application("Entropy | Render engine", WIDTH, HEIGTH);

	Shader defaultShader("shaders/default.vert", "shaders/default.frag");

	float vertices[] = {
	 // position,      texture
		0,   0,   0.0,  0.0, 0.0,
		640, 0,   0.0,  1.0, 0.0,
		640, 225, 0.0,  1.0, 1.0,
		0,   225, 0.0,  0.0, 1.0
	};

	unsigned int indecies[] = {
		0, 1, 3,
		1, 2, 3
	};

	VertexArray vao;
	VertexBuffer vbo(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	vao.AddBuffer(vbo, layout);

	ElementBuffer ebo(indecies, 6);

	Texture logo("textures/Gorv-Productions.png");
	logo.Bind();
	defaultShader.setInt("texture1", 0);

	defaultShader.use();

	Renderer render;

	glm::mat4 proj = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(340, 240, 0));

	while (!application.closed())
	{
		application.processInput(&application);
		 
		application.background(0.1608f, 0.1608f, 0.1608f, 1.0f); //0.1608f, 0.1608f, 0.1608f, 1.0f for gorv logo
		application.clear();

		defaultShader.setMat4("model", model);
		defaultShader.setMat4("view", view);
		defaultShader.setMat4("projection", proj);

		render.Draw(vao, ebo, defaultShader);

		application.update();
	}

	return 0;
}

void Application::processInput(Window* window)
{
	if (window->getKeyPressed(GLFW_KEY_ESCAPE))
		std::cout << "PRESSED ESCAPE" << std::endl;
}