#ifndef CODE_H
#define CODE_H



/*---- Constants */

// Colors
#define BLACK			0b0000'0000
#define RED				0b0000'0100
#define GREEN			0b0000'0010
#define BLUE			0b0000'0001
#define YELLOW			0b0000'0110
#define PINK			0b0000'0101
#define CYAN			0b0000'0011
#define WHITE			0b0000'0111

// Keys
#define KEY_RIGHT		0b0000'0001 // << 0
#define KEY_LEFT		0b0000'0010 // << 1
#define KEY_DOWN		0b0000'0100 // << 2
#define KEY_UP			0b0000'1000 // << 3
#define KEY_SELECT		0b0001'0000 // << 4
#define KEY_BACK		0b0010'0000 // << 5

// Keys' getters
#define GET_KEY_RIGHT	(Keys & KEY_RIGHT)
#define GET_KEY_LEFT	((Keys & KEY_LEFT) >> 1)
#define GET_KEY_DOWN	((Keys & KEY_DOWN) >> 2)
#define GET_KEY_UP		((Keys & KEY_UP) >> 3)
#define GET_KEY_SELECT	((Keys & KEY_SELECT) >> 4)
#define GET_KEY_BACK	((Keys & KEY_BACK) >> 5)

// Keys' getters (down)
#define GETD_KEY_RIGHT	(KeysDown & KEY_RIGHT)
#define GETD_KEY_LEFT	((KeysDown & KEY_LEFT) >> 1)
#define GETD_KEY_DOWN	((KeysDown & KEY_DOWN) >> 2)
#define GETD_KEY_UP		((KeysDown & KEY_UP) >> 3)
#define GETD_KEY_SELECT	((KeysDown & KEY_SELECT) >> 4)
#define GETD_KEY_BACK	((KeysDown & KEY_BACK) >> 5)

// Keys' getters (up)
#define GETU_KEY_RIGHT	(KeysUp & KEY_RIGHT)
#define GETU_KEY_LEFT	((KeysUp & KEY_LEFT) >> 1)
#define GETU_KEY_DOWN	((KeysUp & KEY_DOWN) >> 2)
#define GETU_KEY_UP		((KeysUp & KEY_UP) >> 3)
#define GETU_KEY_SELECT	((KeysUp & KEY_SELECT) >> 4)
#define GETU_KEY_BACK	((KeysUp & KEY_BACK) >> 5)

// Others
#define BUFFER(i, j)					Buffer[j][i]
#define VAR_WITH_MIN_BITS(var, bits)	((var) & ~(bits))
#define VAR_WITH_MAX_BITS(var, bits)	((var) | (bits))
#define GET_BITS(var, bits, pos)		(((var) & (bits)) >> (pos))
#define SET_BUFFER(i, j, c)				if (((i >= 0) && (i < DISPLAY_W)) && ((j >= 0) && (j < DISPLAY_H))) Buffer[j][i] = c;
#define MAIN(game, scene)				mainUpd = game ## scene ## Upd; mainDraw = game ## scene ## Draw; flag1 = 0; flag2 = 0;	// Changes main scene to scene
#define SET_TO_MIN(var, bits)			var = VAR_WITH_MIN_BITS(var, bits);
#define SET_TO_MAX(var, bits)			var = VAR_WITH_MAX_BITS(var, bits);
#define CHANGES(var, bits)				var ^= (bits);



/*---- Functions */

// Draws chars
void drawA(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x - 1, y + 1) = BUFFER(x, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawB(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawC(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawD(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawE(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawF(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = color;
}
void drawG(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 1, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawH(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawI(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawJ(byte x, byte y, char color)
{
	BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x + 2, y - 1) = color;
	BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawK(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawL(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawM(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawN(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x - 1, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawO(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawP(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = color;
}
void drawQ(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawR(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawS(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawT(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawU(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawV(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawW(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawX(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawY(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawZ(byte x, byte y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x - 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void draw0(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw1(byte x, byte y, char color)
{
	BUFFER(x, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw2(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw3(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw4(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x + 1, y + 2) = color;
}
void draw5(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw6(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw7(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x + 1, y + 2) = color;
}
void draw8(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw9(byte x, byte y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}

// Draws num
void drawNum(byte x, byte y, unsigned int num, byte color)
{
	// fazer um vetor de ponteiros pra funcao e varias coisas
	if (num)
	{
		for (char i = 0; num; i++)
		{
			switch (num % 10)
			{
				case 0:
					draw0(x, y, color);
					break;
				case 1:
					draw1(x, y, color);
					break;
				case 2:
					draw2(x, y, color);
					break;
				case 3:
					draw3(x, y, color);
					break;
				case 4:
					draw4(x, y, color);
					break;
				case 5:
					draw5(x, y, color);
					break;
				case 6:
					draw6(x, y, color);
					break;
				case 7:
					draw7(x, y, color);
					break;
				case 8:
					draw8(x, y, color);
					break;
				case 9:
					draw9(x, y, color);
					break;
				default:
					break;
			}

			x -= 4;
			num /= 10;
		}
	}
	else
	{
		draw0(x, y, color);
	}
}

#endif
