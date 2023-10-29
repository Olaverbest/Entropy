#ifndef Texture_h
#define Texture_h
#pragma once

#include "../Renderer.h"
#include <string>
#include <stb_image.h>

class Texture
{
private:
	unsigned int _TextureID;
	std::string _FilePath;
	unsigned char* _LocalBuffer;
	int _Width, _Heigth, _BPP;

public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return _Width; }
	inline int GetHeigth() const { return _Heigth; }

	inline int GetTextureID() const;
};

#endif