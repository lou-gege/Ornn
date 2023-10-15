#include <Ornn.h>

class Sandbox :public Ornn::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Ornn::Application* Ornn::CreateApplication()
{
	return new Sandbox();
}