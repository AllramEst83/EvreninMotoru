#pragma once

#ifdef EM_PLATFORM_WINDOWS

extern EvreninMotoru::Application* EvreninMotoru::CreateApplication();

int main(int argc, char** argv) {

	EvreninMotoru::Log::Init();
	EM_CORE_INFO("Testing");
	EM_CRITICAL("Noooooo");

	auto app = EvreninMotoru::CreateApplication();
	app->Run();
	delete app;
}

#endif

