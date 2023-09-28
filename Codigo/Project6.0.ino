/*---- Constants */

// Arduino
#define nop				__asm__("nop \n");
#define SC_X			240 // Total width
#define SC_Y			523 // Total height
#define DISPLAY_W		40
#define DISPLAY_H		30
#define V_SYNC_PULSE	4
#define H_SYNC_PULSE	96
#define V_BACK_PORCH	35
#define V_FRONT_PORCH	515 // Y - 10
#define H_BACK_PORCH	144
#define H_FRONT_PORCH	224 // X - 16

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
#define RESET_BITS(var, bits)			var = VAR_WITH_MIN_BITS(var, bits);
#define SET_BITS(var, bits)			var = VAR_WITH_MAX_BITS(var, bits);
#define CHANGES(var, bits)				var ^= (bits);



/*---- Menu constants */

#define COLOR_MENU		RED



/*---- Paco constants */

// Start values
#define PL_START_0		0b00000011
#define PL_START_1		0b00111111
#define PL_START_POS_X	4
#define PL_START_POS_Y	7
#define EN_START		0b00000000
#define EN_START_POS_X	4
#define EN_START_POS_Y	21

// Colors
#define COLOR_PL_EYE	BLACK
#define COLOR_PL_SKIN	YELLOW
#define COLOR_PL_HAT	BLACK
#define COLOR_PL_FEET	BLACK
#define COLOR_PL_PANTS	BLACK
#define COLOR_PL_SHIRT	BLACK
#define COLOR_PL_ROBE	BLACK

#define COLOR_EN1_EYE	BLACK
#define COLOR_EN1_SKIN	YELLOW
#define COLOR_EN1_HAT	WHITE
#define COLOR_EN1_FEET	WHITE
#define COLOR_EN1_PANTS	BLACK
#define COLOR_EN1_SHIRT	BLUE

#define COLOR_EN2_EYE	BLACK
#define COLOR_EN2_SKIN	YELLOW
#define COLOR_EN2_HAT	BLACK
#define COLOR_EN2_FEET	RED
#define COLOR_EN2_PANTS	WHITE
#define COLOR_EN2_SHIRT	BLACK

#define COLOR_GUN		BLACK
#define COLOR_LIFE_BAR	RED
#define COLOR_SCORE		YELLOW

#define COLOR_SKY		CYAN
#define COLOR_SUN		WHITE
#define COLOR_GRASS		GREEN
#define COLOR_DIRT		YELLOW
#define COLOR_CLOUD		WHITE

// Game consts
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
#define BL(bits, i)		(bits << (4 * i))

// Clouds' properties
#define CL_POS_X		0b00111111 // << 0, size 6
#define CL_OFFS			0b11000000 // << 6, size 2



/*---- Snake constants */

// Game consts
#define SNAKE_MAX_SIZE		30
#define SNAKE_BYTE_START	0
//#define OPT_NUMBER		2

// Snake's bytes
#define SNAKE_DIR			0b0000000000000011 // << 0, size 1
#define SNAKE_HEAD			0b0000001111110000 // << 4, size 6
#define SNAKE_TAIL			0b1111110000000000 // << 10, size 6

// Colors
#define COLOR_SNAKE			WHITE
#define COLOR_BACK			BLACK
#define COLOR_FRUIT			RED
#define COLOR_SNAKE_WALL	CYAN

// Direction
#define SNAKE_UP			0
#define SNAKE_LEFT			1
#define SNAKE_DOWN			2
#define SNAKE_RIGHT			3



/*---- Paco procedures */

// Checking
#define CHECK_PL_X_BOUNDS		if (plPosX > DISPLAY_W - PL_BOUNDS_X - 1) plPosX = DISPLAY_W - PL_BOUNDS_X - 1; else if (plPosX < PL_BOUNDS_X) plPosX = PL_BOUNDS_X;
#define CHECK_PL_Y_BOUNDS		if (plPosY > DISPLAY_H - PL_BOUNDS_Y - 3) { RESET_PL_JUMP; plPosY = DISPLAY_H - PL_BOUNDS_Y - 3; } else if (plPosY < PL_BOUNDS_Y) plPosY = PL_BOUNDS_Y;
#define CHECK_EN_X_BOUNDS(i)	if (enPosX[i] > DISPLAY_W - EN_BOUNDS_X - 1) enPosX[i] = DISPLAY_W - EN_BOUNDS_X - 1; else if (enPosX[i] < EN_BOUNDS_X) enPosX[i] = EN_BOUNDS_X;
#define CHECK_EN_Y_BOUNDS(i)	if (enPosY[i] > DISPLAY_H - EN_BOUNDS_Y - 3) { enPosY[i] = DISPLAY_H - EN_BOUNDS_Y - 3; } else if (enPosY[i] < EN_BOUNDS_Y) enPosY[i] = EN_BOUNDS_Y;

