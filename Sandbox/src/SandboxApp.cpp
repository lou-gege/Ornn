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
		ORNN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ornn::Event& event) override
	{
		ORNN_TRACE("{0}", event);
	}
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