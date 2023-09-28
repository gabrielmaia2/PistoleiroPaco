#include "Emulator.h"

#include "Code.h"
#include "Vars.h"



/*---- Menu constants */

#define COLOR_MENU	RED



/*---- Declarations */

// Main scene
void MainMenuUpd();
void MainMenuDraw();

// Paco scene
void PacoStart();
void PacoEnd();
void PacoStartUpd();
void PacoStartDraw();
void PacoGameUpd();
void PacoGameDraw();
void PacoMenuUpd();
void PacoMenuDraw();
void PacoLoseUpd();
void PacoLoseDraw();
void PacoWonUpd();
void PacoWonDraw();

// Snake scene
void SnakeStart();
void SnakeEnd();
void SnakeStartUpd();
void SnakeStartDraw();
void SnakeGameUpd();
void SnakeGameDraw();
void SnakeMenuUpd();
void SnakeMenuDraw();
void SnakeLoseUpd();
void SnakeLoseDraw();
void SnakeWonUpd();
void SnakeWonDraw();



/*---- Paco vars */

// Global
int I, J;
char flag1, flag2;
byte spawnTimer;

// Player
byte plByte0; // Player's properties 1
byte plByte1; // Player's properties 2
byte plKills; // Player's kills
char plPosX; // Player's position in x
char plPosY; // Player's position in y

// Bullets
char *blPosX; // Bullets' pos in x
char *blPosY; // Bullets' pos in y
long blByte; // Bullets' properties

// Enemies
char *enPosX; // Enemies' pos in x
char *enPosY; // Enemies' pos in y
byte *enByte; // Enemies' properties
unsigned short enBlood; // Blood

// Clouds
byte clByte;
byte *clPosY;



/*---- Snake vars */

// Global
//int I, J;
//char flag1, flag2;

// Snake
//unsigned short enBlood; // snake properties
char *snakePosX; // Player's position in x
char *snakePosY; // Player's position in y

// Fruit
//byte plPosX; // fruit pos x
//byte plPosY; // fruit pos y



/*---- Paco functions */



// Sets vars to initial values
void PacoResetVars()
{
	// Sets values
	spawnTimer = flag1 = flag2 = I = J = 0;

	plByte0 = PL_START_0;
	plByte1 = PL_START_1;
	plKills = 0;
	plPosX = PL_START_POS_X;
	plPosY = PL_START_POS_Y;

	for (I = 0; I < MAX_BULLETS; I++)
	{
		blPosX[I] = 0;
		blPosY[I] = 0;
	}
	blByte = 0;

	for (I = 0; I < MAX_ENEMIES; I++)
	{
		enByte[I] = 0;
		enPosX[I] = 0;
		enPosY[I] = 0;
	}
	enBlood = 0;

	clByte = 0;
	for (I = 0; I < 4; I++)
	{
		GEN_CL_POS_Y(I);
	}

	// Start scene
	MAIN(Paco, Start);
}

// Updates player's position
void plUpdPos()
{
	// Walks
	if (GET_KEY_RIGHT)
	{
		SET_PL_DIR_RIGHT;
		PL_WALK;
	}
	else if (GET_KEY_LEFT)
	{
		SET_PL_DIR_LEFT;
		PL_WALK;
	}
	else
	{
		RESET_PL_FEET;
		RESET_PL_ROBE;
	}

	// Up / down
	if (!GET_PL_GRAV)
	{
		// Updates jump
		INC_PL_JUMP_IT;
		if (!GET_PL_JUMP_IT)
		{
			SET_PL_GRAV;
		}
	}
	else if (GET_KEY_UP && !GET_PL_JUMP)
	{
		REV_PL_GRAV;
		SET_PL_JUMP;
	}
	if (GET_KEY_DOWN)
	{
		// Down
	}

	INC_PL_POS_Y;
}

// Updates player's life
void plUpdLife()
{
	if (!GET_PL_LIFE)
	{
		MAIN(Paco, Lose);
	}
}

// Fires the bullets (max = MAX_BULLETS)
void plFire()
{
	// Finds empty position in bullets
	for (I = 0; (I < MAX_BULLETS) && GET_BL_TIMER_IT(I); I++);
	// If exists empty position
	if (I < MAX_BULLETS)
	{
		// Sets bullet's dir
		flag1 = GET_PL_DIR;
		if (flag1 == 1)
		{
			SET_BL_DIR_RIGHT(I);
		}
		else
		{
			SET_BL_DIR_LEFT(I);
		}

		// Sets bullet's pos
		blPosX[I] = plPosX + 2 * flag1;
		blPosY[I] = plPosY + 1;

		// Fires bullet
		RESET_BL_TIMER_IT(I);
		INC_BL_TIMER_IT(I);
	}
}

// Updates fire timer
void plUpdFire()
{
	if (GET_PL_FIRE_IT)
	{
		// Updates fire
		INC_PL_FIRE_IT;
	}
	else if (GET_KEY_SELECT)
	{
		// Fires
		plFire();

		INC_PL_FIRE_IT;
	}
}

// Updates bullets
void blUpd()
{
	for (I = 0; I < MAX_BULLETS; I++)
	{
		if (GET_BL_TIMER_IT(I))
		{
			// Updates bullet
			INC_BL_POS_X(I);
			INC_BL_TIMER_IT(I);
		}
	}
}

// Updates enemies'
void enUpdate()
{
	for (I = 0; I < MAX_ENEMIES; I++)
	{
		if (GET_EN_LIFE(I))
		{
			for (J = 0; J < MAX_BULLETS; J++)
			{
				if (GET_BL_TIMER_IT(J))
				{
					// Checks collision
					if (abs(enPosX[I] - blPosX[J]) < BL_SPEED / 2 + 1)
					{
						RESET_BL_TIMER_IT(J);
						DEC_EN_LIFE(I);
						if (!GET_EN_LIFE(I))
						{
							plKills++;
							INC_EN_BLOOD(I);
						}
					}
				}
			}
		}
		else if (GET_EN_BLOOD(I))
		{
			INC_EN_BLOOD(I);
		}
		if (GET_EN_LIFE(I))
		{
			// Walks
			if (enPosX[I] < plPosX - (EN_BOUNDS_X + PL_BOUNDS_X - 1))
			{
				SET_EN_DIR_RIGHT(I);
				EN_WALK(I);
			}
			else if (enPosX[I] > plPosX + (EN_BOUNDS_X + PL_BOUNDS_X - 1))
			{
				SET_EN_DIR_LEFT(I);
				EN_WALK(I);
			}
			else
			{
				// Collision with player

				RESET_EN_FEET(I);
				if (GET_EN_TIMER_IT(I))
				{
					RESET_EN_HAND(I);
				}
				else
				{
					SET_EN_HAND(I);
					DEC_PL_LIFE;
				}
				INC_EN_TIMER_IT(I);
			}

			INC_EN_POS_Y(I);
		}
		else if ((!spawnTimer) && (!GET_EN_BLOOD(I)))
		{
			spawnTimer = (spawnTimer + 1) % SPAWN_TICK;

			EN_SPAWN(I, random(0, 2) * (DISPLAY_W - 2 * EN_BOUNDS_X - 1) + EN_BOUNDS_X, 21);
			if (random(0, 2))
			{
				SET_EN_TYPE_1(I);
			}
			else
			{
				SET_EN_TYPE_2(I);
			}
		}
	}
}

// Updates clouds
void clUpdate()
{
	INC_CL_POS;
	if (GET_CL_POS >= CL_DISTANCE)
	{
		DEC_CL_POS;
		INC_CL_OFFS;
		GEN_CL_POS_Y(3 - GET_CL_OFFS);
	}
}

// Draws score
void drawScore()
{
	drawNum(SCORE_POS_X, SCORE_POS_Y, plKills, COLOR_SCORE);
}

// Draws life
void drawLife()
{
	flag1 = GET_PL_LIFE; // Gets life

	for (I = 0; I < flag1 / 4; I++)
		BUFFER(LIFE_POS_X + I - 7, LIFE_POS_Y) = COLOR_LIFE_BAR;
	for (; I < PL_LIFE / 4; I++)
		BUFFER(LIFE_POS_X + I - 7, LIFE_POS_Y) = BLACK;
}

// Draws a cloud
void drawCloud(char x, char y)
{
	for (J = -2; J < 2; J++)
	{
		SET_BUFFER(x + J, y - 1, COLOR_CLOUD);
	}
	for (J = -4; J < 5; J++)
	{
		SET_BUFFER(x + J, y, COLOR_CLOUD);
	}
	for (J = 0; J < 4; J++)
	{
		SET_BUFFER(x + J, y + 1, COLOR_CLOUD);
	}
}

// Draws blood
void drawBlood(byte i)
{
	// Gets pos
	byte x = enPosX[i];
	byte y = enPosY[i];

	switch (GET_EN_BLOOD(i))
	{
		case 0:
		{
			BUFFER(x, y) = RED;
		}
		break;
		case 1:
		{
			BUFFER(x - 1, y - 1) = BUFFER(x, y - 1) = RED;
			BUFFER(x, y) = BUFFER(x + 1, y) = RED;
			BUFFER(x, y + 1) = RED;
		}
		break;
		case 2:
		{
			BUFFER(x - 1, y - 2) = BUFFER(x + 1, y - 2) = RED;
			BUFFER(x - 2, y - 1) = BUFFER(x, y - 1) = BUFFER(x + 1, y - 1) = RED;
			BUFFER(x - 1, y) = BUFFER(x + 2, y) = RED;
			BUFFER(x - 2, y + 1) = BUFFER(x, y + 1) = RED;
			BUFFER(x - 1, y + 2) = BUFFER(x + 1, y + 2) = RED;
		}
		break;
		case 3:
		{
			SET_BUFFER(x - 3, y - 4, RED);
			SET_BUFFER(x + 3, y - 4, RED);
			BUFFER(x + 1, y - 3) = RED;
			BUFFER(x - 2, y - 2) = RED;
			BUFFER(x + 1, y - 2) = RED;
			SET_BUFFER(x - 4, y - 1, RED);
			BUFFER(x, y - 1) = RED;
			SET_BUFFER(x + 3, y - 1, RED);
			BUFFER(x - 1, y + 1) = RED;
			BUFFER(x + 2, y + 1) = RED;
			BUFFER(x + 2, y + 2) = RED;
			SET_BUFFER(x + 4, y + 2, RED);
			BUFFER(x - 2, y + 3) = RED;
			BUFFER(x, y + 3) = RED;
			BUFFER(x, y + 4) = RED;
		}
		break;
	}
}

// Draws bullets
void drawBullets()
{
	for (I = 0; I < MAX_BULLETS; I++)
	{
		// If bullet(i) exists
		if (GET_BL_TIMER_IT(I))
		{
			// Gets position
			flag1 = blPosX[I];
			flag2 = blPosY[I];

			// Draws bullet(i)
			SET_BUFFER(flag1 - GET_BL_DIR(I), flag2, BLACK);
			SET_BUFFER(flag1, flag2, RED);
		}
	}
}

// Draws player
void drawPlayer(byte x, byte y)
{
	flag1 = GET_PL_DIR; // Gets direction

	BUFFER(x - 1 * flag1, y - 6) = BUFFER(x, y - 6) = BUFFER(x + 1 * flag1, y - 6) = COLOR_PL_HAT;

	BUFFER(x - 1 * flag1, y - 5) = BUFFER(x, y - 5) = BUFFER(x + 1 * flag1, y - 5) = COLOR_PL_PANTS;

	BUFFER(x - 2 * flag1, y - 4) = BUFFER(x - 1 * flag1, y - 4) = BUFFER(x, y - 4) = BUFFER(x + 1 * flag1, y - 4) = BUFFER(x + 2 * flag1, y - 4) = COLOR_PL_HAT;

	BUFFER(x - 1 * flag1, y - 3) = BUFFER(x, y - 3) = BUFFER(x + 1 * flag1, y - 3) = COLOR_PL_SKIN;

	BUFFER(x + 1 * flag1, y - 2) = COLOR_PL_EYE;
	BUFFER(x - 1 * flag1, y - 2) = BUFFER(x, y - 2) = COLOR_PL_SKIN;

	BUFFER(x - 1 * flag1, y - 1) = BUFFER(x, y - 1) = BUFFER(x + 1 * flag1, y - 1) = COLOR_PL_SKIN;

	BUFFER(x, y) = COLOR_PL_SHIRT;

	BUFFER(x, y + 1) = COLOR_PL_SKIN;

	BUFFER(x, y + 2) = COLOR_PL_SKIN;

	BUFFER(x, y + 3) = COLOR_PL_SHIRT;

	BUFFER(x, y + 4) = COLOR_PL_PANTS;

	BUFFER(x, y + 5) = COLOR_PL_PANTS;

	// Draws feet
	if (GET_PL_FEET || GET_PL_JUMP)
		BUFFER(x - 1, y + 6) = BUFFER(x + 1, y + 6) = COLOR_PL_FEET;
	else
		BUFFER(x, y + 6) = COLOR_PL_FEET;

	// Draws robe
	flag2 = GET_PL_ROBE_POS;
	BUFFER(x - 1 * flag1, y) = COLOR_PL_ROBE;
	BUFFER(x - (1 + flag2) * flag1, y + 1) = COLOR_PL_ROBE;
	if (GET_PL_ROBE)
	{
		SET_BUFFER(x - (2 + flag2) * flag1, y + 2 - flag2, COLOR_PL_ROBE);
		SET_BUFFER(x - (3 + flag2) * flag1, y + 3 - flag2, COLOR_PL_ROBE);
		SET_BUFFER(x - (4 + flag2) * flag1, y + 4 - flag2, COLOR_PL_ROBE);
	}
	else
	{
		BUFFER(x - 1 * flag1, y + 2) = COLOR_PL_ROBE;
		BUFFER(x - 1 * flag1, y + 3) = COLOR_PL_ROBE;
		BUFFER(x - 1 * flag1, y + 4) = COLOR_PL_ROBE;
		BUFFER(x - 1 * flag1, y + 5) = COLOR_PL_ROBE;
	}

	// Draws gun
	if (GET_KEY_SELECT)
	{
		BUFFER(x + 1 * flag1, y + 1) = BUFFER(x + 2 * flag1, y + 1) = COLOR_GUN;

		BUFFER(x + 1 * flag1, y + 2) = COLOR_GUN;
	}
}

// Draws enemy
void drawEnemy1(byte i)
{
	// Gets pos
	byte x = enPosX[i];
	byte y = enPosY[i];

	flag1 = GET_EN_DIR(i); // Gets direction

	BUFFER(x - 1 * flag1, y - 6) = BUFFER(x, y - 6) = BUFFER(x + 1 * flag1, y - 6) = COLOR_EN1_HAT;

	BUFFER(x - 1 * flag1, y - 5) = BUFFER(x, y - 5) = BUFFER(x + 1 * flag1, y - 5) = COLOR_EN1_PANTS;

	BUFFER(x - 2 * flag1, y - 4) = BUFFER(x - 1 * flag1, y - 4) = BUFFER(x, y - 4) = BUFFER(x + 1 * flag1, y - 4) = BUFFER(x + 2 * flag1, y - 4) = COLOR_EN1_HAT;

	BUFFER(x - 1 * flag1, y - 3) = BUFFER(x, y - 3) = BUFFER(x + 1 * flag1, y - 3) = COLOR_EN1_SKIN;

	BUFFER(x + 1 * flag1, y - 2) = COLOR_EN1_EYE;
	BUFFER(x - 1 * flag1, y - 2) = BUFFER(x, y - 2) = COLOR_EN1_SKIN;

	BUFFER(x - 1 * flag1, y - 1) = BUFFER(x, y - 1) = BUFFER(x + 1 * flag1, y - 1) = COLOR_EN1_SKIN;

	BUFFER(x, y) = COLOR_EN1_SHIRT;

	BUFFER(x, y + 1) = COLOR_EN1_SKIN;

	BUFFER(x, y + 3) = COLOR_EN1_SHIRT;

	BUFFER(x, y + 4) = COLOR_EN1_PANTS;

	BUFFER(x, y + 5) = COLOR_EN1_PANTS;

	// Draws arm
	if (GET_EN_HAND(i))
	{
		BUFFER(x, y + 2) = COLOR_EN1_SHIRT;

		BUFFER(x + 1 * flag1, y + 1) = COLOR_EN1_SKIN;
	}
	else
	{
		BUFFER(x, y + 2) = COLOR_EN1_SKIN;
	}

	// Draws feet
	if (GET_EN_FEET(i))
		BUFFER(x - 1, y + 6) = BUFFER(x + 1, y + 6) = COLOR_EN1_FEET;
	else
		BUFFER(x, y + 6) = COLOR_EN1_FEET;
}

// Draws enemy
void drawEnemy2(byte i)
{
	// Gets pos
	byte x = enPosX[i];
	byte y = enPosY[i];

	flag1 = GET_EN_DIR(i); // Gets direction

	BUFFER(x - 1 * flag1, y - 6) = BUFFER(x, y - 6) = BUFFER(x + 1 * flag1, y - 6) = COLOR_EN2_HAT;

	BUFFER(x - 1 * flag1, y - 5) = BUFFER(x, y - 5) = BUFFER(x + 1 * flag1, y - 5) = COLOR_EN2_PANTS;

	BUFFER(x - 2 * flag1, y - 4) = BUFFER(x - 1 * flag1, y - 4) = BUFFER(x, y - 4) = BUFFER(x + 1 * flag1, y - 4) = BUFFER(x + 2 * flag1, y - 4) = COLOR_EN2_HAT;

	BUFFER(x - 1 * flag1, y - 3) = BUFFER(x, y - 3) = BUFFER(x + 1 * flag1, y - 3) = COLOR_EN2_SKIN;

	BUFFER(x + 1 * flag1, y - 2) = COLOR_EN2_EYE;
	BUFFER(x - 1 * flag1, y - 2) = BUFFER(x, y - 2) = COLOR_EN2_SKIN;

	BUFFER(x - 1 * flag1, y - 1) = BUFFER(x, y - 1) = BUFFER(x + 1 * flag1, y - 1) = COLOR_EN2_SKIN;

	BUFFER(x, y) = COLOR_EN2_SHIRT;

	BUFFER(x, y + 1) = COLOR_EN2_SKIN;

	BUFFER(x, y + 3) = COLOR_EN2_SHIRT;

	BUFFER(x, y + 4) = COLOR_EN2_PANTS;

	BUFFER(x, y + 5) = COLOR_EN2_PANTS;

	// Draws arm
	if (GET_EN_HAND(i))
	{
		BUFFER(x, y + 2) = COLOR_EN2_SHIRT;

		BUFFER(x + 1 * flag1, y + 1) = COLOR_EN2_SKIN;
	}
	else
	{
		BUFFER(x, y + 2) = COLOR_EN2_SKIN;
	}

	// Draws feet
	if (GET_EN_FEET(i))
		BUFFER(x - 1, y + 6) = BUFFER(x + 1, y + 6) = COLOR_EN2_FEET;
	else
		BUFFER(x, y + 6) = COLOR_EN2_FEET;
}

// Draws enemies
void drawEnemies()
{
	for (I = 0; I < MAX_ENEMIES; I++)
	{
		if (GET_EN_LIFE(I))
		{
			if (GET_EN_TYPE(I) == 2)
			{
				drawEnemy2(I);
			}
			else
			{
				drawEnemy1(I);
			}
		}
		else if (GET_EN_BLOOD(I))
		{
			drawBlood(I);
		}
	}
}

// Draws background
void drawBackground()
{
	// Draws sky
	drawBack(COLOR_SKY);

	// Draws sun
	for (I = 30; I < 34; I++)
		for (J = 5; J < 9; J++)
			BUFFER(I, J) = COLOR_SUN;

	// Draws grass
	for (I = 0; I < DISPLAY_W; I++)
		for (J = 27; J < 28; J++)
			BUFFER(I, J) = COLOR_GRASS;

	// Draws dirt
	for (I = 0; I < DISPLAY_W; I++)
		for (J = 28; J < 30; J++)
			BUFFER(I, J) = COLOR_DIRT;
}

// Draws clouds
void drawClouds()
{
	for (I = 0; I < 4; I++)
	{
		drawCloud(GET_CL_POS_X(I) - 4, clPosY[I]);
	}
}



/*---- Snake functions */

void fruitGen()
{
	plPosX = random(0, DISPLAY_W);
	plPosY = random(0, DISPLAY_H);
}

void SnakeResetVars()
{
	flag1 = flag2 = 0;
	enBlood = SNAKE_BYTE_START;
	snakePosX[0] = 20;
	snakePosY[0] = 0;
	SET_SNAKE_DIR_DOWN;

	MAIN(Snake, Start);
	fruitGen();
}

void snakeUpd()
{
	flag1 = GET_SNAKE_PREV_POS(GET_SNAKE_SIZE);
	flag2 = GET_SNAKE_TAIL;
	for (I = flag2; I < flag1 + flag2; I++)
	{
		if ((snakePosX[I] == snakePosX[GET_SNAKE_HEAD]) && (snakePosY[I] == snakePosY[GET_SNAKE_HEAD]))
		{
			MAIN(Snake, Lose);
		}
	}
	if (GET_SNAKE_SIZE == SNAKE_MAX_SIZE)
	{
		MAIN(Snake, Won);
	}
}

void snakeUpdPos()
{
	if ((GET_KEY_UP) && (GET_SNAKE_DIR_Y != 1))
	{
		SET_SNAKE_DIR_UP;
	}
	else if ((GET_KEY_DOWN) && (GET_SNAKE_DIR_Y != -1))
	{
		SET_SNAKE_DIR_DOWN;
	}
	else if ((GET_KEY_LEFT) && (GET_SNAKE_DIR_X != 1))
	{
		SET_SNAKE_DIR_LEFT;
	}
	else if ((GET_KEY_RIGHT) && (GET_SNAKE_DIR_X != -1))
	{
		SET_SNAKE_DIR_RIGHT;
	}

	if ((snakePosX[GET_SNAKE_HEAD] == plPosX) && (snakePosY[GET_SNAKE_HEAD] == plPosY))
	{
		fruitGen();
	}
	else
	{
		INC_SNAKE_TAIL;
	}

	INC_SNAKE_HEAD;
	SET_SNAKE_NEW_HEAD;

	if ((snakePosX[GET_SNAKE_HEAD] < 0) ||
		(snakePosX[GET_SNAKE_HEAD] >= DISPLAY_W) ||
		(snakePosY[GET_SNAKE_HEAD] < 0) ||
		(snakePosY[GET_SNAKE_HEAD] >= DISPLAY_H))
	{
		MAIN(Snake, Lose);
	}
}

void drawSnake()
{
	flag1 = GET_SNAKE_SIZE;
	flag2 = GET_SNAKE_TAIL;
	for (I = flag2; I < flag1 + flag2; I++)
	{
		SET_BUFFER(snakePosX[I % SNAKE_MAX_SIZE], snakePosY[I % SNAKE_MAX_SIZE], COLOR_SNAKE);
	}
}

void drawFruit()
{
	BUFFER(plPosX, plPosY) = COLOR_FRUIT;
}



/*---- Paco scene functions */

// Start
void PacoStart()
{
	blPosX = (char*) malloc(sizeof(char) * MAX_BULLETS);
	blPosY = (char*) malloc(sizeof(char) * MAX_BULLETS);
	enPosX = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enPosY = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enByte = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	clPosY = (byte*) malloc(sizeof(byte) * 4);

	PacoResetVars();
}

void PacoEnd()
{
	free(blPosX);
	free(blPosY);
	free(enPosX);
	free(enPosY);
	free(enByte);
	free(clPosY);
}

void PacoStartUpd()
{
	flag1 = (flag1 + 1) % 16;
	if (GETD_KEY_BACK)
	{
		MAIN(Main, Menu);
	}
	else if (GETD_KEY_SELECT)
	{
		MAIN(Paco, Game);
	}
}

void PacoStartDraw()
{
	// Background
	drawBack(BLACK);

	// Pistoleiro
	drawP(8, 4, WHITE);
	drawI(14, 4, WHITE);
	drawS(20, 4, WHITE);
	drawT(26, 4, WHITE);
	drawO(32, 4, WHITE);
	drawL(8, 10, WHITE);
	drawE(14, 10, WHITE);
	drawI(20, 10, WHITE);
	drawR(26, 10, WHITE);
	drawO(32, 10, WHITE);

	// Paco
	J = (flag1 % 4) / 2;
	I = J ? RED : PINK;
	J = J ? PINK : RED;
	drawP(11, 16, I);
	drawA(17, 16, J);
	drawC(23, 16, I);
	drawO(29, 16, J);

	// Draws loading dots
	for (I = 0; I < (flag1 % 16) / 2; I++)
		BUFFER(14 + I * 2, 22) = I + 1;
}

void PacoGameUpd()
{
	spawnTimer = (spawnTimer + 1) % SPAWN_TICK;

	blUpd();
	plUpdPos();
	plUpdLife();
	plUpdFire();
	enUpdate();
	clUpdate();

	// Updates menu
	if (plKills == MAX_KILLS)
	{
		MAIN(Paco, Won);
	}
	else if (GETD_KEY_BACK)
	{
		MAIN(Paco, Menu);
	}
}

void PacoGameDraw()
{
	drawBackground();
	drawEnemies();
	drawPlayer(plPosX, plPosY);
	drawBullets();
	drawClouds();
	drawLife();
	drawScore();
}

