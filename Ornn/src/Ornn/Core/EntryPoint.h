#pragma once

#ifdef ORNN_PLATFORM_WINDOWS

extern Ornn::Application* Ornn::CreateApplication();

int main(int argc, char** argv)
{
	Ornn::Log::Init();
	//ORNN_CORE_WARN("Initialized Log!");
	//int a = 5;
	//ORNN_INFO("Hello! Var={0}", a);

	auto app = Ornn::CreateApplication();
	app->Run();
	delete app;
}

#endif // ORNN_PLATFORM_WINDOWS