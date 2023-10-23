#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Ornn/Events/ApplicationEvent.h"
#include "Ornn/LayerStack.h"

namespace Ornn {

	class ORNN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in Client
	Application* CreateApplication();
}