// Getters
#define BL_DIR_BIT(i)			(BL_DIR << (4 * i))
#define BL_TIMER_IT_BIT(i)		(BL_TIMER_IT << (4 * i))
#define EN_BLOOD_BIT(i)			(EN_BLOOD << (2 * i))
#define GET_PL_DIR				(GET_BITS(plByte0, PL_DIR, 0) * 2 - 1)					// Returns player walk direction (1 or -1)
#define GET_PL_GRAV				GET_BITS(plByte0, PL_GRAV, 1)							// Returns player gravity direction (1 down, 0 up)
#define GET_PL_FEET				GET_BITS(plByte0, PL_FEET, 2)							// Returns player feet
#define GET_PL_JUMP				GET_BITS(plByte0, PL_JUMP, 3)							// Returns player jump (if it is jumping)
#define GET_PL_JUMP_IT			GET_BITS(plByte0, PL_JUMP_IT, 4)						// Returns player jump iterator
#define GET_PL_FIRE_IT			GET_BITS(plByte0, PL_FIRE_IT, 6)						// Returns player fire iterator
#define GET_PL_LIFE				GET_BITS(plByte1, PL_LIFE, 0)							// Returns player's life
#define GET_PL_ROBE				GET_BITS(plByte1, PL_ROBE, 6)							// Returns player's robe
#define GET_PL_ROBE_POS			GET_BITS(plByte1, PL_ROBE_POS, 7)						// Returns player's robe position
#define GET_BL_DIR(i)			(GET_BITS(blByte, BL_DIR_BIT(i), 3 + (4 * i)) * 2 - 1)	// Returns bullet(i) direction
#define GET_BL_TIMER_IT(i)		GET_BITS(blByte, BL_TIMER_IT_BIT(i), (4 * i))			// Returns bullet(i) timer iterator
#define GET_EN_DIR(i)			(GET_BITS(enByte[i], EN_DIR, 0) * 2 - 1)				// Returns enemy(i) walk direction (1 or -1)
#define GET_EN_FEET(i)			GET_BITS(enByte[i], EN_FEET, 1)							// Returns enemy(i) feet
#define GET_EN_LIFE(i)			GET_BITS(enByte[i], EN_LIFE, 2)							// Returns enemy(i) life
#define GET_EN_HAND(i)			GET_BITS(enByte[i], EN_HAND, 4)							// Returns enemy(i) hand
#define GET_EN_TIMER_IT(i)		GET_BITS(enByte[i], EN_TIMER_IT, 5)						// Returns enemy(i) timer iterator
#define GET_EN_TYPE(i)			(GET_BITS(enByte[i], EN_TYPE, 7) + 1)					// Returns enemy(i) type
#define GET_EN_BLOOD(i)			GET_BITS(enBlood, EN_BLOOD_BIT(i), 2 * i)				// Returns enemy(i) type
#define GET_CL_OFFS				GET_BITS(clByte, CL_OFFS, 6)							// Returns cloud offset
#define GET_CL_POS				GET_BITS(clByte, CL_POS_X, 0)							// Returns cloud position in x
#define GET_CL_POS_X(i)			(GET_CL_POS + CL_DISTANCE * ((i + GET_CL_OFFS) % 4))	// Returns cloud(i) position in x

// Setters
#define SET_PL_DIR_LEFT			RESET_BITS(plByte0, PL_DIR)								// Sets player direction to left
#define SET_PL_DIR_RIGHT		SET_BITS(plByte0, PL_DIR)								// Sets player direction to right
#define SET_PL_GRAV				SET_BITS(plByte0, PL_GRAV)								// Sets player gravity direction (down)
#define REV_PL_GRAV				RESET_BITS(plByte0, PL_GRAV)							// Reverses player gravity direction (up)
#define CHANGE_PL_FEET			CHANGES(plByte0, PL_FEET)								// Changes player feet
#define RESET_PL_FEET			RESET_BITS(plByte0, PL_FEET)							// Resets player feet
#define SET_PL_JUMP				SET_BITS(plByte0, PL_JUMP)								// Sets player jump
#define RESET_PL_JUMP			RESET_BITS(plByte0, PL_JUMP)							// Resets player jump
#define CHANGE_PL_ROBE_POS		CHANGES(plByte1, PL_ROBE_POS)							// Changes pl robe num
#define SET_PL_ROBE				SET_BITS(plByte1, PL_ROBE)								// Sets player robe
#define RESET_PL_ROBE			RESET_BITS(plByte1, PL_ROBE | PL_ROBE_POS)				// Resets player robe
#define SET_BL_DIR_LEFT(i)		RESET_BITS(blByte, BL_DIR_BIT(i))						// Sets bullet(i) direction to left
#define SET_BL_DIR_RIGHT(i)		SET_BITS(blByte, BL_DIR_BIT(i))							// Sets bullet(i) direction to right
#define RESET_BL_TIMER_IT(i)	RESET_BITS(blByte, BL_TIMER_IT_BIT(i))					// Resets bullet(i) timer iterator
#define SET_EN_DIR_LEFT(i)		RESET_BITS(enByte[i], EN_DIR)							// Sets enemy(i) direction to left
#define SET_EN_DIR_RIGHT(i)		SET_BITS(enByte[i], EN_DIR)								// Sets enemy(i) direction to right
#define CHANGE_EN_FEET(i)		CHANGES(enByte[i], EN_FEET)								// Changes enemy(i) feet
#define RESET_EN_FEET(i)		RESET_BITS(enByte[i], EN_FEET)							// Resets enemy(i) feet
#define CHANGE_EN_HAND(i)		CHANGES(enByte[i], EN_HAND)								// Changes enemy(i) hand
#define SET_EN_HAND(i)			SET_BITS(enByte[i], EN_HAND)							// Sets enemy(i) hand
#define RESET_EN_HAND(i)		RESET_BITS(enByte[i], EN_HAND)							// Resets enemy(i) hand
#define RESET_EN_TIMER_IT(i)	RESET_BITS(enByte[i], EN_TIMER_IT)						// Resets enemy(i) timer iterator
#define RESET_EN_LIFE(i)		SET_BITS(enByte[i], EN_LIFE)							// Resets enemy(i) life to its original value
#define SET_EN_TYPE_1(i)		RESET_BITS(enByte[i], EN_TYPE)							// Sets enemy(i) type to 1
#define SET_EN_TYPE_2(i)		SET_BITS(enByte[i], EN_TYPE)							// Sets enemy(i) type to 2

// Iterators
#define INC_PL_POS_X			plPosX += PL_SPEED * GET_PL_DIR; CHECK_PL_X_BOUNDS;
#define INC_PL_POS_Y			plPosY += (GET_PL_GRAV) ? GRAVITY : -JUMP_SPEED; CHECK_PL_Y_BOUNDS;
#define INC_PL_JUMP_IT			plByte0 = ((plByte0 & ~PL_JUMP_IT) | (((GET_PL_JUMP_IT + 1) % 4) << 4));
#define INC_PL_FIRE_IT			plByte0 = ((plByte0 & ~PL_FIRE_IT) | (((GET_PL_FIRE_IT + 1) % 4) << 6));
#define INC_PL_LIFE				plByte1 = (GET_PL_LIFE + PL_HEAL >= PL_LIFE) ? (plByte1 | PL_LIFE) : ((plByte1 & ~PL_LIFE) | (GET_PL_LIFE + PL_HEAL));
#define DEC_PL_LIFE				plByte1 = (GET_PL_LIFE <= EN_DAMAGE) ? (plByte1 & ~PL_LIFE) : ((plByte1 & ~PL_LIFE) | (GET_PL_LIFE - EN_DAMAGE));
#define INC_BL_POS_X(i)			blPosX[i] += BL_SPEED * GET_BL_DIR(i);
#define INC_BL_TIMER_IT(i)		blByte = ((blByte & ~BL_TIMER_IT_BIT(i)) | (((GET_BL_TIMER_IT(i) + 1) << (4 * i)) & BL_TIMER_IT_BIT(i)));
#define INC_EN_POS_X(i)			enPosX[i] += EN_SPEED * GET_EN_DIR(i); CHECK_EN_X_BOUNDS(i);
#define INC_EN_POS_Y(i)			enPosY[i] += GRAVITY; CHECK_EN_Y_BOUNDS(i);
#define INC_EN_LIFE(i)			enByte[i] = (GET_EN_LIFE(i) + EN_HEAL >= EN_LIFE) ? (enByte[i] | EN_LIFE) : ((enByte[i] & ~EN_LIFE) | ((GET_EN_LIFE(i) + EN_HEAL) << 2));
#define DEC_EN_LIFE(i)			enByte[i] = (GET_EN_LIFE(i) <= PL_DAMAGE) ? (enByte[i] & ~EN_LIFE) : ((enByte[i] & ~EN_LIFE) | ((GET_EN_LIFE(i) - PL_DAMAGE) << 2));
#define INC_EN_TIMER_IT(i)		enByte[i] = ((enByte[i] & ~EN_TIMER_IT) | (((GET_EN_TIMER_IT(i) + 1) << 5) & EN_TIMER_IT));
#define INC_EN_BLOOD(i)			enBlood = ((enBlood & ~EN_BLOOD_BIT(i)) | (((GET_EN_BLOOD(i) + 1) << (2 * i)) & EN_BLOOD_BIT(i)));
#define INC_CL_POS				clByte = (GET_CL_POS + CL_SPEED >= CL_POS_X) ? (CL_POS_X) : ((clByte & ~CL_POS_X) | (GET_CL_POS + CL_SPEED));
#define DEC_CL_POS				clByte = (GET_CL_POS <= CL_DISTANCE) ? (clByte & ~CL_POS_X) : ((clByte & ~CL_POS_X) | (GET_CL_POS - CL_DISTANCE));
#define INC_CL_OFFS				clByte = ((clByte & ~CL_OFFS) | (((GET_CL_OFFS + 1) << 6) & CL_OFFS));

