#pragma once
#include "Jogador.h"


class Game
{
private:
	sf::RenderWindow *window;
	sf::Text topText;
	sf::Font font;
	Jogador jogador1;
	Jogador jogador2;
	Tabuleiro  tabuleiro;
	bool turno;

public:
	Game();
	~Game();
	void executar();
	bool reiniciar();
};
