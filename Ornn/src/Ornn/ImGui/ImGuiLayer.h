#pragma once

#include "Ornn/Core/Layer.h"

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
		virtual void OnEvent(Event& e) override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}