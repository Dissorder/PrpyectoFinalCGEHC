/*---------------------------------------------------------*/
/* ----------------   Dibujo --------------------------*/
/*-----------------    2019-2   ---------------------------*/
/*------------- Luis Sergio Valencia Castro ---------------*/
#include <glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader_m.h>

#include <iostream>

void resize(GLFWwindow* window, int width, int height);
void my_input(GLFWwindow *window);

// settings
// Window size
int SCR_WIDTH = 3800;
int SCR_HEIGHT = 7600;

GLFWmonitor *monitors;
GLuint VBO, VAO, EBO;

void myData(void);
void display(void);
void getResolution(void);

//For Keyboard
float	movX = 0.0f,
		movY = 0.0f,
		movZ = -1.0f,
		rotY = 0.0f;

void getResolution()
{
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	SCR_WIDTH = mode->width;
	SCR_HEIGHT = (mode->height) - 80;
}

void myData()
{	
		GLfloat vertices[] = {
		//Position				//Color
		-2.0f, -8.0f, -0.2f,	//V0 - Bota Izquierda
		-2.0f,-10.0f,-0.2f,		//V1
		-10.0f,-10.0f,-0.2f,	//V2
		-10.0f,-9.0f,-0.2f,		//V3
		-9.0f,-8.0f,-0.2f,		//V4
		-8.0f,-8.0f,-0.2f,		//V5
		-7.0f,-7.0f,-0.2f,		//V6
		-6.0f,-7.0f,-0.2f,		//V7
		-6.0f,-6.0f,-0.2f,		//V8
		-5.0f,-5.0f,-0.2f,		//V9

		- 0.0f,-6.0f,-0.2f,		//V10	Antes de la pierna izq
		-2.0f,-8.0f,-0.2f,		//V11
		-5.0f,-5.0f,-0.2f,		//V12
		-4.0f,-4.0f,-0.2f,		//V13

		2.0f,-8.0f,-0.2f,		//V14	Bota der
		2.0f,-10.0f,-0.2f,		//V15
		10.0f,-10.0f,-0.2f,		//V16
		10.0f,-9.0f,-0.2f,		//V17
		9.0f,-8.0f,-0.2f,		//V18
		8.0f,-8.0f,-0.2f,		//V19
		7.0f,-7.0f,-0.2f,		//V20
		6.0f,-7.0f,-0.2f,		//V21
		6.0f,-6.0f,-0.2f,		//V22
		5.0f,-5.0f,-0.2f,		//V23

		0.0f,-6.0f,-0.2f,		//V24  Antes de la bota der
		2.0f,-8.0f,-0.2f,		//V25
		5.0f,-5.0f,-0.2f,		//V26
		4.0f,-4.0f,-0.2f,		//V27

		0.0f,-6.0f,-0.2f,		//V28
		-4.0f,-4.0f,-0.2f,		//V29
		-4.0f,-3.0f,-0.2f,		//V30
		4.0f,-3.0f,-0.2f,		//V31
		4.0f,-4.0f,-0.2f,		//V32

		-4.0f,-3.0f,-0.2f,		//V33	Pecho Parte 1
		-4.0f,0.0f,-0.2f,		//V34
		-2.0f,2.0f,-0.2f,		//V35
		-1.0f,1.0f,-0.2f,		//V36
		3.0f,1.0f,-0.2f,		//V37
		4.0f,0.0f,-0.2f,		//V38
		4.0f,-3.0f,-0.2f,		//V39

		-4.0f,0.0f,-0.2f,		//V40	Pecho parte 2
		-5.0f,-1.0f,-0.2f,		//V41
		-6.0f,3.0f,-0.2f,		//V42
		-5.0f,4.0f,-0.2f,		//V43
		-4.0f,4.0f,-0.2f,		//V44
		-2.0f,2.0f,-0.2f,		//V45

		3.0f,1.0f,-0.2f,		//V46	Pecho parte 3
		5.0f,3.0f,-0.2f,		//V47
		7.0f,3.0f,-0.2f,		//V48
		5.0f,-1.0f,-0.2f,		//V49
		4.0f,0.0f,-0.2f,		//V50

		-4.0f,-3.0f,-0.2f,		//V51 Pecho delineado
		-4.0f,0.0f,-0.2f,		//V52
		-5.0f,-1.0f,-0.2f,		//V53
		-6.0f,3.0f,-0.2f,		//V54
		-5.0f,4.0f,-0.2f,		//V55
		-4.0f,4.0f,-0.2f,		//V56
		-1.0f,1.0f,-0.2f,		//V57
		3.0f,1.0f,-0.2f,		//V58
		5.0f,3.0f,-0.2f,		//V59
		7.0f,3.0f,-0.2f,		//V60
		5.0f,-1.0f,-0.2f,		//V61
		4.0f,0.0f,-0.2f,		//V62
		4.0f,-3.0f,-0.2f,		//V63

		-5.0f,-1.0f,-0.2f,		//V64	Guante Izq
		-5.0f,-3.0f,-0.2f,		//V65
		-6.0f,-4.0f,-0.2f,		//V66
		-8.0f,-4.0f,-0.2f,		//V67
		-9.0f,-3.0f,-0.2f,		//V68
		-9.0f,0.0f,-0.2f,		//V69
		-8.0f,1.0f,-0.2f,		//V70
		-8.0f,2.0f,-0.2f,		//V71
		-7.0f,3.0f,-0.2f,		//V72
		-6.0f,3.0f,-0.2f,		//V73

		5.0f,-1.0f,-0.2f,		//V74	Guante Der
		5.0f,-3.0f,-0.2f,		//V75
		6.0f,-4.0f,-0.2f,		//V76
		8.0f,-4.0f,-0.2f,		//V77
		9.0f,-3.0f,-0.2f,		//V78
		9.0f,0.0f,-0.2f,		//V79
		8.0f,1.0f,-0.2f,		//V80
		8.0f,2.0f,-0.2f,		//V81
		7.0f,3.0f,-0.2f,		//V82
		6.0f,3.0f,-0.2f,		//V83

		3.0f,1.0f,-0.2f,		//V84 ????
		5.0f,3.0f,-0.2f,		//V85
		7.0f,3.0f,-0.2f,		//V86
		5.0f,-1.0f,-0.2f,		//V87

		-2.0f, 2.0f, -0.2f,		//V88	Casco 1
		-4.0f, 4.0f, -0.2f,		//V89
		-4.0f, 10.0f, -0.2f,	//V90
		-2.0f, 12.0f, -0.2f,	//V91

		-3.0f, 11.0f, -0.2f,	//V92	Casco 2
		-2.0f, 12.0f, -0.2f,	//V93
		0.0f, 12.0f, -0.2f,		//V94
		2.0f, 10.0f, -0.2f,		//V95
		2.0f, 9.0f, -0.2f,		//V96
		3.0f, 8.0f, -0.2f,		//V97
		-1.0f, 8.0f, -0.2f,		//V98
		-2.0f, 7.0f, -0.2f,		//V99
		-3.0f, 7.0f, -0.2f,		//V100

		-4.0f, 5.0f, -0.2f,		//V101 Casco 3
		-5.0f, 6.0f, -0.2f,		//V102
		-5.0f, 8.0f, -0.2f,		//V103
		-4.0f, 9.0f, -0.2f,		//V104

		-4.0f, 4.0f, -0.2f,		//V105	Delimitar casco
		-4.0f, 5.0f, -0.2f,		//V106
		-5.0f, 6.0f, -0.2f,		//V107
		-5.0f, 8.0f, -0.2f,		//V108
		-4.0f, 9.0f, -0.2f,		//V109
		-4.0f, 10.0f, -0.2f,	//V110
		-3.0f, 11.0f, -0.2f,	//V111
		-2.0f, 12.0f, -0.2f,		//V112
		0.0f, 12.0f, -0.2f,		//V113
		1.0f, 13.0f, -0.2f,		//V114
		2.0f, 13.0f, -0.2f,		//V115
		5.0f, 10.0f, -0.2f,		//V116
		5.0f, 3.0f, -0.2f,		//V117
		3.0f, 1.0f, -0.2f,		//V118
		-1.0f, 1.0f, -0.2f,		//V119
		-1.0f, 1.0f, -0.2f,		//V120

		0.0f, 12.0f, -0.2f,		//V121	Interno casco
		1.0f, 13.0f, -0.2f,		//V122
		2.0f, 13.0f, -0.2f,		//V123
		5.0f, 10.0f, -0.2f,		//V124
		2.0f, 10.0f, -0.2f,		//V125

		4.0f, 10.0f, -0.2f,		//V126	Frente
		2.0f, 10.0f, -0.2f,		//V127
		2.0f, 9.0f, -0.2f,		//V128
		3.0f, 8.0f, -0.2f,		//V129
		4.0f, 8.0f, -0.2f,		//V130

		4.0f, 10.0f, -0.2f,		//V131
		5.0f, 10.0f, -0.2f,		//V132
		5.0f, 8.0f, -0.2f,		//V133
		4.0f, 8.0f, -0.2f,		//V134

		2.0f, 10.0f, -0.2f,		//V135
		2.0f, 9.0f, -0.2f,		//V136
		3.0f, 8.0f, -0.2f,		//V137
		4.0f, 8.0f, -0.2f,		//V138

		5.0f, 8.0f, -0.2f,		//V139	rostro
		5.0f, 3.0f, -0.2f,		//V140
		3.0f, 1.0f, -0.2f,		//V141
		-1.0f, 1.0f, -0.2f,		//V142
		-2.0f, 2.0f, -0.2f,		//V143
		-2.0f, 7.0f, -0.2f,		//V144
		-1.0f, 8.0f, -0.2f,		//V145

		0.0f, 7.0f, -0.2f,		//V146
		2.0f, 7.0f, -0.2f,		//V147
		2.0f, 4.0f, -0.2f,		//V148
		0.0f, 4.0f, -0.2f,		//V149

		3.0f, 7.0f, -0.2f,		//V150
		4.0f, 7.0f, -0.2f,		//V151
		4.0f, 4.0f, -0.2f,		//V152
		3.0f, 4.0f, -0.2f,		//V153

		-1.0f, 3.0f, -0.2f,		//V154
		3.0f, 3.0f, -0.2f,		//V155
		3.0f, 2.0f, -0.2f,		//V156
		-1.0f, 2.0f, -0.2f		//V157
	};



	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void display(void)
{
	//Shader myShader("shaders/shader.vs", "shaders/shader.fs");
	Shader projectionShader("shaders/shader_projection.vs", "shaders/shader_projection.fs");

	projectionShader.use();

	// create transformations and Projection
	glm::mat4 model = glm::mat4(1.0f);		// initialize Matrix, Use this matrix for individual models
	glm::mat4 view = glm::mat4(1.0f);		//Use this matrix for ALL models
	glm::mat4 projection = glm::mat4(1.0f);	//This matrix is for Projection

	
	//Use "projection" in order to change how we see the information
	projection = glm::ortho(0.0f, 15.0f, -13.0f, 13.0f, 0.1f, 10.0f);

	//Use "view" in order to affect all models
	view = glm::translate(view, glm::vec3(movX, movY, movZ));
	view = glm::rotate(view,glm::radians(rotY), glm::vec3(0.0f, 1.0f, 0.0f));
	// pass them to the shaders
	projectionShader.setMat4("model", model);
	projectionShader.setMat4("view", view);
	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	projectionShader.setMat4("projection", projection);


	glBindVertexArray(VAO);
	glLineWidth(18.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 0, 10); //Bota Izquierda
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 0, 10); //Bota Izquierda

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 10, 4); //Antes de bota Izquierda
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 10, 4); //Antes de bota Izquierda

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 14, 10); //Antes de bota Izquierda
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 14, 10); //Antes de bota Izquierda

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 24, 4); //Antes de bota Izquierda
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 24, 4); //Antes de bota Izquierda

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 28, 5); //Antes de bota Izquierda
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 28, 5); //Antes de bota Izquierda

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 33, 7); //Pecho parte 1

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 40, 6); //Pecho parte 2

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 46, 5); //Pecho parte 2

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 51, 13); //Pecho DELINEADO

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 64, 10); //Guante Izq
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 64, 10); //Guante Izq DELINEADO
		

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 74, 10); //Guante Der
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 74, 10); //Guante Der DELINEADO

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 88, 4); //Casco

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 92, 9); //Casco 2

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.8f, 0.9f));
		glDrawArrays(GL_POLYGON, 101, 4); //Casco 3
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_LINE_LOOP, 105, 16); //Casco delineado

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.9f, 0.8f));
		glDrawArrays(GL_POLYGON, 121, 5); //Interno Casco
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_LINE_LOOP, 121, 5); //Interno Casco delineado

		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.7f));
		glDrawArrays(GL_POLYGON, 131, 4); //Frente
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.9f, 0.8f));
		glDrawArrays(GL_POLYGON, 126, 5); //Frente
		

		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_LINE_STRIP, 131, 4); //Frente


		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 146, 4); //Ojo
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 150, 4); //Ojo
		projectionShader.setVec3("aColor", glm::vec3(0.0f, 0.0f, 0.0f));
		glDrawArrays(GL_POLYGON, 154, 4); //Boca
		projectionShader.setVec3("aColor", glm::vec3(1.0f, 0.9f, 0.5f));
		glDrawArrays(GL_POLYGON, 139, 7); //Cara

		
		
		
		

	glBindVertexArray(0);

}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    /*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
	monitors = glfwGetPrimaryMonitor();
	getResolution();

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Dibujo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
	glfwSetWindowPos(window, 0, 30);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, resize);

	glewInit();


	//Mis funciones
	//Datos a utilizar
	myData();
	glEnable(GL_DEPTH_TEST);

    // render loop
    // While the windows is not closed
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        my_input(window);

        // render
        // Backgound color
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Mi función de dibujo
		display();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void my_input(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
        glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		movX += 0.08f;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		movX -= 0.08f;
	if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		movY += 0.08f;
	if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		movY -= 0.08f;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		movZ -= 0.08f;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		movZ += 0.08f;

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void resize(GLFWwindow* window, int width, int height)
{
    // Set the Viewport to the size of the created window
    glViewport(0, 0, width, height);
}