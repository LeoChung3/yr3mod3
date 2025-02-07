#pragma once
#include <DemonRenderer.hpp>
#include "include/ui.hpp"
#include "include/ImGui/bloomPanel.hpp"

enum class GameState {intro, running, gameOver};

class AsteriodBelt : public Layer
{
public:
	AsteriodBelt(GLFWWindowImpl& win);
private:
	void onRender() override;
	void onUpdate(float timestep) override;
	void onImGUIRender() override;
	void onKeyPressed(KeyPressedEvent& e) override;
	void generateLevel();
	void checkWaypointCollisions();
	void checkAsteroidCollisions();
private:
	std::shared_ptr<Scene> m_mainScene;
	std::shared_ptr<Scene> m_screenScene; // Rename this!
	std::vector<std::shared_ptr<Scene>> m_bloomScenes;

	Renderer m_mainRenderer;
	std::vector<glm::vec3> m_closeAsteroids; // Asteroids to be drawn in the UI (x,y) dist
	std::vector<glm::vec3> m_closeTargets; // Targets to be drawn in the UI (x,y) dist

	// ImGui panels
	BloomPanel m_bloomPanel = BloomPanel(m_mainRenderer);
	// Actor positions for ease of use and to avoid additonal magic numbers

	UI m_ui; // Seperate user interface
	size_t cameraIdx{ 0 };
	size_t skyboxIdx{ 0 };
	size_t shipIdx{ 0 };
	size_t nextTargetIdx{ 0 };


	GameState m_state{ GameState::intro };
	float speed{ 0.f };

	std::shared_ptr<Texture> m_introTexture{ nullptr };
	std::shared_ptr<Texture> m_gameOverTexture{ nullptr };
	const std::array<glm::vec4, 16> m_speedUIColours = {
		glm::vec4(0.992156862745098f, 0.941176470588235f, 0.0117647058823529f, 0.85f),
		glm::vec4(0.984313725490196f, 0.894117647058824f, 0.0313725490196078f, 0.85f),
		glm::vec4(0.976470588235294f, 0.83921568627451f, 0.0549019607843137f, 0.85f),
		glm::vec4(0.972549019607843f, 0.788235294117647f, 0.0745098039215686f, 0.85f),
		glm::vec4(0.964705882352941f, 0.737254901960784f, 0.0941176470588235f, 0.85f),
		glm::vec4(0.956862745098039f, 0.686274509803922f, 0.113725490196078f, 0.85f),
		glm::vec4(0.949019607843137f, 0.631372549019608f, 0.137254901960784f, 0.85f),
		glm::vec4(0.941176470588235f, 0.580392156862745f, 0.156862745098039f, 0.85f),
		glm::vec4(0.933333333333333f, 0.529411764705882f, 0.176470588235294f, 0.85f),
		glm::vec4(0.933333333333333f, 0.462745098039216f, 0.180392156862745f, 0.85f),
		glm::vec4(0.945098039215686f, 0.337254901960784f, 0.133333333333333f, 0.85f),
		glm::vec4(0.96078431372549f, 0.203921568627451f, 0.0784313725490196f, 0.85f),
		glm::vec4(0.972549019607843f, 0.0784313725490196f, 0.0313725490196078f, 0.85f),
		glm::vec4(0.968627450980392f, 0.f,0.f, 0.85f),
		glm::vec4(0.937254901960784f, 0.f,0.f, 0.85f),
		glm::vec4(0.909803921568627f, 0.f,0.f, 0.85f)
	};

	const std::array<float, 15> m_speedThresholds = {
			-0.82f,
			-1.14f,
			-1.46f,
			-1.78f,
			-2.1f,
			-2.42f,
			-2.74f,
			-3.06f,
			-3.38f,
			-3.7f,
			-4.02f,
			-4.34f,
			-4.66f,
			-4.98f,
			-5.3f
	};
};