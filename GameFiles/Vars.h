#ifndef VARS_H
#define VARS_H



/*---- Paco constants */

// Start values
#define PL_START_0		0b0000'0011
#define PL_START_1		0b0011'1111
#define PL_START_POS_X	4
#define PL_START_POS_Y	7
#define EN_START		0b0000'0000
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
#define PL_DIR			0b0000'0001 // << 0, size 1
#define PL_GRAV			0b0000'0010 // << 1, size 1
#define PL_FEET			0b0000'0100 // << 2, size 1
#define PL_JUMP			0b0000'1000 // << 3, size 1
#define PL_JUMP_IT		0b0011'0000 // << 4, size 2
#define PL_FIRE_IT		0b1100'0000 // << 6, size 2

// Player's properties(1)
#define PL_LIFE			0b0011'1111 // << 0, size 6
#define PL_ROBE			0b0100'0000 // << 6, size 1
#define PL_ROBE_POS		0b1000'0000 // << 7, size 1

// Enemies' properties
#define EN_DIR			0b0000'0001 // << 0, size 1
#define EN_FEET			0b0000'0010 // << 1, size 1
#define EN_LIFE			0b0000'1100 // << 2, size 2
#define EN_HAND			0b0001'0000 // << 4, size 1
#define EN_TIMER_IT		0b0110'0000	// << 5, size 2
#define EN_TYPE			0b1000'0000 // << 7, size 1
#define EN_BLOOD		0b0000'0011 // << 0, size 2

// Bullet's properties
#define BL_TIMER_IT		0b0000'0111 // << 0, size 4
#define BL_DIR			0b0000'1000 // << 3, size 1
#define BL(bits, i)		(bits << (4 * i))

// Clouds' properties
#define CL_POS_X		0b0011'1111 // << 0, size 6
#define CL_OFFS			0b1100'0000 // << 6, size 2



/*---- Snake constants */

// Game consts
#define SNAKE_MAX_SIZE		30
#define SNAKE_BYTE_START	0
//#define OPT_NUMBER		2

// Snake's bytes
#define SNAKE_DIR			0b0000'0000'0000'0011 // << 0, size 1
#define SNAKE_HEAD			0b0000'0011'1111'0000 // << 4, size 6
#define SNAKE_TAIL			0b1111'1100'0000'0000 // << 10, size 6

// Colors
#define COLOR_SNAKE			WHITE
#define COLOR_BACK			BLACK
#define COLOR_FRUIT			RED

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
#define SET_PL_DIR_LEFT			SET_TO_MIN(plByte0, PL_DIR)								// Sets player direction to left
#define SET_PL_DIR_RIGHT		SET_TO_MAX(plByte0, PL_DIR)								// Sets player direction to right
#define SET_PL_GRAV				SET_TO_MAX(plByte0, PL_GRAV)							// Sets player gravity direction (down)
#define REV_PL_GRAV				SET_TO_MIN(plByte0, PL_GRAV)							// Reverses player gravity direction (up)
#define CHANGE_PL_FEET			CHANGES(plByte0, PL_FEET)								// Changes player feet
#define RESET_PL_FEET			SET_TO_MIN(plByte0, PL_FEET)							// Resets player feet
#define SET_PL_JUMP				SET_TO_MAX(plByte0, PL_JUMP)							// Sets player jump
#define RESET_PL_JUMP			SET_TO_MIN(plByte0, PL_JUMP)							// Resets player jump
#define CHANGE_PL_ROBE_POS		CHANGES(plByte1, PL_ROBE_POS)							// Changes pl robe num
#define SET_PL_ROBE				SET_TO_MAX(plByte1, PL_ROBE)							// Sets player robe
#define RESET_PL_ROBE			SET_TO_MIN(plByte1, PL_ROBE | PL_ROBE_POS)				// Resets player robe
#define SET_BL_DIR_LEFT(i)		SET_TO_MIN(blByte, BL_DIR_BIT(i))						// Sets bullet(i) direction to left
#define SET_BL_DIR_RIGHT(i)		SET_TO_MAX(blByte, BL_DIR_BIT(i))						// Sets bullet(i) direction to right
#define RESET_BL_TIMER_IT(i)	SET_TO_MIN(blByte, BL_TIMER_IT_BIT(i))					// Resets bullet(i) timer iterator
#define SET_EN_DIR_LEFT(i)		SET_TO_MIN(enByte[i], EN_DIR)							// Sets enemy(i) direction to left
#define SET_EN_DIR_RIGHT(i)		SET_TO_MAX(enByte[i], EN_DIR)							// Sets enemy(i) direction to right
#define CHANGE_EN_FEET(i)		CHANGES(enByte[i], EN_FEET)								// Changes enemy(i) feet
#define RESET_EN_FEET(i)		SET_TO_MIN(enByte[i], EN_FEET)							// Resets enemy(i) feet
#define CHANGE_EN_HAND(i)		CHANGES(enByte[i], EN_HAND)								// Changes enemy(i) hand
#define SET_EN_HAND(i)			SET_TO_MAX(enByte[i], EN_HAND)							// Sets enemy(i) hand
#define RESET_EN_HAND(i)		SET_TO_MIN(enByte[i], EN_HAND)							// Resets enemy(i) hand
#define RESET_EN_TIMER_IT(i)	SET_TO_MIN(enByte[i], EN_TIMER_IT)						// Resets enemy(i) timer iterator
#define RESET_EN_LIFE(i)		SET_TO_MAX(enByte[i], EN_LIFE)							// Resets enemy(i) life to its original value
#define SET_EN_TYPE_1(i)		SET_TO_MIN(enByte[i], EN_TYPE)							// Sets enemy(i) type to 1
#define SET_EN_TYPE_2(i)		SET_TO_MAX(enByte[i], EN_TYPE)							// Sets enemy(i) type to 2

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
#define GET_SNAKE_DIR			GET_BITS(enBlood, SNAKE_DIR, 0)
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

#endif