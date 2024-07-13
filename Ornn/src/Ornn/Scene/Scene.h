#pragma once

#include "entt.hpp"

#include "Ornn/Core/Timestep.h"

namespace Ornn {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		//temp
		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep ts);

	private:
		entt::registry m_Registry;
	};

}