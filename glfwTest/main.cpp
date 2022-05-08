#include <iostream>
#include <conio.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "camController.hpp"
#include "models.hpp"

#define OVERLAY_MODE 0


int app_width = 1920;
int app_height = 1080;

float camx = .0f;
float camy = .0f;
float camz = .0f;



int main(void)
{
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	if (OVERLAY_MODE == 1) {
		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
		glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
		glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	}

	//GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	//const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	GLFWwindow* window = glfwCreateWindow(app_width, app_height, "GLFW Test", 0, 0);

	camController->InitController(window);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	float angle = 0.0f;

	float angle2 = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		camController->Move();
		camController->Turn();
		glfwGetFramebufferSize(window, &app_width, &app_height);
		glViewport(0, 0, app_width, app_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glfwPollEvents();
		int w, h;
		glfwGetFramebufferSize(window, &w, &h);
		glViewport(0, 0, w, h);
		glEnable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glMatrixMode(GL_MODELVIEW);


		const float time = static_cast<float>(glfwGetTime());

		float angle1 = time;
		angle2 = time * 2.f;
		float aspect = (float)app_width / (float)app_height;
		glm::mat4 projection = glm::perspective(1.0f, aspect, 0.1f, 100.0f);

		glPushMatrix();
		{
			glm::mat4 view = camController->LookAt();
			//glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 2.5f));
			glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 2.56f));


			
			view = projection * view * model;
			glMultMatrixf(glm::value_ptr(view));
			DrawPly(.325f, 200, 0, 0);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glm::mat4 view = camController->LookAt();
			glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.5f));
			model = glm::rotate(model, 10.f, glm::vec3(0.4f, 0.0f, 0.f));
			model = glm::rotate(model, angle1, glm::vec3(0.0f, 0.4f, 0.f));

			view = projection * view * model;
			glMultMatrixf(glm::value_ptr(view));
			DrawPly(.325f, 0, 0, 200);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glm::mat4 view = camController->LookAt();
			glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(2.5f, 0.0f, 0.f));
			model = glm::rotate(model,1.f, glm::vec3(1.f, 0.0f, 0.f));
			//PI / 2 = 1.57079632679
			model = glm::rotate(model, 1.57079632679f, glm::vec3(0.f, 1.f, 0.f));
			model = glm::translate(model, glm::vec3(std::sin(angle1), 0.0f, 0.f));
			view = projection * view * model;
			glMultMatrixf(glm::value_ptr(view));
			DrawPly(.325f, 0, 200, 0);
		}
		glPopMatrix();


		for (int i = 0; i < 5; i++)
		{
			glPushMatrix();
			{
				glm::mat4 view = camController->LookAt();
				glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-2.5f, 0.0f, -1.f + 0.5f * (float)i ));
				view = projection * view * model;
				glMultMatrixf(glm::value_ptr(view));
				DrawPly(.325f, 200, 0, 200);
			}
			glPopMatrix();
		}



		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	exit(EXIT_SUCCESS);
	return 0;
}
