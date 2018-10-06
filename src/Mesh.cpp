
#include "Mesh.hpp"

Mesh::Mesh()
{
}
Mesh::~Mesh()
{
}
void Mesh::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT,0, &vertices[0]);
	
	glEnableClientState( GL_NORMAL_ARRAY );
	glNormalPointer(GL_FLOAT, 0, &normals[0] );
	
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer(2, GL_FLOAT, 0, &uv[0] );

	glDrawArrays(GL_TRIANGLES,0 ,vertexCount);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
