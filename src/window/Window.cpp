/**
 * 
 */


static void resizeCallback( GLFWwindow* window_ptr, int Width, int Height ){

	Window* userWindow = (Window*)glfwGetWindowUserPointer(windowPtr);
	userWindow->width = Width;
	userWindow->height = Height;
	glViewport( 0, 0, Width, Height );

}


void Window::init(){
	if( !glfwInit() ){
		std::cout << "Failed to initialize GLFW" << std::endl;
		return nullptr;
	}

	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

}


Window* Window::create( const char* title ){

	Window* window = new Window();

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	if( !monitor ){
		std::cout << "Failed to get primary monitor" << std::endl;
		return nullptr;
	}

	const GLFWvidmode* videomode = glfwGetVideoMode( monitor );
	if( !videomode ){
		std::cout << "Failed to get video mode of primary monitor." << std::endl;
		return nullptr;
	}

	std::cout << "Monitor size: " << videomode->width << "x" << videomode->height << std::endl;

	//minimum 300x200
	window->width = glm::clamp( videomode->width / 2, 300, INT_MAX );
	window->height = glm::clamp( videomode->height / 2, 200, INT_MAX );
	window->title = title;

	window->window_ptr = (void*)glfwCreateWindow( window->width, window->height, title, nullptr, nullptr );
	if( window->window_ptr == nullptr ){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glfwSetWindowUserPointer( (GLFWwindow*)window->window_ptr, (void*)(window) );
	window->makeContextCurrent();

	//Input callbacks

	int monitorX;
	int monitorY;
	glfwGetMonitorPos( monitor, &monitorX, &monitorY );

	int windowWidth;
	int windowHeight;
	glfwGetWindowSize( (GLFWwindow*)window->window_ptr, &windowWidth, &windowHeight );

	glfwSetWindowPos( (GLFWwindow*)window->window_ptr, monitorX + ( videomode->width - windowWidth ) / 2, monitorY + ( videomode->height - windowHeight ) / 2 );

	window->setVSync( true );

	return window;
}


void Window::setTitle( const char* title ){
	glfwSetWindowTitle( (GLFWwindow*)window_ptr, title );
}


void Window::setSize( int width, int height ){
	glfwSetWindowSize( (GLFWwindow*)window_ptr, width, height );
}


void Window::makeContextCurrent(){
	glfwMakeContextCurrent( (GLFWwindow*)window_ptr );
}


void Window::close(){
	glfwSetWindowShouldClose( (GLFWwindow*)window_ptr, GLFW_TRUE );
}


bool Window::shouldClose(){
	return glfwWindowShouldClose( (GLFWwindow*)window_ptr );
}


float Window::getAspectRatio() const {
	return (float) m_Width / (float) m_Height;
}


void Window::setVSync( bool on ){
	if( on ){
		glfwSwapInterval(1);
	}
	else {
		glfwSwapInterval(0);
	}
}


void Window::free(){
	glfwTerminate();
}