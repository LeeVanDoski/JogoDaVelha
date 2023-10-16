#pragma once
#include "Tabuleiro.h"

class Jogador
{
private:
	sf::Vector2i pos;
	sf::Color cor;
	Tabuleiro* tabuleiro;
	bool turno;
	Jogador *jogador2;

public:
	Jogador();
	~Jogador();
	void move();
	void setTurno(bool tur);
	void setCor(sf::Color color);
	void setTabuleiro(Tabuleiro* tab);
	bool getTurno();
	void setInimigo(Jogador* jog);
	void resetPos();
	
};