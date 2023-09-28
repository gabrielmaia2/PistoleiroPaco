#define SNAKE_MAX_SIZE 30

char snakePosX[SNAKE_MAX_SIZE]; // posicao em x
char snakePosY[SNAKE_MAX_SIZE]; // posicao em y
unsigned char snakeTailIt = 0; // iterador da cabeca
unsigned char snakeHeadIt = 0; // iterador do rabo
char snakeDirX; // direcao da cobra em x (-1 = esquerda, 1 = direita, 0 = nada)
char snakeDirY; // direcao da cobra em Y (-1 = cima, 1 = baixo, 0 = nada)

// desenha cobra
void draw()
{
	// iteracao
	for (i = SNAKE_TAIL_POSITION; i < SNAKE_SIZE + SNAKE_TAIL_POSITION; i++)
	{
		// iguala o buffer na posicao do item atual a cor da cobra
		BUFFER(snakePosX[i % SNAKE_MAX_SIZE], snakePosY[i % SNAKE_MAX_SIZE]) = COLOR_SNAKE;
		
		// checa se essa posicao esta colidindo com a cabeca
		if ((snakePosX[i % SNAKE_MAX_SIZE] == snakePosX[snakeHeadIt]) &&
			(snakePosY[i % SNAKE_MAX_SIZE] == snakePosY[snakeHeadIt]))
		{
			// se colidir
			Scene = YouLose; // muda de cena para voce perdeu
		}
	}
}

void update()
{
	// Atualizar posicao da cobra
	snakeHeadIt = (snakeHeadIt + 1) % SNAKE_MAX_SIZE;
	
	// Se a cobra NÃO for crescer
	if (!ATE_FOOD)
	{
		snakeTailIt = (snakeTailIt + 1) % SNAKE_MAX_SIZE;
	}
	
	// Seta posicao da nova cabeça (apos incrementar o iterador da cabeca) (pega antiga posicao e soma a direcao)
	snakePosX[snakeHeadIt] = snakePosX[snakeHeadIt - 1] + snakeDirX;
	snakePosY[snakeHeadIt] = snakePosY[snakeHeadIt - 1] + snakeDirY;
	
	// Checa se chegou no tamanho maximo (SNAKE_MAX_SIZE)
	if((snakeHeadIt + 1) % SNAKE_MAX_SIZE == snakeTailIt)
		{
			// se chegar no tamanho maximo
			Scene = YouWon; // muda de cena para voce ganhou
		}
}