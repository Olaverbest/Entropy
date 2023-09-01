#ifndef Window_h
#define Window_h

#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window
{
private:
	const char* _title;
	unsigned int _width, _heigth;
	GLFWwindow* _window;
	bool _closed;

	bool _Keys[MAX_KEYS];
	bool _MouseButtons[MAX_BUTTONS];
	double mx, my;
public:
	Window(const char* title, int width, int height);
	~Window();

	void clear();
	void background(float r, float g, float b , float a);
	void update();
	bool closed();

	GLFWwindow* get() { return _window; }

	virtual void processInput(Window* window);
	//GLFWwindow* window

	bool getKeyPressed(unsigned int keycode) const;
	bool getMouseButtonPressed(unsigned int button) const;
	void getMousePosition(double& x, double& y) const;
private:
	bool init();

	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif