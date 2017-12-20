#include <stdlib.h>
#include <stdio.h>
#pragma once

class Chip8
{

public:
	Chip8();
	~Chip8();

	bool drawFlag;

	void debugerRender();
	void emulateCycle();
	bool loadApplication(const char * filename);

	//teclado do chip8
	unsigned char key[16];
	//graficos do chip8 2048 pixels
	unsigned char gfx[64 * 32];

private:
	//opcodes do sistema, 2 bytes
	unsigned short opcode;
	//memoria do chip8
	unsigned char memory[4096];
	//15 registros do cpu + registro 'carry flag'
	unsigned char V[16];

	//indice de registro
	unsigned short I;
	//contador de programa
	unsigned short pc;

	//interuptos e registros de hardware
	unsigned char delay_timer;
	//A campainha do sistema soa sempre que o temporizador de som atinge zero
	unsigned char sound_timer;

	//pilha utilizada pra lembrar qual localizacao na memoria caso chama da uma sub-rotina
	unsigned short stack[16];
	unsigned short sp;

	void initialize();

};