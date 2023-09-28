// -----Variables:

#define SC_X 240 // Total width
#define SC_Y 525 // Total height

#define WIDTH 40
#define HEIGHT 30

#define nop __asm__("nop \n")

#define V_SYNC_PULSE 2
#define H_SYNC_PULSE 96

#define V_BACK_PORCH 35
#define V_FRONT_PORCH 515 // Y - 10
#define H_BACK_PORCH 144
#define H_FRONT_PORCH 224 // X - 16

byte Buffer[HEIGHT][WIDTH];
byte Keys = 0;
byte Mode = 1;

// -----Types:

enum Color
{
	N = 0b000,
	R = 0b100,
	G = 0b010,
	B = 0b001,
	Y = 0b110,
	P = 0b101,
	C = 0b011,
	W = 0b111
};

// -----Functions:

// Sets a pixel at the position (x, y)
// When using this function, put the values in rgb in binary format (ex: 0b011 (red = 0, green = 1, blue = 1))
void SetPixel(byte x, byte y, Color rgb)
{
	Buffer[(x * 3 + 0) / 8][y] = (rgb >> 2) % 2; // Red
	Buffer[(x * 3 + 1) / 8][y] = (rgb >> 1) % 2; // Green
	Buffer[(x * 3 + 2) / 8][y] = (rgb >> 0) % 2; // Blue
}
//-----Test Game
byte x = WIDTH/2;
byte y = HEIGHT/2;
byte color_test = 0;
byte size_test = 1;

void update_test() {
  if (Keys & 0b100000) {
    //Going Up
    y--;
  }
  if (Keys & 0b10000) {
    //Going Left
    x--;
  }
  if (Keys & 0b1000) {
    //Going Right
    x++;
  }
  if (Keys & 0b100) {
    //Going Down
    y++;
  }
  if (Keys & 0b10) {
    //Select
    if (++color_test >> 3) color_test = 0;
  }
  if (Keys & 1) {
    //Exit
    if (++size_test >> 3) size_test = 1;
  }
}

void draw_test() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i >= x && i < x + size_test &&
          j >= y && j < y + size_test) {
        Buffer[i][j] = color_test;      
      }
      else {
        Buffer[i][j] = 0b111;
      }
    }
  }
}


// -----Code:

volatile int Line = SC_Y;

ISR(TIMER2_OVF_vect)
{
	sei();
	__asm__("sleep \n");
}

char showroom = 0;

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
		byte pixel = WIDTH;// i = 5;
		while(pixel--)//Line < 250 || Line > 250? 1 : 0
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

  memset(Buffer, 0x7, sizeof(Buffer));
	
	sei(); // set interrupts
}

void loop()
{
  //Keys: [5]Left [4]Down [3]Up [2]Right [1]Select [0]Exit
	Keys = PINC;
  switch (Mode) {
    case 1:
      update_test();
      draw_test();
    break;
  }
  
  delay(50);
}
