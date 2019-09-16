#include "meshresource.h"


MeshResource::MeshResource(std::vector<GLfloat> verts, std::vector<GLuint> indices)
{
    this->verts = verts;
    this->indices = indices;
}


void MeshResource::SetupIndexBuffer()
{
    glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    GLuint buffer_size = indices.size() *sizeof(GLuint);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,buffer_size, &indices[0], GL_STATIC_DRAW);
}

void MeshResource::SetupVertexBuffer()
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

    GLuint buffer_size = verts.size() * sizeof(GLfloat);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, &verts[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 7*sizeof(GLfloat), NULL);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 7*sizeof(GLfloat), (void*)12);

}
void MeshResource::SetupVertexArray()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindVertexArray(0);
}

void MeshResource::BindVao()
{
    glBindVertexArray(vao);
}

void MeshResource::BindIbo()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}
void MeshResource::BindVbo()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

