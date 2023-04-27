#pragma once

#ifdef EM_PLATFORM_WINDOWS

extern EvreninMotoru::Application* EvreninMotoru::CreateApplication();

int main(int argc, char** argv) {

	printf("Hello");
	auto app = EvreninMotoru::CreateApplication();
	app->Run();
	delete app;
}

#endif

