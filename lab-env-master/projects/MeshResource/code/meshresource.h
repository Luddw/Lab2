#pragma once

#include <vector>
#include <GL/glew.h>

/** A class that represents a Mesh in OpenGL*/
class MeshResource
{
public:
	/** 
	* Custom constructor for creating a mesh
	* @param verts: a vector containing GLfloats for the setup of vertexbuffer and vertexattribs
	* @param indices: a vector containing GLuints for the setup of indexbuffer
	*/
	MeshResource(std::vector<GLfloat> verts, std::vector<GLuint> indices);
	/** stores each vertices value for use in the mesh methods */
	std::vector<GLfloat> verts;
	/** stores each indices value for use in the mesh methods */
	std::vector<GLuint> indices;

	/** method to bind the Vertex array object*/
	void BindVao();
	/** method to bind the Vertex buffer object*/
	void BindVbo();
	/** method to bind the Index buffer object */
	void BindIbo();

	/** 
	* Generates buffers and binds them, Buffers the data to the gpu.
	* Enables Vertex attributes, position and colour for each vertex.
	*/
	void SetupVertexBuffer();
	/** Generates buffers and binds them, Buffers the data to the gpu. */
	void SetupIndexBuffer();
	/** Generates A vertex array, and binds it. */
	void SetupVertexArray();
	

private:
	/** Unsigned ints used in openGL to represent each object */
	GLuint vao,vbo,ibo;
	
};