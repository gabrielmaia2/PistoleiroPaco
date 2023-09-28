/*---- Constants */

// Arduino
#define nop __asm__("nop \n");

// Colors
#define BLACK			0b00000000
#define RED				0b00000001
#define GREEN			0b00000010
#define BLUE			0b00000100
#define YELLOW			0b00000011
#define PINK			0b00000101
#define CYAN			0b00000110
#define WHITE			0b00000111

// Keys
#define KEY_RIGHT		0b00000001 // << 0
#define KEY_LEFT		0b00000010 // << 1
#define KEY_DOWN		0b00000100 // << 2
#define KEY_UP			0b00001000 // << 3
#define KEY_SELECT		0b00010000 // << 4
#define KEY_BACK		0b00100000 // << 5

// Keys' getters
#define GET_KEY_RIGHT		(Keys & KEY_RIGHT)
#define GET_KEY_LEFT		((Keys & KEY_LEFT) >> 1)
#define GET_KEY_DOWN		((Keys & KEY_DOWN) >> 2)
#define GET_KEY_UP			((Keys & KEY_UP) >> 3)
#define GET_KEY_SELECT		((Keys & KEY_SELECT) >> 4)
#define GET_KEY_BACK		((Keys & KEY_BACK) >> 5)

// Keys' getters (down)
#define GETD_KEY_RIGHT		(KeysDown & KEY_RIGHT)
#define GETD_KEY_LEFT		((KeysDown & KEY_LEFT) >> 1)
#define GETD_KEY_DOWN		((KeysDown & KEY_DOWN) >> 2)
#define GETD_KEY_UP			((KeysDown & KEY_UP) >> 3)
#define GETD_KEY_SELECT		((KeysDown & KEY_SELECT) >> 4)
#define GETD_KEY_BACK		((KeysDown & KEY_BACK) >> 5)

// Keys' getters (up)
#define GETU_KEY_RIGHT		(KeysUp & KEY_RIGHT)
#define GETU_KEY_LEFT		((KeysUp & KEY_LEFT) >> 1)
#define GETU_KEY_DOWN		((KeysUp & KEY_DOWN) >> 2)
#define GETU_KEY_UP			((KeysUp & KEY_UP) >> 3)
#define GETU_KEY_SELECT		((KeysUp & KEY_SELECT) >> 4)
#define GETU_KEY_BACK		((KeysUp & KEY_BACK) >> 5)



/*---- Constants */

// Start values
#define PL_START_0		0b00000011
#define PL_START_1		0b00111111
#define PL_START_POS_X	4
#define PL_START_POS_Y	7
#define EN_START		0b00000000
#define EN_START_POS_X	4
#define EN_START_POS_Y	21

// Colors player
#define COLOR_PL_EYE	BLACK
#define COLOR_PL_SKIN	YELLOW
#define COLOR_PL_HAT	BLACK
#define COLOR_PL_FEET	BLACK
#define COLOR_PL_PANTS	BLACK
#define COLOR_PL_SHIRT	BLACK
#define COLOR_PL_ROBE	BLACK

// Colors enemy 1
#define COLOR_EN1_EYE	BLACK
#define COLOR_EN1_SKIN	YELLOW
#define COLOR_EN1_HAT	WHITE
#define COLOR_EN1_FEET	WHITE
#define COLOR_EN1_PANTS	BLACK
#define COLOR_EN1_SHIRT	BLUE

// Colors enemy 2
#define COLOR_EN2_EYE	BLACK
#define COLOR_EN2_SKIN	YELLOW
#define COLOR_EN2_HAT	BLACK
#define COLOR_EN2_FEET	RED
#define COLOR_EN2_PANTS	WHITE
#define COLOR_EN2_SHIRT	BLACK

// Colors background
#define COLOR_SKY		CYAN
#define COLOR_SUN		WHITE
#define COLOR_GRASS		GREEN
#define COLOR_DIRT		YELLOW
#define COLOR_CLOUD		WHITE

