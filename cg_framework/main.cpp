#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	//    putPixel(glm::ivec2(50,50), glm::u8vec4(255,255,255,255));
	//    putPixel(glm::ivec2(300,300), glm::u8vec4(0,0,255,255));

	drawTriangle(glm::ivec2(128, 256), glm::u8vec4(255, 0, 0, 255), glm::ivec2(256, 128), glm::u8vec4(0, 255, 0, 255), glm::ivec2(512, 512), glm::u8vec4(0, 0, 255, 255));

	//    round_and_round();
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}