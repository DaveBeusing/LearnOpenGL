# Learn OpenGL
With this repository I track my "successes" in learning and understanding OpenGL while using [learnopengl.com](https://learnopengl.com/) by Joey de Vries.<br>
This repo, even if it contains "equivalent code", has no connection to the source repo https://github.com/JoeyDeVries/LearnOpenGL <br>
Please use the original for your own experiences, I cannot give any support.<br><br>
I use VSCode as IDE and windows-gcc-x64 for compiling.


#### Dependancies
[GLAD OpenGL 3.3 Core](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=compatibility&loader=on)<br>
[GLFW 3.3.8 Win64 Binaries](https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN64.zip)<br>
[stb single-file public domain libraries for C/C++](https://github.com/nothings/stb)<br>
[OpenGL Mathematics (GLM)](https://github.com/g-truc/glm)<br>

>Be sure to include GLAD before GLFW. The include file for GLAD includes the required OpenGL headers behind the scenes (like GL/gl.h) so be sure to include GLAD before other header files that require OpenGL (like GLFW).<br><br>
#include <glad/glad.h><br>
#include <GLFW/glfw3.h>

>Define STB_IMAGE_IMPLEMENTATION before you include stb_image.h to create the implementation.<br><br>
 #define STB_IMAGE_IMPLEMENTATION<br>
 #include <stb/stb_image.h><br>

#### Additional reading
[https://learnopengl.com](https://learnopengl.com/)<br>
[https://www.scratchapixel.com](https://www.scratchapixel.com/index.html)<br>
[https://docs.gl](https://docs.gl/)