// Colors others
#define COLOR_GUN		BLACK
#define COLOR_LIFE_BAR	RED
#define COLOR_SCORE		YELLOW

// Game consts 1
#define SC_X 240 // Total width
#define SC_Y 525 // Total height
#define DISPLAY_W 40
#define DISPLAY_H 30
#define V_SYNC_PULSE 2
#define H_SYNC_PULSE 96
#define V_BACK_PORCH 35
#define V_FRONT_PORCH 515 // Y - 10
#define H_BACK_PORCH 144
#define H_FRONT_PORCH 224 // X - 16

// Game consts 1
#define PL_SPEED		3
#define PL_BOUNDS_X		2
#define PL_BOUNDS_Y		6
#define PL_DAMAGE		1
#define PL_HEAL			1
#define MAX_KILLS		255
#define GRAVITY			2
#define JUMP_SPEED		2
#define BL_SPEED		4
#define OPT_NUMBER		2
#define MAX_BULLETS		8
#define MAX_ENEMIES		4
#define EN_SPEED		1
#define EN_BOUNDS_X		2
#define EN_BOUNDS_Y		6
#define EN_DAMAGE		1
#define EN_HEAL			1
#define SPAWN_TICK		40
#define CL_SPEED		1
#define CL_DISTANCE		20

// Positions
#define SCORE_POS_X		10
#define SCORE_POS_Y		3
#define LIFE_POS_X		31
#define LIFE_POS_Y		2

// Player's properties(0)
#define PL_DIR			0b00000001 // << 0, size 1
#define PL_GRAV			0b00000010 // << 1, size 1
#define PL_FEET			0b00000100 // << 2, size 1
#define PL_JUMP			0b00001000 // << 3, size 1
#define PL_JUMP_IT		0b00110000 // << 4, size 2
#define PL_FIRE_IT		0b11000000 // << 6, size 2

// Player's properties(1)
#define PL_LIFE			0b00111111 // << 0, size 6
#define PL_ROBE			0b01000000 // << 6, size 1
#define PL_ROBE_POS		0b10000000 // << 7, size 1

// Enemies' properties
#define EN_DIR			0b00000001 // << 0, size 1
#define EN_FEET			0b00000010 // << 1, size 1
#define EN_LIFE			0b00001100 // << 2, size 2
#define EN_HAND			0b00010000 // << 4, size 1
#define EN_TIMER_IT		0b01100000	// << 5, size 2
#define EN_TYPE			0b10000000 // << 7, size 1
#define EN_BLOOD		0b00000011 // << 0, size 2

// Bullet's properties
#define BL_TIMER_IT		0b00000111 // << 0, size 4
#define BL_DIR			0b00001000 // << 3, size 1

// Clouds' properties
#define CL_POS_X		0b00111111 // << 0, size 6
#define CL_OFFS			0b11000000 // << 6, size 2



/*---- Procedures */

// Checking
#define CHECK_PL_X_BOUNDS		if (plPosX > DISPLAY_W - PL_BOUNDS_X - 1) plPosX = DISPLAY_W - PL_BOUNDS_X - 1; else if (plPosX < PL_BOUNDS_X) plPosX = PL_BOUNDS_X;
#define CHECK_PL_Y_BOUNDS		if (plPosY > DISPLAY_H - PL_BOUNDS_Y - 3) { RESET_PL_JUMP; plPosY = DISPLAY_H - PL_BOUNDS_Y - 3; } else if (plPosY < PL_BOUNDS_Y) plPosY = PL_BOUNDS_Y;
#define CHECK_EN_X_BOUNDS(i)	if (enPosX[i] > DISPLAY_W - EN_BOUNDS_X - 1) enPosX[i] = DISPLAY_W - EN_BOUNDS_X - 1; else if (enPosX[i] < EN_BOUNDS_X) enPosX[i] = EN_BOUNDS_X;
#define CHECK_EN_Y_BOUNDS(i)	if (enPosY[i] > DISPLAY_H - EN_BOUNDS_Y - 3) { enPosY[i] = DISPLAY_H - EN_BOUNDS_Y - 3; } else if (enPosY[i] < EN_BOUNDS_Y) enPosY[i] = EN_BOUNDS_Y;

