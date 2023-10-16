#include "Jogador.h"

Jogador::Jogador() :pos(0, 0), turno(false), tabuleiro(NULL), jogador2(NULL)
{}
Jogador::~Jogador()
{
	tabuleiro = NULL;
	jogador2 = NULL;
}
void Jogador::move()
{
	if (turno)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (pos.x - 1 >= 0)
				pos.x -= 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (pos.y - 1 >= 0)
				pos.y -= 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (pos.x + 1 < CASAS)
				pos.x += 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (pos.y + 1 < CASAS)
				pos.y += 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (tabuleiro->colocaPeça(pos, cor))
			{
				turno = false;
				jogador2->setTurno(true);
			}
		}
		tabuleiro->moverMarcador(pos, cor);
	}
}
void Jogador:: setTurno(bool tur)
{
	turno = tur;
}
void Jogador::setCor(sf::Color color)
{
	cor = color;
}
void Jogador::setTabuleiro(Tabuleiro* tab)
{
	tabuleiro = tab;
}
bool Jogador::getTurno()
{
	return turno;
}
void Jogador::setInimigo(Jogador* jog)
{
	jogador2 = jog;
}
void Jogador:: resetPos()
{
	pos = sf::Vector2i(0, 0);
}