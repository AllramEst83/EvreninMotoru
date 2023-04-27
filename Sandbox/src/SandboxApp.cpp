
#pragma once
#include <EvreninMotoru.h>


class Sandbox : public EvreninMotoru::Application {

public:

	Sandbox() {


	}

	~Sandbox() {


	}
};

EvreninMotoru::Application* EvreninMotoru::CreateApplication() {

	return new Sandbox();
}
