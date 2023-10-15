#pragma once

#ifdef ORNN_PLATFORM_WINDOWS

extern Ornn::Application* Ornn::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ornn::CreateApplication();
	app->Run();
	delete app;
}

#endif // ORNN_PLATFORM_WINDOWS