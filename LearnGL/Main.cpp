// Robin Meyler
// Start: 16/04/2019, Continued June ->, July ->
// Last Update: 17/06/19
// LearnGl tutorial
//#include <GLFW/glfw3.h>
////#include <glfw3.h>							// Window
//#include <glad/glad.h>						// To handle GL fucntion pointer
//
//#include <glm/glm.hpp>						// Math
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#define STB_IMAGE_IMPLEMENTATION			// Image loading
//#include "stb_image.h"
//
//#include <iostream>							// Built in
//#include <string>							
//
//#include "Shader.h"							// Made classes/headers
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//// settings
//const unsigned int SCR_WIDTH = 1800;
//const unsigned int SCR_HEIGHT = 1600;
//
//float deltaTime = 0.0f;	// Time between current frame and last frame
//float lastFrame = 0.0f; // Time of last frame
//
//float lastX = 400, lastY = 300;
//float pitch = 0, yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//float fov = 45.f;
//bool firstMouse = true;
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//int main()
//{
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 3.0 in update
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 0.3 in update
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		// Not old fixed pipeline
//
//	// Creates a window
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);	// Set that window to the context		(Look into Context more for multithreading?)
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	
//	// Glad manages fucntion pointers
//	// Must be initialized before an y open gl calls made
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	
//	// View point
//	glViewport(0, 0, 1800, 1600);
//	
//	// Load Shader text files
//	Shader myShader("vertex.txt", "Frag.txt");
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Coords <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	// For Cube
//	float vertices[] = {
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//  glm::vec3(0.0f,  0.0f,  0.0f),
//  glm::vec3(2.0f,  5.0f, -15.0f),
//  glm::vec3(-1.5f, -2.2f, -2.5f),
//  glm::vec3(-3.8f, -2.0f, -12.3f),
//  glm::vec3(2.4f, -0.4f, -3.5f),
//  glm::vec3(-1.7f,  3.0f, -7.5f),
//  glm::vec3(1.3f, -2.0f, -2.5f),
//  glm::vec3(1.5f,  2.0f, -2.5f),
//  glm::vec3(1.5f,  0.2f, -1.5f),
//  glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//	// For Square  (USES EBO, thus draw elements in render)
//	//float vertices[] = {
//	//	// positions          // colors           // texture coords
//	//	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//	//	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
//	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
//	//};
//	// For Triangles 
//	//float vertices[] = {
//	//	// positions         // colors
//	//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//	//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//	//	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
//	//};
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Indices <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	//unsigned int indices[] = {  // note that we start from 0! (FOR EBO)
//	//	0, 1, 3,  // first Triangle
//	//	1, 2, 3   // second Triangle
//	//};
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Texture loading <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	unsigned int texture1;
//	unsigned int texture2;
//	glGenTextures(1, &texture1);
//	glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	// set the texture wrapping/filtering options (on the currently bound texture object)
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	stbi_set_flip_vertically_on_load(true);	// ??
//	int width, height, nrChannels; // nrChannels = RGB format
//	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//
//	// (Below)
//	// 1 = Texture Target
//	// 2 = MipMap Level
//	// 3 = Format to store Texture
//	// 4,5 = dimensions from above, values given by the loader for use here
//	// 6 = Legacy stuff, not explained, always 0
//	// 7 = Format
//	// 8 = Datatype
//	// 9 = Actual image data
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D); // Only base texture loaded before this
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data); // Good practice to free memory
//
//	glGenTextures(1, &texture2);
//	glActiveTexture(GL_TEXTURE1); // activate the texture unit first before binding texture
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	// set the texture wrapping/filtering options (on the currently bound texture object)
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{		// RGBA for the Aplha
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture2" << std::endl;
//	}
//	stbi_image_free(data); // Good practice to free memory
//
//	myShader.use(); // don't forget to activate the shader before setting uniforms!  
//	glUniform1i(glGetUniformLocation(myShader.ID, "texture1"), 0); // set it manually
//	myShader.setInt("texture2", 1); // or with shader class		// These are the same, manually doing it or through our shdaer class
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Vertex Objects <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	unsigned int VBO[2], VAO[2], EBO;		 // Stores large number of vertices in GPU memory.
//
//	glGenVertexArrays(2, VAO);	// Can generate many Arrays and Buffers at once this way
//	glGenBuffers(2, VBO);		// 1 = how many you are making, you can have many.	
//	glGenBuffers(1, &EBO);
//
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//	glBindVertexArray(VAO[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);			// Can bind many buffers at once but they must be a different type.
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);										// Only needed if used (Usually used)
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// 1st = picks which one we want to configure, location = 0 from string
//	// 2nd = size of vertex attribute, Vec3
//	// 3rd = type
//	// 4th = if we want it to be normalised, True if int or byte
//	// 5th = Stride, space between vertex attributes
//	// 6th = Offset from the start, must be of type void* so it is cast
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); // position attribute
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));	// Texel attribute
//	glEnableVertexAttribArray(1);
//
//	// Vertex attributes managed by the VBO, current VBO on the GL_ARRAY_BUFFER
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);	// Unbinding
//
//	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0);
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Transforms Setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	// Wireframe
//	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	glEnable(GL_DEPTH_TEST);						// Tells Open GL to do Z buffer testing
//
//	//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f); // Camera pos
//
//	//glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//	//glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
//
//	//glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);	// Up in world space
//	//glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
//	//glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
//	//glm::mat4 view;
//	//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),	// Position
//	//	glm::vec3(0.0f, 0.0f, 0.0f),	// Target
//	//	glm::vec3(0.0f, 1.0f, 0.0f));	// upVector
//
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);		// Input
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);	// Sets the color to clear screen to	(State Setting)
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Checks for the state of glClearColor(State Using) // Clears colour and depth info
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Transforms Update <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//		
//		// Working in reverse to intuition, Don't rotate first
//		// Matrix Mulpilication is read Right to Left
//		
//	/*	float radius = 10.0f;			// Rotating about a circle code
//		float camX = sin(glfwGetTime()) * radius;
//		float camZ = cos(glfwGetTime()) * radius;
//*/
//		glm::mat4 view;
//		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//		//glm::mat4 view = glm::mat4(1.0f);
//		//// note that we're translating the scene in the reverse direction of where we want to move
//		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//
//		glm::mat4 projection;
//		projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Shader Update <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//		myShader.use();		// Apply desired Shader
//
//		// Update Uniforms
//		// For glUniformMatix4fv 1 = location 2 = how many you are sending 3 = if you want to transpose it 4 = Data we are sending
//
//		int viewLoc = glGetUniformLocation(myShader.ID, "view");
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//		int projectionLoc = glGetUniformLocation(myShader.ID, "projection");
//		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//		// Bind the Right Texture to the right Mesh and Memory
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Draw <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//		glBindVertexArray(VAO[0]);			// Seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		// If EBO or index array used
//		//glDrawArrays(GL_TRIANGLES, 0, 36);						// If no indices used (EBO)
//		for (unsigned int i = 0; i < 10; i++)
//		{
//			glm::mat4 model = glm::mat4(1.0f);		// Indentity Matix to reset
//			model = glm::translate(model, cubePositions[i]);
//			float angle = 20.0f * i;
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f)); 
//			myShader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	glDeleteVertexArrays(1, VAO);
//	glDeleteBuffers(1, VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();		// Clears/closes window properly
//	return 0;
//}
//	
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Press Escape
//		glfwSetWindowShouldClose(window, true);
//	float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		cameraPos += cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		cameraPos -= cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	float sensitivity = 0.05;
//	xoffset *= sensitivity;
//	yoffset *= sensitivity;
//
//	yaw += xoffset;
//	pitch += yoffset;
//
//	if (pitch > 89.0f)
//		pitch = 89.0f;
//	if (pitch < -89.0f)
//		pitch = -89.0f;
//
//	glm::vec3 front;
//	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	front.y = sin(glm::radians(pitch));
//	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//	cameraFront = glm::normalize(front);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	if (fov >= 1.0f && fov <= 45.0f)
//		fov -= yoffset;
//	if (fov <= 1.0f)
//		fov = 1.0f;
//	if (fov >= 45.0f)
//		fov = 45.0f;
//}


