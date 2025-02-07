#pragma once

#include <glm/glm.hpp>

#include "gameObjects/actor.hpp"
#include "windows/GLFWWindowImpl.hpp"
#include "core/log.hpp"
class ControllerScript : public Script
{
public:
	ControllerScript(Actor& actor, GLFWWindowImpl& win, Actor& followCamera, const glm::vec3& movementSpeed, const glm::vec3& offset, float* speed) :
		Script(actor),
		m_winRef(win),
		m_followCamera(followCamera),
		m_movementSpeed(movementSpeed),
		m_offset(offset),
		m_speedOut(speed)
	{
		*m_speedOut = m_movementSpeed.z;
		onUpdate(0.f); // Initialise camera
	}
	void onUpdate(float timestep) override;
	void onKeyPress(KeyPressedEvent& e) override {};
	void onKeyRelease(KeyReleasedEvent& e) override {};
	void onImGuiRender() override;
private:
	GLFWWindowImpl& m_winRef;
	Actor& m_followCamera;
	glm::vec3 m_movementSpeed{ 0.f, 0.f, 0.f };
	glm::vec3 m_offset{ 0.f, 0.f, 0.f };
	const float m_minSpeed{ -0.5f };
	const float m_maxSpeed{ -5.5f };
	float* m_speedOut{ nullptr };
};
