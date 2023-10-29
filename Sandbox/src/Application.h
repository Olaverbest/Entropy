#ifndef Application_h
#define Application_h

#pragma once

#include "../../Entropy/src/Graphics/Window.h"
#include "../../Entropy/src/Graphics/Camera.h"

class Application : public Window
{
public:
	Application(const char* title, int width, int height);

	virtual void processInput(Window* window, Camera* camera);
};
#endif

Application::Application(const char* title, int width, int height) : Window(title, width, height) { }