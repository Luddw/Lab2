//------------------------------------------------------------------------------
// Lab2.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab2.h"
#include <cstring>
#include "meshresource.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include "matlib.h"
	


const GLchar* vs =
"#version 430\n"
"layout(location=0) in vec3 pos;\n"
"layout(location=1) in vec4 color;\n"
"layout(location=0) uniform mat4 rotmat;\n"
"layout(location=0) out vec4 Color;\n"
"void main()\n"
"{\n"
"	gl_Position = rotmat*vec4(pos, 1);\n"
"	Color = color;\n"
"}\n";

const GLchar* ps =
"#version 430\n"
"layout(location=0) in vec4 color;\n"
"out vec4 Color;\n"
"void main()\n"
"{\n"
"	Color = color;\n"
"}\n";

using namespace Display;
namespace Example
{

//------------------------------------------------------------------------------
/**
*/
Lab2::Lab2()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
Lab2::~Lab2()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
Lab2::Open()
{
	App::Open();
	this->window = new Display::Window;
	window->SetKeyPressFunction([this](int32, int32, int32, int32)
	{
		this->window->Close();
	});


	if (this->window->Open())
	{
		// set clear color to gray
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// setup vertex shader
		this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLint length = static_cast<GLint>(std::strlen(vs));
		glShaderSource(this->vertexShader, 1, &vs, &length);
		glCompileShader(this->vertexShader);

		// get error log
		GLint shaderLogSize;
		glGetShaderiv(this->vertexShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->vertexShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// setup pixel shader
		this->pixelShader = glCreateShader(GL_FRAGMENT_SHADER);
		length = static_cast<GLint>(std::strlen(ps));
		glShaderSource(this->pixelShader, 1, &ps, &length);
		glCompileShader(this->pixelShader);

		// get error log
		shaderLogSize;
		glGetShaderiv(this->pixelShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->pixelShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// create a program object
		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->pixelShader);
		glLinkProgram(this->program);
		glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetProgramInfoLog(this->program, shaderLogSize, NULL, buf);
			printf("[PROGRAM LINK ERROR]: %s", buf);
			delete[] buf;
		}

		//data used for the creation of vertexbuffer in the mesh. 
		std::vector<GLfloat> positions = {
			-0.5f,-0.5f, -1, // 0
			 1,0,0,1,		// color0
			 0.5f,-0.5f, -1, // 1
			 0,1,0,1,		//color1
			 0.5f, 0.5f, -1, // 2
			 0,0,1,1,		//color2
			-0.5f, 0.5f, -1, // 3
			 1,1,1,1		//color4


		};

		//indices used in the vertex buffer     
		/*	3------2
			|	   | 
			|	   |
			0------1
		*/
		std::vector<GLuint> indices = {
			0,1,2,					
			2,3,0
		};
		
		//creates mesh object
		MeshResource mesh(positions, indices);
		
		//setup of vertex and index buffers for the mesh
		mesh.SetupVertexBuffer();
		mesh.SetupIndexBuffer();

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/
void
Lab2::Run()
{
	//angle and velocity for continous rotation and movement in the x-axis, rotation around z-axis
	float angle=0;
	float vel = 0.5;
	
	while (this->window->IsOpen())
	{
		//creation of movement matrix, transform mat
		//using sine-wave for movement, quad shifting between left and right
		Matrix4D move(
			1, 0, 0, sin(vel),
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);

		//change of rotation value for continous rotation
		angle -= 0.05;
		glClear(GL_COLOR_BUFFER_BIT);
		this->window->Update();

		Matrix4D rot = Matrix4D::RotZ_axis(angle);


		vel += 0.05;
		glUseProgram(this->program);
		glUniformMatrix4fv(0,1,GL_FALSE, &(rot*move)[0]); // rot and move matrix multiplied togheter to transform the each vertex using an uniform for the vertex shader

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glUseProgram(0);
		this->window->SwapBuffers();
		
	}
	
}

} // namespace Example