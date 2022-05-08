#define _USE_MATH_DEFINES 1
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <GLFW/glfw3.h>
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include "camController.hpp"

#define TURN_RATE 1.f
#define LIMIT_PITCH  90.f;

CamController* camController = new CamController();

void keyCall(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE) { // exits the program
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			glfwTerminate();
			exit(EXIT_SUCCESS);
		}
			
		if (key == GLFW_KEY_W)
		{
			camController->InputZ++;
		}

		if (key == GLFW_KEY_S)
		{
			camController->InputZ--;
		}

		if (key == GLFW_KEY_A)
		{
			camController->InputX++;
		}

		if (key == GLFW_KEY_D)
		{
			camController->InputX--;
		}

		if (key == GLFW_KEY_LEFT)
		{
			camController->InputYaw++;
		}
		if (key == GLFW_KEY_RIGHT)
		{
			camController->InputYaw--;
		}
		if (key == GLFW_KEY_UP)
		{
			camController->InputPitch++;
		}
		if (key == GLFW_KEY_DOWN)
		{
			camController->InputPitch--;
		}
	}



	if (action == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_W)
		{
			camController->InputZ--;
		}

		if (key == GLFW_KEY_S)
		{
			camController->InputZ++;
		}

		if (key == GLFW_KEY_A)
		{
			camController->InputX--;
		}

		if (key == GLFW_KEY_D)
		{
			camController->InputX++;
		}

		if (key == GLFW_KEY_LEFT)
		{
			camController->InputYaw--;
		}
		if (key == GLFW_KEY_RIGHT)
		{
			camController->InputYaw++;
		}
		if (key == GLFW_KEY_UP)
		{
			camController->InputPitch--;
		}
		if (key == GLFW_KEY_DOWN)
		{
			camController->InputPitch++;
		}
	}
}

void CamController::InitController(GLFWwindow* window)
{
	glfwSetKeyCallback(window, keyCall);
}

glm::vec3 CamController::GetPos()
{
	return glm::vec3(X, Y, Z);
}

float pitch2Ang(float pitch) //convert pitch values from rad to local player angle
{
	return  pitch * (90.f / (M_PI / 2.f)); // coverts to local angles and store

}
float pitch2Rad(float pitch) //convert pitch values from local player angle to rad
{
	return  pitch / (90.f / (M_PI / 2.f)); //

}

float yaw2Ang(float pitch) 
{
	return  pitch * (180.f / (M_PI / 2.f)); 

}
float yaw2Rad(float pitch) //convert pitch values from rad to local player angle
{
	return  pitch / (180.f / (M_PI / 2.f)); // coverts to local angles and store

}


glm::mat4 CamController::LookAt()
{

	float maxPitch = 0.4f;

	Direction = glm::rotate(glm::vec3(0.0f, 0.0f, 1.f), pitch2Rad( Pitch ) , glm::vec3(1, 0, 0));
	Direction = glm::rotate(Direction, vYaw, glm::vec3(0, 1, 0));

	glm::mat4 view = glm::lookAt(
		glm::vec3(X, Y, Z),
		GetPos() + Direction,
		glm::vec3(0, 1, 0) // 0, 1, 0
	);
	return view;
}

void CamController::Turn()
{
	if (InputYaw >= 1) TurnLeft();
	else if (InputYaw <= -1) TurnRight();

	float limitPitch = LIMIT_PITCH;
	limitPitch -= TURN_RATE;
	if (InputPitch >= 1 && Pitch > -limitPitch) TurnUp();
	else if (InputPitch <= -1 && Pitch < limitPitch) TurnDown();

}

void CamController::Move()
{
	if (InputZ >= 1) MoveForward();
	else if (InputZ <= -1) MoveBack();

	if (InputX >= 1) MoveLeft();
	else if (InputX <= -1) MoveRight();

}

void CamController::MoveForward()
{
	glm::vec3 move = Direction * 0.02f;
	Z += move.z;
	X += move.x;
}

void CamController::MoveBack()
{
	glm::vec3 move = Direction * 0.02f;
	Z -= move.z;
	X -= move.x;
}

void CamController::MoveLeft()
{
	std::cout << "x: " << Direction.x
	<< "  y: " << Direction.y
	<< "  z: " << Direction.z
	<< " , called left\n";
	glm::vec3 leftDir = glm::rotate(Direction, (float)M_PI / 2.f, glm::vec3(0.f, -1.f, 0.f));
	glm::vec3 move = leftDir * 0.02f;
	Z -= move.z;
	X -= move.x;
}

void CamController::MoveRight()
{

	glm::vec3 rightDir = glm::rotate(Direction, (float)M_PI / 2.f, glm::vec3(0.f, 1.f, 0.f));
	glm::vec3 move = rightDir * 0.02f;
	Z -= move.z;
	X -= move.x;
}
void CamController::TurnLeft()
{
	vYaw += 0.02f;

}

void CamController::TurnRight()
{
	vYaw -= 0.02f;
	float yy = yaw2Ang(vYaw);
	std::cout << "Input: " << vYaw
		<< "  yaw2Ang: " << yy
		<< "  yaw2Rad: " << yaw2Rad(yy)
		<< "\n";
}

void CamController::TurnUp()
{
	Pitch -= TURN_RATE;

	float ang = pitch2Ang(Pitch);
	/*
	std::cout << "Input: " << Pitch
		<< "  pitch2Ang: " << pitch2Rad(Pitch)
		<< "\n";
	*/
}

void CamController::TurnDown()
{

	Pitch += TURN_RATE;

	//std::cout << Pitch << "\n";
}