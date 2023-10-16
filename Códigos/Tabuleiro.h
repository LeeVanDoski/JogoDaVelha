#pragma once

#include <SFML/Graphics.hpp>
#define CASAS 3
#define COMP 800
#define LARG 600
#define P1_COR sf::Color::Green
#define P2_COR sf::Color::Red

typedef struct node
{
	struct node* prox;
	sf::CircleShape *circulo;
}Circulo;

class Tabuleiro
{
private:
	int matrizTab[CASAS][CASAS];
	sf::Vertex marcador[4][2];
	sf::Vertex linhas[12][2];
	Circulo *listaMarcadores;
	sf::RenderWindow* janela;


	Circulo* insert(sf::CircleShape *circ) {
		Circulo* node = (Circulo*)malloc(sizeof(Circulo));
		node->circulo = circ;
		node->prox = listaMarcadores;
		return node;
	}

	void criaTabuleiro();

public:
	Tabuleiro();
	~Tabuleiro();
	void desenhaTabuleiro();
	bool colocaPeça(sf::Vector2i pos, sf::Color cor);
	void moverMarcador(sf::Vector2i pos, sf::Color cor);
	void setWindow(sf::RenderWindow* jal);
	int checaJogo();
	void resetaTab();
	
};