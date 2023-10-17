#include "Application.h"

#include "Ornn/Events/ApplicationEvent.h"
#include "Ornn/Log.h"

namespace Ornn {

	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ORNN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ORNN_TRACE(e);
		}

		while (true)
		{

		}
	}
}