// Getters
#define GET_PL_DIR				((plByte0 & PL_DIR) * 2 - 1)					// Returns player walk direction (1 or -1)
#define GET_PL_GRAV				((plByte0 & PL_GRAV) >> 1)						// Returns player gravity direction (1 down, 0 up)
#define GET_PL_FEET				((plByte0 & PL_FEET) >> 2)						// Returns player feet
#define GET_PL_JUMP				((plByte0 & PL_JUMP) >> 3)						// Returns player jump (if it is jumping)
#define GET_PL_JUMP_IT			((plByte0 & PL_JUMP_IT) >> 4)					// Returns player jump iterator
#define GET_PL_FIRE_IT			((plByte0 & PL_FIRE_IT) >> 6)					// Returns player fire iterator
#define GET_PL_LIFE				(plByte1 & PL_LIFE)								// Returns player's life
#define GET_PL_ROBE				((plByte1 & PL_ROBE) >> 6)						// Returns player's robe
#define GET_PL_ROBE_POS			((plByte1 & PL_ROBE_POS) >> 7)					// Returns player's robe position
#define GET_BL_DIR(i)			((((blByte >> (4 * i)) & BL_DIR) >> 3) * 2 - 1)	// Returns bullet(i) direction
#define GET_BL_TIMER_IT(i)		((blByte >> (4 * i)) & BL_TIMER_IT)				// Returns bullet(i) timer iterator
#define GET_EN_DIR(i)			((enByte[i] & EN_DIR) * 2 - 1)					// Returns enemy(i) walk direction (1 or -1)
#define GET_EN_FEET(i)			((enByte[i] & EN_FEET) >> 1)					// Returns enemy(i) feet
#define GET_EN_LIFE(i)			((enByte[i] & EN_LIFE) >> 2)					// Returns enemy(i) life
#define GET_EN_HAND(i)			((enByte[i] & EN_HAND) >> 4)					// Returns enemy(i) hand
#define GET_EN_TIMER_IT(i)		((enByte[i] & EN_TIMER_IT) >> 5)				// Returns enemy(i) timer iterator
#define GET_EN_TYPE(i)			(((enByte[i] & EN_TYPE) >> 7) + 1)				// Returns enemy(i) type
#define GET_EN_BLOOD(i)			((enBlood >> (2 * i)) & EN_BLOOD)				// Returns enemy(i) type
#define GET_CL_OFFS				((clByte & CL_OFFS) >> 6)						// Returns cloud offset
#define GET_CL_POS				(clByte & CL_POS_X)								// Returns cloud position in x
#define GET_CL_POS_X(i)			(GET_CL_POS + CL_DISTANCE * ((i + GET_CL_OFFS) % 4))	// Returns cloud(i) position in x

