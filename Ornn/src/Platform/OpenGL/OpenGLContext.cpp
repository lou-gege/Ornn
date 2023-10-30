#include "pch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Ornn {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		ORNN_CORE_ASSERT(windowHandle, "Window handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);//不知道用法
		ORNN_CORE_ASSERT(status, "Failed to initialize Glad!");

		ORNN_CORE_INFO("OpenGL Info:");
		ORNN_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		ORNN_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		ORNN_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}