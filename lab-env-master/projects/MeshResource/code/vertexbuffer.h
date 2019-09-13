#pragma once
#include <GL/glew.h>
class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind();
	void Unbind();
private:
	unsigned int id;
};

