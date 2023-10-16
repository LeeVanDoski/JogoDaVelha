#include "Game.h"

Game::Game()
{
	font.loadFromFile("Aaargh.ttf");
	topText.setFont(font);
	topText.setCharacterSize(15);
	topText.setFillColor(sf::Color::Yellow);
	topText.setString("Mova-se com WASD, selecione com Enter,reinicie o jogo com o ESC");
	topText.setPosition(20, 75);
	turno = false;
	window = new sf::RenderWindow(sf::VideoMode(LARG, COMP), "Jogo da Velha");
	window->setFramerateLimit(10);
	tabuleiro.setWindow(window);
	jogador1.setTabuleiro(&tabuleiro);
	jogador1.setCor(P1_COR);
	jogador2.setTabuleiro(&tabuleiro);
	jogador2.setCor(P2_COR);
	jogador1.setInimigo(&jogador2);
	jogador2.setInimigo(&jogador1);
	jogador2.setTurno(true);
	executar();
}
Game::~Game()
{
	window = NULL;
}
void Game::executar()
{
	bool gameFreeze = false;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		if (!gameFreeze)
		{
			if (jogador1.getTurno())
				jogador1.move();
			else
				jogador2.move();
			int vencedor = tabuleiro.checaJogo();
			if (vencedor == 1 || vencedor == 2)
			{
				gameFreeze = true;
				vencedor == 1 ? topText.setString("Verde venceu!!") : topText.setString("Vermelho venceu!!");
			}
			else if (vencedor == 3)
			{
				gameFreeze = true;
				topText.setString("Vocês empataram :(");
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameFreeze = reiniciar();
			}
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameFreeze = reiniciar();
			}
		}
		tabuleiro.desenhaTabuleiro();
		window->draw(topText);
		window->display();
	}
}
bool Game::reiniciar()
{
	tabuleiro.resetaTab();
	jogador1.resetPos();
	jogador2.resetPos();
	topText.setString("Bom jogo :))), mova-se com WASD e reinicie o jogo com o ESC");
	return false;
}