// Others
#define PL_WALK					CHANGE_PL_FEET; SET_PL_ROBE; CHANGE_PL_ROBE_POS; INC_PL_POS_X;
#define EN_WALK(i)				CHANGE_EN_FEET(i); RESET_EN_HAND(i); INC_EN_POS_X(i);
#define EN_SPAWN(i, x, y)		enByte[i] = EN_LIFE; enPosX[i] = x; enPosY[i] = y;
#define GEN_CL_POS_Y(i)			clPosY[i] = random(4, 14);



/*---- Snake procedures */

// Getters
#define GET_SNAKE_DIR			((signed) GET_BITS(enBlood, SNAKE_DIR, 0))
#define GET_SNAKE_DIR_X			((GET_SNAKE_DIR - 2) % 2)
#define GET_SNAKE_DIR_Y			((GET_SNAKE_DIR - 1) % 2)
#define GET_SNAKE_HEAD			GET_BITS(enBlood, SNAKE_HEAD, 4)
#define GET_SNAKE_TAIL			GET_BITS(enBlood, SNAKE_TAIL, 10)
#define GET_SNAKE_PREV_POS(i)	((i + SNAKE_MAX_SIZE - 1) % SNAKE_MAX_SIZE)
#define GET_SNAKE_NEXT_POS(i)	((i + 1) % SNAKE_MAX_SIZE)
#define GET_SNAKE_SIZE			(((GET_SNAKE_HEAD - GET_SNAKE_TAIL + SNAKE_MAX_SIZE) % SNAKE_MAX_SIZE) + 1)

// Setters
#define SET_SNAKE_DIR_UP		enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_DIR) + SNAKE_UP;
#define SET_SNAKE_DIR_LEFT		enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_DIR) + SNAKE_LEFT;
#define SET_SNAKE_DIR_DOWN		enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_DIR) + SNAKE_DOWN;
#define SET_SNAKE_DIR_RIGHT		enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_DIR) + SNAKE_RIGHT;
#define SET_SNAKE_POS(x, y, i)	snakePosX[i] = x; snakePosY[i] = y;

// Iterators
#define INC_SNAKE_HEAD			enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_HEAD) | (GET_SNAKE_NEXT_POS(GET_SNAKE_HEAD) << 4);
#define INC_SNAKE_TAIL			enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_TAIL) | (GET_SNAKE_NEXT_POS(GET_SNAKE_TAIL) << 10);
#define DEC_SNAKE_TAIL			enBlood = VAR_WITH_MIN_BITS(enBlood, SNAKE_TAIL) | (GET_SNAKE_PREV_POS(GET_SNAKE_TAIL) << 10);
#define SET_SNAKE_NEW_HEAD		SET_SNAKE_POS(snakePosX[GET_SNAKE_PREV_POS(GET_SNAKE_HEAD)] + GET_SNAKE_DIR_X, snakePosY[GET_SNAKE_PREV_POS(GET_SNAKE_HEAD)] + GET_SNAKE_DIR_Y, GET_SNAKE_HEAD);



