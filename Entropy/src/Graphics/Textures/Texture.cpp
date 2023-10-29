#include "enpch.h"
#include "Texture.h"

Texture::Texture(const std::string& path)
	: _TextureID(0), _FilePath(path), _LocalBuffer(nullptr), _Width(0), _Heigth(0), _BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	_LocalBuffer = stbi_load(path.c_str(), &_Width, &_Heigth, &_BPP, 4);

	glGenTextures(1, & _TextureID);
	glBindTexture(GL_TEXTURE_2D, _TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_NEAREST
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); // GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER); // GL_REPEAT

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _Width, _Heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, _LocalBuffer); // GL_RGBA8?
	glBindTexture(GL_TEXTURE_2D, 0);

	if (_LocalBuffer)
		stbi_image_free(_LocalBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &_TextureID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _TextureID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

inline int Texture::GetTextureID() const
{
	return _TextureID;
}
