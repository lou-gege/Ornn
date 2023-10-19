#include "pch.h"
#include "Application.h"

#include "Ornn/Events/ApplicationEvent.h"
#include "Ornn/Log.h"

namespace Ornn {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}