void PacoMenuUpd()
{
	// Changes option
	if (GET_KEY_DOWN && (flag1 < OPT_NUMBER - 1))
		flag1++;
	else if (GET_KEY_UP && (flag1 > 0))
		flag1--;

	// Selects option
	if (GETD_KEY_SELECT)
	{
		switch (flag1)
		{
			case 0: // Back
				MAIN(Paco, Game);
				break;
			case 1: // Quit
				PacoEnd();
				MAIN(Main, Menu);
				break;
			default:
				break;
		}
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void PacoMenuDraw()
{
	drawBack(BLACK);

	J = (flag2 % 4) / 2;
	I = J ? RED : PINK;
	J = J ? PINK : RED;

	// Back
	if (flag1 == 0)
	{
		drawB(11, 9, I);
		drawA(17, 9, J);
		drawC(23, 9, I);
		drawK(29, 9, J);
	}
	else
	{
		drawB(11, 9, WHITE);
		drawA(17, 9, WHITE);
		drawC(23, 9, WHITE);
		drawK(29, 9, WHITE);
	}

	// Quit
	if (flag1 == 1)
	{
		drawQ(11, 19, I);
		drawU(17, 19, J);
		drawI(23, 19, I);
		drawT(29, 19, J);
	}
	else
	{
		drawQ(11, 19, WHITE);
		drawU(17, 19, WHITE);
		drawI(23, 19, WHITE);
		drawT(29, 19, WHITE);
	}
}

void PacoLoseUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		PacoResetVars();
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void PacoLoseDraw()
{
	drawBack(BLACK);

	// You lose
	drawY(14, 5, WHITE);
	drawO(20, 5, WHITE);
	drawU(26, 5, WHITE);
	drawL(11, 11, WHITE);
	drawO(17, 11, WHITE);
	drawS(23, 11, WHITE);
	drawE(29, 11, WHITE);

	// Back
	J = (flag2 % 4) / 2;
	I = J ? RED : PINK;
	J = J ? PINK : RED;
	drawB(11, 21, I);
	drawA(17, 21, J);
	drawC(23, 21, I);
	drawK(29, 21, J);
}

void PacoWonUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		PacoResetVars();
	}

	flag1 = (flag1 + 1) % 8;
}

void PacoWonDraw()
{
	drawBack(BLACK);

	drawY(14, 9, flag1);
	drawO(20, 9, (flag1 + 5) % 8);
	drawU(26, 9, (flag1 + 10) % 8);
	drawW(14, 20, (flag1 + 15) % 8);
	drawO(20, 20, (flag1 + 20) % 8);
	drawN(26, 20, (flag1 + 25) % 8);
}



/*---- Snake scene functions */

void SnakeStart()
{
	snakePosX = (byte*) malloc(sizeof(byte) * SNAKE_MAX_SIZE);
	snakePosY = (byte*) malloc(sizeof(byte) * SNAKE_MAX_SIZE);

	SnakeResetVars();
}

void SnakeEnd()
{
	free(snakePosX);
	free(snakePosY);
}

void SnakeStartUpd()
{
	flag1 = (flag1 + 1) % 16;
	if (GETD_KEY_BACK)
	{
		MAIN(Main, Menu);
	}
	else if (GETD_KEY_SELECT)
	{
		MAIN(Snake, Game);
	}
}

void SnakeStartDraw()
{
	// Background
	drawBack(BLACK);

	// Snake game
	drawS(8, 6, WHITE);
	drawN(14, 6, WHITE);
	drawA(20, 6, WHITE);
	drawK(26, 6, WHITE);
	drawE(32, 6, WHITE);
	drawG(11, 14, WHITE);
	drawA(17, 14, WHITE);
	drawM(23, 14, WHITE);
	drawE(29, 14, WHITE);

	// Start
	J = (flag1 % 4) / 2;
	I = J ? BLUE : CYAN;
	drawS(8, 23, I);
	drawT(14, 23, I);
	drawA(20, 23, I);
	drawR(26, 23, I);
	drawT(32, 23, I);
}

void SnakeGameUpd()
{
	snakeUpd();
	snakeUpdPos();

	// Updates menu
	if (GETD_KEY_BACK)
	{
		MAIN(Snake, Menu);
	}
}

void SnakeGameDraw()
{
	drawBack(COLOR_BACK);
	drawFruit();
	drawSnake();
}

