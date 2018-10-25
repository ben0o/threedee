
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
void Mesh::Draw(Shader* _shader)
{
	glBindVertexArray(vao); 
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, map_Kd);
	GLint KdID = _shader->GetTextureID("map_Kd");
	glUniform1i(KdID, 0);
	
	//glActiveTexture(GL_TEXTURE1);
	//glBindTexture(GL_TEXTURE_2D, map_Ks);
	//GLint KsID = _shader->GetTextureID("map_Ks");
	//glUniform1i(KsID, 1);
	
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, map_bump);
	GLint bump_ID = _shader->GetTextureID("map_bump");
	glUniform1i(bump_ID, 2);
	
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
	//glDrawArrays(GL_POINTS, 0, vertexCount);
	
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindVertexArray(0); 
    glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}
