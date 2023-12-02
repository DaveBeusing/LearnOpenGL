/**
 * 
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback( GLFWwindow* window, int width, int height );
void processInput( GLFWwindow *window );


const unsigned int screenWidth = 1280;
const unsigned int screenHeight = 720;
const char* screenTitle = "LearnOpenGL";

int main( void ){


    //  instantiate the GLFW window
    if( !glfwInit() ){
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );


    // Next we're required to create a window object. This window object holds all the windowing data and is required by most of GLFW's other functions.
    GLFWwindow* window = glfwCreateWindow( screenWidth, screenHeight, screenTitle, NULL, NULL );
    if( window == NULL ){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent( window );


    // Declare callback for resizing events
    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );


    // initialize GLAD and load all OpenGL function pointers before we call any OpenGL function
    if( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress) ) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }  

    
    // We have to tell OpenGL the size of the rendering window so OpenGL knows how we want to display the data and coordinates with respect to the window.
    glViewport( 0, 0, screenWidth, screenHeight );


    // render loop
    while( !glfwWindowShouldClose( window ) ){

        // handle key inputs
        processInput(window);

        // render
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers( window );
        glfwPollEvents();
    }


    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput( GLFWwindow *window ){
    if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ){
        glfwSetWindowShouldClose( window, true );
    }
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback( GLFWwindow* window, int width, int height ){
    glViewport( 0, 0, width, height );
}