#ifndef Application_h

#pragma once

#include "../../Entropy/src/Graphics/Window.h"

class Application : public Window
{
public:
	Application(const char* title, int width, int height);

	void processInput(Window* window) override;
};

#endif
