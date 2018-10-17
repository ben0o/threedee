
#include "Mesh.hpp"

Mesh::Mesh()
{  
}
Mesh::~Mesh()
{
}
void Mesh::InitialiseVAO()
{
    glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); 
	
	GLuint buffers[3];
	
	glGenBuffers(3, buffers);
	
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GL_FLOAT), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(&normals[0]), &normals[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(&uv[0]), &uv[0], GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Mesh::Draw()
{
	glBindVertexArray(vao); 
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
	//glDrawArrays(GL_POINTS, 0, vertexCount);
	
	glBindVertexArray(0); 
    glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
