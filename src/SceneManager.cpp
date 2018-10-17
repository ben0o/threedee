
#include "SceneManager.hpp"
SceneManager::SceneManager()
{
}
SceneManager::SceneManager(MeshManager* _ptrMeshMan, TextureManager* _ptrTexMan, Settings* _ptrSettings)
{
	p_meshManager = _ptrMeshMan;
	p_textureManager = _ptrTexMan;
	p_settings = _ptrSettings;
}
SceneManager::~SceneManager()
{
}
void SceneManager::Draw(GLFWwindow* _window)
{
	int width, height;
    glfwGetFramebufferSize(_window, &width, &height);
	assert(width > 0 && height > 0);
	const float ratio = width / float(height);
	/*
	const glm::mat4 orthoProj = glm::ortho(-ratio, ratio,
										   -1.0f,  1.0f,
											1.0f,  -1.0f);
	*/									
	const glm::mat4 projection = glm::perspective(45.0f, ratio, 0.1f, 200.0f);
	glm::mat4 modelView = glm::mat4(1.0f);
	
	//camera
	modelView = glm::translate(modelView, glm::vec3(0.0,0.0,-50.0));
	modelView = glm::rotate(modelView, -1.5708f, glm::vec3(0.0, 1.0, 0.0));
	
	const glm::mat4 MVP        = projection * modelView;
	
	glViewport(0, 0, width, height);
	
	GLint mvpID = glGetUniformLocation(shaderProgram, "MVP");
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, glm::value_ptr(MVP));

	for (std::vector<Object>::size_type i = 0;i<objects.size();i++)
		p_meshManager->Draw(objects[i].meshID);
}
void SceneManager::Update(double _dt)
{
	
}
void SceneManager::AddObject(Object _object)
{
	_object.meshID = p_meshManager->LoadObj(_object.meshFilename);
	objects.push_back(_object);
}
// Shader sources
const GLchar* vertexSource = R"glsl(

    #version 330

	layout(location = 0) in vec4 vertex;

	uniform mat4 MVP;

	void main()
	{
		gl_Position = MVP * vertex;
	}
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 150 core

	void main()
	{ 
		gl_FragColor = vec4(1.0,0.0,0.0,1.0);
	}
)glsl";

void SceneManager::InitialiseShaders()
{
	std::cout << "Initialise Shaders" << std::endl;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
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
    glUseProgram(shaderProgram);
    std::cout << "Shaders Loaded" << std::endl;
}