/*---- Global vars */

byte lastKeys;
byte Buffer[DISPLAY_H][DISPLAY_W];
byte Keys = 0;
byte KeysUp;
byte KeysDown;
void (*mainUpd)();
void (*mainDraw)();



/*---- Global functions */

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

void drawBack(byte color)
{
	memset(Buffer, color, sizeof(Buffer));
}

void updateKeys()
{
	Keys = PINC;
	KeysDown = (~lastKeys & Keys);
	KeysUp = (lastKeys & ~Keys);
	lastKeys = Keys;
}



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
	plPosX = random(1, DISPLAY_W - 1);
	plPosY = random(1, DISPLAY_H - 1);
}

void SnakeResetVars()
{
	flag1 = flag2 = 0;
	enBlood = SNAKE_BYTE_START;
	snakePosX[0] = 20;
	snakePosY[0] = 1;
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

	if ((snakePosX[GET_SNAKE_HEAD] <= 0) ||
		(snakePosX[GET_SNAKE_HEAD] >= DISPLAY_W - 1) ||
		(snakePosY[GET_SNAKE_HEAD] <= 0) ||
		(snakePosY[GET_SNAKE_HEAD] >= DISPLAY_H - 1))
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

void drawWall()
{
	for (I = 0; I < DISPLAY_W; I++)
	{
		BUFFER(I, 0) = COLOR_SNAKE_WALL;
		BUFFER(I, DISPLAY_H - 1) = COLOR_SNAKE_WALL;
	}
	for (I = 0; I < DISPLAY_H; I++)
	{
		BUFFER(0, I) = COLOR_SNAKE_WALL;
		BUFFER(DISPLAY_W - 1, I) = COLOR_SNAKE_WALL;
	}
}



/*---- Paco scene scenes */

// Start
void PacoStart()
{
	blPosX = (char*) malloc(sizeof(char) * MAX_BULLETS);
	blPosY = (char*) malloc(sizeof(char) * MAX_BULLETS);
	enPosX = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enPosY = (char*) malloc(sizeof(char) * MAX_ENEMIES);
	enByte = (byte*) malloc(sizeof(byte) * MAX_ENEMIES);
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
	snakePosX = (char*) malloc(sizeof(char) * SNAKE_MAX_SIZE);
	snakePosY = (char*) malloc(sizeof(char) * SNAKE_MAX_SIZE);

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
	drawWall();
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



/*---- Main menu functions */

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

void start()
{
	MAIN(Main, Menu);
}



/*---- Code */

void setup()
{
	cli(); // clear interrupts

	// Setting pinos
	PORTD = 0;
	DDRD |= bit(DDD3) | bit(DDD4);
	DDRB = B0111;

	DDRC |= 0b111111;

	// Timer 2 setup (fast PWM, TOP = OCR1A, update at BOTTOM, TOV set on TOP)
	TCCR2A = bit(COM2B1) | bit(WGM20) | bit(WGM21); // clear b on compare match
	TCCR2B = bit(WGM22) | bit(CS21); // clk
	OCR2A = 63; // hsync time
	OCR2B = 6; // hsync duration
	TIMSK2 = bit(OCIE2B) | bit(TOIE2); // compare interrupt, overflow interrupt
	TIFR2 = bit(OCF2B) | bit(TOV2); // compare interrupt, overflow interrupt

	SMCR = bit(SE);

	//drawBack(WHITE);

	sei(); // Sets interrupts
	
	start();
}

void loop()
{
	updateKeys();
	(*mainUpd)();
	(*mainDraw)();

	delay(50);
}

//

#define V_SYNC	0b00010000
#define H_SYNC	0b00001000

// PORTB:	Colors
// PORTC:	Keys
// PORTD:	Vsync, Hsync

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
		SET_BITS(PORTD, V_SYNC);
	}
	else if (Line == V_SYNC_PULSE)
	{
		RESET_BITS(PORTD, V_SYNC | H_SYNC);
		RESET_BITS(PORTB, RED | GREEN | BLUE);
	}
	else if ((Line >= V_BACK_PORCH) && (Line < V_FRONT_PORCH) && !showroom)
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
		RESET_BITS(PORTB, RED | GREEN | BLUE);
	}
	else
	{
		RESET_BITS(PORTD, V_SYNC | H_SYNC);
		RESET_BITS(PORTB, RED | GREEN | BLUE);
	}

	showroom = !showroom;
	Line++;
}
