#include <Entropy/Core.h>
#include <Entropy/Graphics.h>
#include <Entropy/Buffers.h>
#include <Entropy/Math.h>

#include "Graphics/Camera.h"

#define WIDTH 1280
#define HEIGTH 720

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = WIDTH / 2.0f;
float lastY = HEIGTH / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
	Application application("Entropy | Render engine", WIDTH, HEIGTH);
	Shader defaultShader("shaders/default.vert", "shaders/default.frag");

	glfwSetCursorPosCallback(application.get(), mouse_callback);
	glfwSetInputMode(application.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	/*float vertices[] = {
		// position           texture
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	};

	unsigned int indices[] = {
		0, 1, 2,  // Front face
		0, 2, 3,
		1, 5, 6,  // Right face
		1, 6, 2,
		4, 5, 1,  // Bottom face
		4, 1, 0,
		3, 2, 6,  // Top face
		3, 6, 7,
		4, 0, 3,  // Left face
		4, 3, 7,
		4, 7, 6,  // Back face
		4, 6, 5
	};

	VertexArray vao;
	VertexBuffer vbo(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	vao.AddBuffer(vbo, layout);

	ElementBuffer ebo(indices, 36);

	Texture logo("textures/test.png");
	logo.Bind();
	defaultShader.setInt("texture1", 0);*/
	defaultShader.use();

	stbi_set_flip_vertically_on_load(1);

	Model backpack("models/backpack/backpack.obj");
	glm::vec3 backpackPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 backpackScale = glm::vec3(1.0f, 1.0f, 1.0f);

	Renderer render;

	while (!application.closed())
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Pre-frame
		application.processInput(&application, &camera);
		application.background(0.1608f, 0.1608f, 0.1608f, 1.0f);
		application.clear();

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGTH, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		defaultShader.setMat4("projection", projection);
		defaultShader.setMat4("view", view);

		// Drawing
		//render.Draw(vao, ebo, defaultShader);
		render.DrawModel(backpack, defaultShader, backpackPosition, backpackScale);

		// Update
		application.update();
	}

	return 0;
}

void Application::processInput(Window* window, Camera* camera)
{
	if (window->getKeyPressed(GLFW_KEY_1))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (window->getKeyPressed(GLFW_KEY_2))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (window->getKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetInputMode(window->get(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		//std::cout << "PRESSED ESCAPE" << std::endl;

	if (window->getKeyPressed(GLFW_KEY_W))
		camera->ProcessKeyboard(FORWARD, deltaTime);
	if (window->getKeyPressed(GLFW_KEY_A))
		camera->ProcessKeyboard(LEFT, deltaTime);
	if (window->getKeyPressed(GLFW_KEY_S))
		camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (window->getKeyPressed(GLFW_KEY_D))
		camera->ProcessKeyboard(RIGHT, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}