// Setters
#define SET_PL_DIR_LEFT			plByte0 &= ~PL_DIR;								// Sets player direction to left
#define SET_PL_DIR_RIGHT		plByte0 |= PL_DIR;								// Sets player direction to right
#define SET_PL_GRAV				plByte0 |= PL_GRAV;								// Sets player gravity direction (down)
#define REV_PL_GRAV				plByte0 &= ~PL_GRAV;							// Reverses player gravity direction (up)
#define CHANGE_PL_FEET			plByte0 ^= PL_FEET;								// Changes player feet
#define RESET_PL_FEET			plByte0 &= ~PL_FEET;							// Resets player feet
#define SET_PL_JUMP				plByte0 |= PL_JUMP;								// Sets player jump
#define RESET_PL_JUMP			plByte0 &= ~PL_JUMP;							// Resets player jump
#define CHANGE_PL_ROBE_POS		plByte1 ^= PL_ROBE_POS;							// Changes pl robe num
#define SET_PL_ROBE				plByte1 |= PL_ROBE;								// Sets player robe
#define RESET_PL_ROBE			plByte1 &= ~(PL_ROBE | PL_ROBE_POS);			// Resets player robe
#define SET_BL_DIR_LEFT(i)		blByte &= ~(BL_DIR << (4 * i));					// Sets bullet(i) direction to left
#define SET_BL_DIR_RIGHT(i)		blByte |= (BL_DIR << (4 * i));					// Sets bullet(i) direction to right
#define RESET_BL_TIMER_IT(i)	blByte &= ~((unsigned long) BL_TIMER_IT << (4 * i));	// Resets bullet(i) timer iterator
#define SET_EN_DIR_LEFT(i)		enByte[i] &= ~EN_DIR;							// Sets enemy(i) direction to left
#define SET_EN_DIR_RIGHT(i)		enByte[i] |= EN_DIR;							// Sets enemy(i) direction to right
#define CHANGE_EN_FEET(i)		enByte[i] ^= EN_FEET;							// Changes enemy(i) feet
#define RESET_EN_FEET(i)		enByte[i] &= ~EN_FEET;							// Resets enemy(i) feet
#define CHANGE_EN_HAND(i)		enByte[i] ^= EN_HAND;							// Changes enemy(i) hand
#define SET_EN_HAND(i)			enByte[i] |= EN_HAND;							// Sets enemy(i) hand
#define RESET_EN_HAND(i)		enByte[i] &= ~EN_HAND;							// Resets enemy(i) hand
#define RESET_EN_TIMER_IT(i)	enByte[i] &= ~EN_TIMER_IT;						// Resets enemy(i) timer iterator
#define RESET_EN_LIFE(i)		enByte[i] |= EN_LIFE;							// Resets enemy(i) life to its original value
#define SET_EN_TYPE_1(i)		enByte[i] &= ~EN_TYPE;							// Sets enemy(i) type to 1
#define SET_EN_TYPE_2(i)		enByte[i] |= EN_TYPE;							// Sets enemy(i) type to 2

// Iterators
#define INC_PL_POS_X			plPosX += PL_SPEED * GET_PL_DIR; CHECK_PL_X_BOUNDS;
#define INC_PL_POS_Y			plPosY += (GET_PL_GRAV) ? GRAVITY : -JUMP_SPEED; CHECK_PL_Y_BOUNDS;
#define INC_PL_JUMP_IT			plByte0 = ((plByte0 & ~PL_JUMP_IT) | (((GET_PL_JUMP_IT + 1) % 4) << 4));
#define INC_PL_FIRE_IT			plByte0 = ((plByte0 & ~PL_FIRE_IT) | (((GET_PL_FIRE_IT + 1) % 4) << 6));
#define INC_PL_LIFE				plByte1 = (GET_PL_LIFE + PL_HEAL >= PL_LIFE) ? (plByte1 | PL_LIFE) : ((plByte1 & ~PL_LIFE) | (GET_PL_LIFE + PL_HEAL));
#define DEC_PL_LIFE				plByte1 = (GET_PL_LIFE <= EN_DAMAGE) ? (plByte1 & ~PL_LIFE) : ((plByte1 & ~PL_LIFE) | (GET_PL_LIFE - EN_DAMAGE));
#define INC_BL_POS_X(i)			blPosX[i] += BL_SPEED * GET_BL_DIR(i);
#define INC_BL_TIMER_IT(i)		blByte = ((blByte & ~(((unsigned long) BL_TIMER_IT) << (4 * i))) | (((GET_BL_TIMER_IT(i) + 1) & BL_TIMER_IT) << (4 * i)));
#define INC_EN_POS_X(i)			enPosX[i] += EN_SPEED * GET_EN_DIR(i); CHECK_EN_X_BOUNDS(i);
#define INC_EN_POS_Y(i)			enPosY[i] += GRAVITY; CHECK_EN_Y_BOUNDS(i);
#define INC_EN_LIFE(i)			enByte[i] = (GET_EN_LIFE(i) + EN_HEAL >= EN_LIFE) ? (enByte[i] | EN_LIFE) : ((enByte[i] & ~EN_LIFE) | ((GET_EN_LIFE(i) + EN_HEAL) << 2));
#define DEC_EN_LIFE(i)			enByte[i] = (GET_EN_LIFE(i) <= PL_DAMAGE) ? (enByte[i] & ~EN_LIFE) : ((enByte[i] & ~EN_LIFE) | ((GET_EN_LIFE(i) - PL_DAMAGE) << 2));
#define INC_EN_TIMER_IT(i)		enByte[i] = ((enByte[i] & ~EN_TIMER_IT) | (((GET_EN_TIMER_IT(i) + 1) << 5) & EN_TIMER_IT));
#define INC_EN_BLOOD(i)			enBlood = ((enBlood & ~(EN_BLOOD << (2 * i))) | (((GET_EN_BLOOD(i) + 1) & EN_BLOOD) << (2 * i)));
#define INC_CL_POS				clByte = (GET_CL_POS + CL_SPEED >= CL_POS_X) ? (CL_POS_X) : ((clByte & ~CL_POS_X) | (GET_CL_POS + CL_SPEED));
#define DEC_CL_POS				clByte = (GET_CL_POS <= CL_DISTANCE) ? (clByte & ~CL_POS_X) : ((clByte & ~CL_POS_X) | (GET_CL_POS - CL_DISTANCE));
#define INC_CL_OFFS				clByte = ((clByte & ~CL_OFFS) | (((GET_CL_OFFS + 1) << 6) & CL_OFFS));