void SnakeMenuUpd()
{
	// Changes option
	if (GET_KEY_DOWN && (flag1 < OPT_NUMBER - 1))
		flag1++;
	else if (GET_KEY_UP && (flag1 > 0))
		flag1--;

	// Selects option
	if (GETD_KEY_SELECT)
	{
		switch (flag1)
		{
			case 0: // Back
				MAIN(Snake, Game);
				break;
			case 1: // Quit
				SnakeEnd();
				MAIN(Main, Menu);
				break;
			default:
				break;
		}
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void SnakeMenuDraw()
{
	drawBack(BLACK);

	J = (flag2 % 4) / 2;
	I = J ? BLUE : CYAN;

	// Back
	if (flag1 == 0)
	{
		drawB(11, 9, I);
		drawA(17, 9, I);
		drawC(23, 9, I);
		drawK(29, 9, I);
	}
	else
	{
		drawB(11, 9, WHITE);
		drawA(17, 9, WHITE);
		drawC(23, 9, WHITE);
		drawK(29, 9, WHITE);
	}

	// Quit
	if (flag1 == 1)
	{
		drawQ(11, 19, I);
		drawU(17, 19, I);
		drawI(23, 19, I);
		drawT(29, 19, I);
	}
	else
	{
		drawQ(11, 19, WHITE);
		drawU(17, 19, WHITE);
		drawI(23, 19, WHITE);
		drawT(29, 19, WHITE);
	}
}

void SnakeLoseUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		SnakeResetVars();
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void SnakeLoseDraw()
{
	drawBack(BLACK);

	// You lose
	drawY(14, 5, WHITE);
	drawO(20, 5, WHITE);
	drawU(26, 5, WHITE);
	drawL(11, 11, WHITE);
	drawO(17, 11, WHITE);
	drawS(23, 11, WHITE);
	drawE(29, 11, WHITE);

	// Back
	J = (flag2 % 4) / 2;
	I = J ? BLUE : CYAN;
	drawB(11, 21, I);
	drawA(17, 21, I);
	drawC(23, 21, I);
	drawK(29, 21, I);
}

void SnakeWonUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		SnakeResetVars();
	}

	flag1 = (flag1 + 1) % 8;
}

void SnakeWonDraw()
{
	drawBack(BLACK);

	drawY(14, 9, flag1);
	drawO(20, 9, (flag1 + 5) % 8);
	drawU(26, 9, (flag1 + 10) % 8);
	drawW(14, 20, (flag1 + 15) % 8);
	drawO(20, 20, (flag1 + 20) % 8);
	drawN(26, 20, (flag1 + 25) % 8);
}



/*---- Main functions */

void MainMenuUpd()
{
	// Changes option
	if (GET_KEY_DOWN && (flag1 < OPT_NUMBER - 1))
		flag1++;
	else if (GET_KEY_UP && (flag1 > 0))
		flag1--;

	// Selects option
	if (GETD_KEY_SELECT)
	{
		switch (flag1)
		{
			case 0: // Paco
				PacoStart();
				MAIN(Paco, Start);
				break;
			case 1: // Snake
				SnakeStart();
				MAIN(Snake, Start);
				break;
			default:
				break;
		}
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;

	if (GETD_KEY_BACK)
	{
		// Ends program
		quit();
	}
}

void MainMenuDraw()
{
	drawBack(BLACK);

	drawM(8, 5, COLOR_MENU);
	drawE(16, 5, COLOR_MENU);
	drawN(24, 5, COLOR_MENU);
	drawU(32, 5, COLOR_MENU);

	J = (flag2 % 4) / 2;
	I = J ? BLUE : CYAN;

	// Back
	if (flag1 == 0)
	{
		drawP(11, 16, I);
		drawA(17, 16, I);
		drawC(23, 16, I);
		drawO(29, 16, I);
	}
	else
	{
		drawP(11, 16, WHITE);
		drawA(17, 16, WHITE);
		drawC(23, 16, WHITE);
		drawO(29, 16, WHITE);
	}

	// Quit
	if (flag1 == 1)
	{
		drawS(8, 23, I);
		drawN(14, 23, I);
		drawA(20, 23, I);
		drawK(26, 23, I);
		drawE(32, 23, I);
	}
	else
	{
		drawS(8, 23, WHITE);
		drawN(14, 23, WHITE);
		drawA(20, 23, WHITE);
		drawK(26, 23, WHITE);
		drawE(32, 23, WHITE);
	}
}

//

// Start
void start()
{
	MAIN(Main, Menu);
}
