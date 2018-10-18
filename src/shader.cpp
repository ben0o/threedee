
#include "shader.hpp"

// Shader sources
const GLchar* vertexSource = R"glsl(

    #version 330

	layout(location = 0) in vec3 vertex;
	layout(location = 1) in vec4 normal;
	layout(location = 2) in vec2 uv;
	
	varying vec2 UV;

	uniform mat4 MVP;

	void main()
	{
		gl_Position = MVP * vec4(vertex,1.f);
		UV = uv;
	}
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 150 core
    
    varying vec2 UV;
    
    uniform sampler2D map_Kd;
	uniform sampler2D map_Ks;
	uniform sampler2D map_bump;
	void main()
	{ 
		gl_FragColor = texture2D(map_Kd, UV);
	}
)glsl";

Shader::Shader()
{
}
Shader::~Shader()
{
}
void Shader::LoadShader()
{
	std::cout << "Initialise Shaders" << std::endl;
    
	// Create and compile the vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    
    GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

	if(isCompiled == GL_FALSE)
	{
		std::cout << "Vertex shader failed to compile!" << std::endl;
		exit(1);
	}

	isCompiled = 0;

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

	if(isCompiled == GL_FALSE)
	{
		std::cout << "Fragment shader failed to compile!" << std::endl;
		exit(1);
	}
    
    // Link the vertex and fragment shader into a shader program
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    std::cout << "Shaders Loaded" << std::endl;
}
void Shader::UseProgram()
{
	glUseProgram(shaderProgram);
}
void Shader::SetMVP(glm::mat4 _MVP)
{
	GLint mvpID = glGetUniformLocation(shaderProgram, "MVP");
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, glm::value_ptr(_MVP));
}
void Shader::SetMap_Kd(GLuint _map_Kd)
{
	GLint textureID = glGetUniformLocation(shaderProgram, "map_Kd");
    assert(textureID>=0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _map_Kd);
    
glUniform1i(textureID, 0);
}
void Shader::SetMap_Ks()
{
}
void Shader::SetMap_bump()
{
}
