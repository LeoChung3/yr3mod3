#include "scripts/include/controller.hpp"
#include "core/log.hpp"
void ControllerScript::onUpdate(float timestep)
{
	glm::vec3 forward = { -m_actor.transform[2][0], -m_actor.transform[2][1], -m_actor.transform[2][2] };

	m_actor.translation += forward * m_movementSpeed.z * timestep;

	if (m_winRef.isKeyPressed(GLFW_KEY_W)) {
		float theta = m_movementSpeed.x * timestep;
		glm::quat delta(glm::vec3(theta, 0.f, 0.f));
		m_actor.rotation *= delta;
	}
	if (m_winRef.isKeyPressed(GLFW_KEY_S)) {
		float theta = m_movementSpeed.x * -timestep;
		glm::quat delta(glm::vec3(theta, 0.f, 0.f));
		m_actor.rotation *= delta;
	}

	if (m_winRef.isKeyPressed(GLFW_KEY_D)) {
		float theta = m_movementSpeed.y * -timestep;
		glm::quat delta(glm::vec3(0.f, theta, 0.f));
		m_actor.rotation *= delta;
	}
	if (m_winRef.isKeyPressed(GLFW_KEY_A)) {
		float theta = m_movementSpeed.y * timestep;
		glm::quat delta(glm::vec3(0.f, theta, 0.f));
		m_actor.rotation *= delta;
	}

	m_actor.recalc();
	
	if (m_winRef.isKeyPressed(GLFW_KEY_UP)) {
		m_movementSpeed.z = std::clamp(m_movementSpeed.z - timestep, m_maxSpeed, m_minSpeed);
		*m_speedOut = m_movementSpeed.z;
	}

	if (m_winRef.isKeyPressed(GLFW_KEY_DOWN)) {
		m_movementSpeed.z = std::clamp(m_movementSpeed.z + timestep, m_maxSpeed, m_minSpeed);
		*m_speedOut = m_movementSpeed.z;
	}

	// Follow
	glm::vec3 targetRight = { m_actor.transform[0][0], m_actor.transform[0][1], m_actor.transform[0][2] };
	glm::vec3 targetUp = { m_actor.transform[1][0], m_actor.transform[1][1], m_actor.transform[1][2] };
	glm::vec3 targetForward = { -m_actor.transform[2][0], -m_actor.transform[2][1], -m_actor.transform[2][2] };

	m_followCamera.translation = m_actor.translation;

	m_followCamera.translation += targetRight * m_offset.x;
	m_followCamera.translation += targetUp * m_offset.y;
	m_followCamera.translation += targetForward * m_offset.z;

	m_followCamera.rotation = m_actor.rotation * glm::quat(glm::vec3(0.f, glm::pi<float>(), 0.f)); // Hack as model is backward to start with

	m_followCamera.recalc();
}

void ControllerScript::onImGuiRender()
{
	ImGui::DragFloat3("Follow cam offset", &m_offset[0], 0.1f, 0.f, 10.f);
	ImGui::DragFloat("Speed", &m_movementSpeed[2], 0.1, -10.f, 10.f);
}
