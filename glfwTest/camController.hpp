#pragma once
#include "GLFW/glfw3.h"
#include <glm.hpp>


class CamController
{
public:
	CamController() {
		//X = 0.0f; Y = 0.0f; Z = 0.0f;
		Direction = glm::vec3(0.f, 0.f, 1.f);
	};
	float X = 0.f;
	float Y = 0.60f;
	float Z = 0.f;
	float Pitch = 0.f;
	float Yaw = 0.f;
	int InputZ = 0.f;
	int InputX = 0.f;
	int InputYaw = 0.f;
	int InputPitch = 0.f;

	glm::vec3 Direction;
	void InitController(GLFWwindow* window);
	void Move();

	void Turn();
	glm::mat4 LookAt();
	glm::vec3 GetPos();
	glm::vec3 FromSourcePos(glm::vec3 pos);
private:

	float pitch2Rad(float pitch);
	float pitch2Ang(float pitch);
	float yaw2Rad(float yaw);
	float yaw2Ang(float yaw);
	void MoveForward();
	void MoveBack();
	void MoveLeft();
	void MoveRight();

	void TurnLeft();
	void TurnRight();
	void TurnUp();
	void TurnDown();
	//void keyCall(GLFWwindow* window, int key, int scancode, int action, int mods);
};


extern CamController* camController;