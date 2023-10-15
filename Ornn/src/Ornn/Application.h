#pragma once

#include "Core.h"

namespace Ornn {

	class ORNN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in Client
	Application* CreateApplication();
}
