/**
 * 
 */

#pragma once

class Window {

	private:
		int m_Width;
		int m_Height;
		const char* m_Title;
		void* window_ptr;

		void makeContextCurrent();

	public:
		static Window* create( const char* title );
		static void init();
		static void free();
		void close();
		void destroy();

		bool shouldClose();
		float getAspectRatio();

		void setVSync( bool on );
		void setTitle( const char* title );
		void setSize( int width, int height );

};