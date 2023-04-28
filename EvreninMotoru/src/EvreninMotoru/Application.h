#pragma once

#include "Core/Base.h"

namespace EvreninMotoru {

	class EvreninMotoru_API Application	{

	public: 
		Application(); 
		virtual ~Application();

		void Run();
	};

	//To be defined in the client
	Application* CreateApplication();
}