//// Load from TxT >>>>>>>>>>>>>>>>>>>>>>>>>>>
	//std::string vertline, textVert;
	//std::ifstream inVert("Vertex.txt");
	//while (std::getline(inVert, vertline))
	//{
	//	textVert += vertline + "\n";
	//}
	//const char* dataVert = textVert.c_str();
	//// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//std::string fragLine, textFrag;
	//std::ifstream inFrag("Frag.txt");
	//while (std::getline(inFrag, fragLine))
	//{
	//	textFrag += fragLine + "\n";
	//}
	//const char* dataFrag = textFrag.c_str();
	//// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//unsigned int vertexShader;		// Shader object
	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, &dataVert, NULL); // Add string to shader, 1 = how many strings passed
	//glCompileShader(vertexShader);	// Complile string of GLSL
	//// Error check --------
	//int  success;
	//char infoLog[512];
	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//// --------------------
	//unsigned int fragmentShader;
	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &dataFrag, NULL);
	//glCompileShader(fragmentShader);
	//// >>>>>>> Example of another Shader usage >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	////unsigned int fragmentShaderY;
	////fragmentShaderY = glCreateShader(GL_FRAGMENT_SHADER);
	////glShaderSource(fragmentShaderY, 1, &FragShaderStringYellow, NULL);
	////glCompileShader(fragmentShaderY);
	//// Error check --------
	//int  success2;
	//char infoLog2[512];
	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success2);
	//if (!success2)
	//{
	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog2);
	//	std::cout << "ERROR::SHADER::Frag::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//// --------------------
	//// Linking shaders to Shader program memory slot
	//unsigned int shaderProgram;
	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);
	//*unsigned int shaderProgramY;
	//shaderProgramY = glCreateProgram();
	//glAttachShader(shaderProgramY, vertexShader);
	//glAttachShader(shaderProgramY, fragmentShaderY);
	//glLinkProgram(shaderProgramY);*/
	//glUseProgram(shaderProgram);	// Every shader and rendering call after this will use this program
	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);
	//glDeleteShader(fragmentShaderY);

//// SECOND BUFFER >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//glBindVertexArray(VAO[1]);		// Binds the new one unbinding the other
	//glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);			// Can bind many buffers at once but they must be a different type.
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2nd), vertices2nd, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);	// Vertex Attribute as its location, i.e 0