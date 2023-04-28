#pragma once

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace EvreninMotoru {

	Application::Application() {


	}

	Application::~Application() {


	}

	void Application::Run() {


		//TEST TO CATCH AND LOG EVENTS
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication)) {

			EM_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {

			EM_INFO(e);
		}
		//TEST

		while (true)
		{

		}
	}
}