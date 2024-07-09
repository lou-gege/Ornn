#include <Ornn.h>
#include "Ornn/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace Ornn {

	class OrnnEditor :public Application
	{
	public:
		OrnnEditor()
			:Application("Ornn Editor")
		{
			PushLayer(new EditorLayer());
		}

		~OrnnEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new OrnnEditor();
	}

}