// Others
#define PL_WALK					CHANGE_PL_FEET; SET_PL_ROBE; CHANGE_PL_ROBE_POS; INC_PL_POS_X;
#define EN_WALK(i)				CHANGE_EN_FEET(i); RESET_EN_HAND(i); INC_EN_POS_X(i);
#define EN_SPAWN(i, x, y)		enByte[i] = EN_LIFE; enPosX[i] = x; enPosY[i] = y;
#define GEN_CL_POS_Y(i)			clPosY[i] = random(4, 14);
#define MAIN(game, scene)		mainUpd = game ## scene ## Upd; mainDraw = game ## scene ## Draw; flag1 = 0; flag2 = 0;	// Changes main scene to scene
#define BUFFER(i, j)			Buffer[j][i]
#define SET_BUFFER(i, j, c)		if (((i >= 0) && (i < DISPLAY_W)) && ((j >= 0) && (j < DISPLAY_H))) Buffer[j][i] = c;



/*---- Vars */

// Arduino
byte lastKeys;
byte Buffer[DISPLAY_H][DISPLAY_W];
byte Keys = 0;
byte Mode = 1;
byte KeysUp;
byte KeysDown;

// Global
int I, J; // TODO maiuscula
char flag1, flag2;
unsigned char spawnTimer;

// Player
unsigned char plByte0; // Player's properties 1
unsigned char plByte1; // Player's properties 2
unsigned char plKills; // Player's kills
char plPosX; // Player's position in x
char plPosY; // Player's position in y

// Bullets
char *blPosX; // Bullets' pos in x
char *blPosY; // Bullets' pos in y
unsigned long blByte; // Bullets' properties

// Enemies
char *enPosX; // Enemies' pos in x
char *enPosY; // Enemies' pos in y
unsigned char *enByte; // Enemies' properties
unsigned short enBlood; // Blood

// Clouds
unsigned char clByte;
unsigned char *clPosY;

// Main functions
void PacoEnd();
void PacoStartUpd();
void PacoStartDraw();
void PacoUpd();
void PacoDraw();
void MenuUpd();
void MenuDraw();
void LoseUpd();
void LoseDraw();
void WonUpd();
void WonDraw();
void(*mainUpd)();
void(*mainDraw)();



