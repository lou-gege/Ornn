#include <Ornn.h>

class ExampleLayer :public Ornn::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//ORNN_INFO("ExampleLayer::Update");
		if (Ornn::Input::IsKeyPressed(ORNN_KEY_TAB))
			ORNN_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Ornn::Event& event) override
	{
		//ORNN_TRACE("{0}", event);
		if (event.GetEventType() == Ornn::EventType::KeyPressed)
		{
			Ornn::KeyPressedEvent& e = (Ornn::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ORNN_KEY_TAB)
				ORNN_TRACE("Tab key is pressed (event)!");
			ORNN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox :public Ornn::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer);
		PushLayer(new Ornn::ImGuiLayer);
	}
	~Sandbox()
	{

	}
};

Ornn::Application* Ornn::CreateApplication()
{
	return new Sandbox();
}