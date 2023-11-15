#include <Ornn.h>

#include "imgui/imgui.h"

class ExampleLayer :public Ornn::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Ornn::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Ornn::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Ornn::VertexBuffer::Create(vertices, sizeof(vertices)));

		Ornn::BufferLayout layout = {
			{Ornn::ShaderDataType::Float3, "a_Position"},
			{Ornn::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Ornn::IndexBuffer> indexBuffer;
		indexBuffer.reset(Ornn::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Ornn::VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Ornn::VertexBuffer> squareVB;
		squareVB.reset(Ornn::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Ornn::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Ornn::IndexBuffer> squareIB;
		squareIB.reset(Ornn::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);



		std::string vertexSrc = R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			
			out vec3 v_Position;
			out vec4 v_Color;

			void main() {
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
			}
		)";

		std::string fragmentSrc = R"(
			#version 460 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;
			
			void main() {
				color = vec4(v_Position + 0.5f, 1.0f);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Ornn::Shader(vertexSrc, fragmentSrc));


		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			uniform mat4 u_ViewProjection;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Ornn::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate() override
	{
		//ORNN_INFO("ExampleLayer::Update");
		if (Ornn::Input::IsKeyPressed(ORNN_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed;
		else if (Ornn::Input::IsKeyPressed(ORNN_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed;

		if (Ornn::Input::IsKeyPressed(ORNN_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed;
		else if (Ornn::Input::IsKeyPressed(ORNN_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed;

		if (Ornn::Input::IsKeyPressed(ORNN_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed;
		else if (Ornn::Input::IsKeyPressed(ORNN_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed;

		Ornn::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Ornn::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Ornn::Renderer::BeginScene(m_Camera);

		Ornn::Renderer::Submit(m_BlueShader, m_SquareVA);
		Ornn::Renderer::Submit(m_Shader, m_VertexArray);

		Ornn::Renderer::EndScene();
	}

	//virtual void OnImGuiRender() override
	//{
	//	ImGui::Begin("Test");
	//	ImGui::Text("Hello World");
	//	ImGui::End();
	//}

	void OnEvent(Ornn::Event& event) override
	{
		//ORNN_TRACE("{0}", event);
		//if (event.GetEventType() == Ornn::EventType::KeyPressed)
		//{
		//	Ornn::KeyPressedEvent& e = (Ornn::KeyPressedEvent&)event;
		//	if (e.GetKeyCode() == ORNN_KEY_TAB)
		//		ORNN_TRACE("Tab key is pressed (event)!");
		//	ORNN_TRACE("{0}", (char)e.GetKeyCode());
		//}
	}
private:
	std::shared_ptr<Ornn::Shader> m_Shader;
	std::shared_ptr<Ornn::VertexArray> m_VertexArray;

	std::shared_ptr<Ornn::Shader> m_BlueShader;
	std::shared_ptr<Ornn::VertexArray> m_SquareVA;

	Ornn::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.1f;
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 1.0f;
};

class Sandbox :public Ornn::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer);
	}
	~Sandbox()
	{

	}
};

Ornn::Application* Ornn::CreateApplication()
{
	return new Sandbox();
}