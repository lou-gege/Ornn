#pragma once

#include "Ornn.h"

class Sandbox2D :public Ornn::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Ornn::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Ornn::Event& e) override;

private:
	Ornn::OrthographicsCameraController m_CameraController;

	// Temp
	Ornn::Ref<Ornn::VertexArray> m_SquareVA;
	Ornn::Ref<Ornn::Shader> m_FlatColorShader;

	Ornn::Ref<Ornn::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.8f, 0.3f,1.0f };
};