#pragma once

#include "Ornn/Layer.h"

#include "Ornn/Events/ApplicationEvent.h"
#include "Ornn/Events/KeyEvent.h"
#include "Ornn/Events/MouseEvent.h"

namespace Ornn {

	class ORNN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}