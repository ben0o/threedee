
#include "shader.hpp"

#define MAXLIGHTS 2

// Shader sources
const GLchar* vertexSource = R"glsl(

    #version 330

	layout(location = 0) in vec3 vertex;
	layout(location = 1) in vec4 normal;
	layout(location = 2) in vec2 uv;
	
	out vec2 UV;

	uniform mat4 m, v, p;

	void main()
	{
		mat4 mvp = p*v*m;
		gl_Position = mvp * vec4(vertex,1.f);
		UV = uv;
	}
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 150 core

    in vec2 UV;
    out vec4 colour;
    
    uniform sampler2D map_Kd;
	uniform sampler2D map_Ks;
	uniform sampler2D map_bump;
	void main()
	{ 
		colour = texture2D(map_Kd, UV);
	}
)glsl";
//******************************************************************
const GLchar* vertexSource2 = R"glsl(

    #version 330

	layout(location = 0) in vec3 v_coord;
	layout(location = 1) in vec3 v_normal;
	layout(location = 2) in vec2 uv;
	
	out vec4 position;
	out vec3 normal;
	out vec2 UV;

	uniform mat4 m, v, p;

	void main()
	{
		mat4 mvp = p*v*m;
		gl_Position = mvp * vec4(v_coord,1.f);
		position = m * vec4(v_coord,1.f);
		normal = vec3(m * vec4(v_normal,1.f));
		UV = uv;
	}
)glsl";
const GLchar* fragmentSource2 = R"glsl(
    #version 330 core
    
    in vec2 UV;
    in vec4 position;
    in vec3 normal;
    out vec4 colour;
    
    uniform sampler2D map_Kd;
	uniform sampler2D map_Ks;
	uniform sampler2D map_bump;
	
	struct lightSource
	{
		vec4 position;
		vec4 diffuse;
		vec4 specular;
		float constantAttenuation, linearAttenuation, quadraticAttenuation;
		float spotCutoff, spotExponent;
		vec3 spotDirection;
	};
	
	lightSource light0 = lightSource(
		vec4(0.0,  5.0,  0.0, 0.0),
		vec4(1.0,  1.0,  1.0, 1.0),
		vec4(1.0,  1.0,  1.0, 1.0),
		0.0, 1.0, 0.0,
		180.0, 0.0,
		vec3(0.0, 0.0, 0.0)
	);
	
	void main()
	{ 
		vec3 ka;
		vec4 kd;
		vec3 ks;
		vec3 normalDirection;
		vec3 lightDirection;
		float attenuation;
		
		// Binormal
		vec3 tangent = -vec3(abs(normal.y) + abs(normal.z), abs(normal.x), 0);
		vec3 binormal = normalize(cross(tangent, normal));
		mat3 TBN = transpose(mat3(tangent,binormal,normal));
		
		//Add bumpmap//////////////////////////////////////////////////////////////
		normalDirection = (normalize(texture2D(map_bump, UV).rgb * 2.0 - 1.0) * TBN);
		normalDirection = normalize(normalDirection);
		
		
		if (light0.position.w == 0.0) 									// directional light?
		{
			attenuation = 1.0; 											// no attenuation
			lightDirection = normalize(vec3(light0.position));
		}
		else
		{
			vec3 positionToLightSource = vec3(light0.position - position);
			float distance = length(positionToLightSource);
			lightDirection = normalize(positionToLightSource);
			
			attenuation = 1.0 / (light0.constantAttenuation + light0.linearAttenuation * distance + light0.quadraticAttenuation * distance * distance);
		  
			if (light0.spotCutoff <= 90.0) // spotlight?
			{
				float clampedCosine = max(0.0, dot(-lightDirection, normalize(light0.spotDirection)));
				if (clampedCosine < cos(radians(light0.spotCutoff))) 									// outside of spotlight cone?
				{
					attenuation = 0.0;
				}
				else
				{
					attenuation = attenuation * pow(clampedCosine, light0.spotExponent);   
				}
			}
		}
		kd = attenuation * light0.diffuse * texture2D(map_Kd, UV) * max(0.0, dot(normalDirection, lightDirection));
		//kd = texture2D(map_Kd, UV);
		colour = kd;
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
    glShaderSource(vertexShader, 1, &vertexSource2, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource2, NULL);
    glCompileShader(fragmentShader);
    
    GLint isVertCompiled = 0;
    GLint isFragCompiled = 0;
    
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isVertCompiled);
	

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isFragCompiled);
	
	if(isVertCompiled == GL_FALSE || isFragCompiled == GL_FALSE)
	{
		{
			std::cout << "Vertex shader log:" << std::endl;
			GLint  logSize;
			glGetProgramiv( vertexShader, GL_INFO_LOG_LENGTH, &logSize);
			char* logMsg = new char[logSize];
			glGetShaderInfoLog( vertexShader, logSize, NULL, logMsg );
			std::cerr << logMsg << std::endl;
		}
		{
			std::cout << "Fragment shader log" << std::endl;
			GLint  logSize;
			glGetProgramiv( fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
			char* logMsg = new char[logSize];
			glGetShaderInfoLog( fragmentShader, logSize, NULL, logMsg );
			std::cerr << logMsg << std::endl;
		}
		std::cout << "Halt - Shaders failed to compile" << std::endl;
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
void Shader::SetMatM(glm::mat4 _M)
{
	GLint mvpID = glGetUniformLocation(shaderProgram, "m");
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, glm::value_ptr(_M));
}
void Shader::SetMatV(glm::mat4 _V)
{
	GLint mvpID = glGetUniformLocation(shaderProgram, "v");
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, glm::value_ptr(_V));
}
void Shader::SetMatP(glm::mat4 _P)
{
	GLint mvpID = glGetUniformLocation(shaderProgram, "p");
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, glm::value_ptr(_P));
}
void Shader::SetMap_Kd(GLuint _map_Kd)
{
	GLint textureID = glGetUniformLocation(shaderProgram, "map_Kd");
    assert(textureID>=0);

    glUniform1i(textureID, 0);
    
glUniform1i(textureID, 0);
}
void Shader::SetMap_Ks(GLuint _map_Ks)
{
	GLint textureID = glGetUniformLocation(shaderProgram, "map_Ks");
    assert(textureID>=0);

    glUniform1i(textureID, 1);
}
void Shader::SetMap_bump(GLuint _map_bump)
{
	GLint textureID = glGetUniformLocation(shaderProgram, "map_bump");
    assert(textureID>=0);
    
    glUniform1i(textureID, 2);
}