/*---- Functions */

// Draws chars
void drawA(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x - 1, y + 1) = BUFFER(x, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawB(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawC(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawD(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawE(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawF(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = color;
}
void drawG(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 1, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawH(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawI(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawJ(unsigned char x, unsigned char y, char color)
{
	BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x + 2, y - 1) = color;
	BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawK(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawL(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 2, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawM(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawN(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x - 1, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawO(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawP(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = color;
}
void drawQ(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawR(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawS(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawT(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawU(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void drawV(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawW(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 2, y - 1) = BUFFER(x + 2, y - 1) = color;
	BUFFER(x - 2, y) = BUFFER(x, y) = BUFFER(x + 2, y) = color;
	BUFFER(x - 2, y + 1) = BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = BUFFER(x + 2, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawX(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void drawY(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x, y + 2) = color;
}
void drawZ(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 2, y - 2) = BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = BUFFER(x + 2, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x - 1, y + 1) = color;
	BUFFER(x - 2, y + 2) = BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = BUFFER(x + 2, y + 2) = color;
}
void draw0(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw1(unsigned char x, unsigned char y, char color)
{
	BUFFER(x, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x, y - 1) = color;
	BUFFER(x, y) = color;
	BUFFER(x, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw2(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw3(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw4(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x + 1, y + 2) = color;
}
void draw5(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw6(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw7(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x + 1, y - 1) = color;
	BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x + 1, y + 2) = color;
}
void draw8(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x - 1, y + 1) = BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}
void draw9(unsigned char x, unsigned char y, char color)
{
	BUFFER(x - 1, y - 2) = BUFFER(x, y - 2) = BUFFER(x + 1, y - 2) = color;
	BUFFER(x - 1, y - 1) = BUFFER(x + 1, y - 1) = color;
	BUFFER(x - 1, y) = BUFFER(x, y) = BUFFER(x + 1, y) = color;
	BUFFER(x + 1, y + 1) = color;
	BUFFER(x - 1, y + 2) = BUFFER(x, y + 2) = BUFFER(x + 1, y + 2) = color;
}

// Draws num
void drawNum(unsigned char x, unsigned char y, unsigned int num, unsigned char color)
{
	// fazer um vetor de ponteiros pra funcao e varias coisas TODO
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

// Draws background TODO
void drawBack(byte color)
{
	memset(Buffer, color, sizeof(Buffer));
}

// Updates keys
void updateKeys()
{
	Keys = PINC;
	KeysDown = (~lastKeys & Keys);
	KeysUp = (lastKeys & ~Keys);
	lastKeys = Keys;
}

// TODO short random(short min, short max) { return rand() % (max - min) + min; }

// Quit TODO
void quit()
{
	
}



/*---- Paco Functions */

// Sets vars to initial values
void resetVars()
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
		MAIN(, Lose);
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
void drawBlood(unsigned char i)
{
	// Gets pos
	unsigned char x = enPosX[i];
	unsigned char y = enPosY[i];

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
void drawPlayer(unsigned char x, unsigned char y)
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
void drawEnemy1(unsigned char i)
{
	// Gets pos
	unsigned char x = enPosX[i];
	unsigned char y = enPosY[i];

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
void drawEnemy2(unsigned char i)
{
	// Gets pos
	unsigned char x = enPosX[i];
	unsigned char y = enPosY[i];

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



/*---- Paco scene functions */

void PacoStart()
{
	blPosX = (char*) malloc(sizeof(char) * MAX_BULLETS);
	blPosY = (char*) malloc(sizeof(char) * MAX_BULLETS);
	enPosX = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enPosY = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enByte = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	clPosY = (unsigned char*) malloc(sizeof(unsigned char) * 4);

	resetVars();
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
	if (GETD_KEY_SELECT)
	{
		MAIN(Paco, );
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

void PacoUpd()
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
		MAIN(, Won);
	}
	else if (GETD_KEY_BACK)
	{
		MAIN(, Menu);
	}
}

void PacoDraw()
{
	drawBackground();
	drawEnemies();
	drawPlayer(plPosX, plPosY);
	drawBullets();
	drawClouds();
	drawLife();
	drawScore();
}

void MenuUpd()
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
				MAIN(Paco, );
				break;
			case 1: // Quit
				quit();
				break;
			default:
				break;
		}
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void MenuDraw()
{
	drawBack(BLACK);

	// Back
	if (flag1 == 0)
	{
		J = (flag2 % 4) / 2;
		I = J ? RED : PINK;
		J = J ? PINK : RED;
	}
	else
	{
		I = J = WHITE;
	}
	drawB(11, 9, I);
	drawA(17, 9, J);
	drawC(23, 9, I);
	drawK(29, 9, J);

	// Quit
	if (flag1 == 1)
	{
		J = (flag2 % 4) / 2;
		I = J ? RED : PINK;
		J = J ? PINK : RED;
	}
	else
	{
		I = J = WHITE;
	}
	drawQ(11, 19, I);
	drawU(17, 19, J);
	drawI(23, 19, I);
	drawT(29, 19, J);
}

void LoseUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		resetVars();
	}

	// Changes selected colors
	flag2 = (flag2 + 1) % 16;
}

void LoseDraw()
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

void WonUpd()
{
	if (GETD_KEY_SELECT)
	{
		// Resets vars
		resetVars();
	}

	flag1 = (flag1 + 1) % 8;
}

void WonDraw()
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

void start()
{
	PacoStart();
}

void update()
{
	(*mainUpd)();
}

void draw()
{
	(*mainDraw)();
}

void end()
{
	PacoEnd();
}



/*---- Arduino */

void setup()
{
	cli(); // clear interrupts

	// Setting pinos
	PORTD  = 0;
	DDRD   |= bit(DDD3)   | bit(DDD4);
	DDRB   = B0111;

	DDRC |= 0b111111;
	
	// Timer 2 setup (fast PWM, TOP = OCR1A, update at BOTTOM, TOV set on TOP)
	TCCR2A	= bit(COM2B1) | bit(WGM20) | bit(WGM21); // clear b on compare match
	TCCR2B	= bit(WGM22) | bit(CS21); // clk
	OCR2A	= 63; // hsync time
	OCR2B	= 7; // hsync duration
	TIMSK2	= bit(OCIE2B) | bit(TOIE2); // compare interrupt, overflow interrupt
	TIFR2	= bit(OCF2B) | bit(TOV2); // compare interrupt, overflow interrupt

	SMCR = bit(SE);

	drawBack(WHITE);
	
	sei(); // set interrupts

	// TODO
	start();
}

void loop()
{
	updateKeys();
      update();
      draw();
  
  delay(50);
}



/*---- Code */

volatile int Line = SC_Y;
char showroom = 0;

ISR(TIMER2_OVF_vect)
{
	sei();
	__asm__("sleep \n");
}
ISR(TIMER2_COMPB_vect)
{
	if (Line >= SC_Y)
	{
		Line = 0;
		PORTD = 0b10000;
	}
	else if (Line == V_SYNC_PULSE)
	{
		PORTD &= 0b11100111;
		PORTB = 0;
	}
	else if ((Line >= V_BACK_PORCH) && (Line < V_FRONT_PORCH) && showroom)
	{
		register byte * buf = &(Buffer[(Line - V_BACK_PORCH) >> 4][0]);
		byte pixel = DISPLAY_W;// i = 5;
		while (pixel--)//Line < 250 || Line > 250? 1 : 0
		{
			PORTB = *(buf++);
		}

		//nop;
		//nop;
		//nop;
		PORTB = 0;
	}
	else
	{
		PORTD &= 0b11100111;
		PORTB = 0;
	}

	showroom = !showroom;
	Line++;
}
