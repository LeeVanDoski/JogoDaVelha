#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() :janela(NULL), listaMarcadores(NULL)
{

	for (int i = 0; i < CASAS; i++)
		for (int j = 0; j < CASAS; j++)
			matrizTab[i][j] = 0;

	criaTabuleiro();
	moverMarcador(sf::Vector2i(0, 0), P1_COR);

}
Tabuleiro::~Tabuleiro() 
{
	resetaTab();
}

void Tabuleiro::desenhaTabuleiro() {

	for (int i = 0; i < 12; i++)
	{
		sf::Vertex linha[] = { linhas[i][0],linhas[i][1], };
		janela->draw(linha, 2, sf::Lines);
	}

	for (int i = 0; i < 4; i++)
	{
		sf::Vertex linha[] = { marcador[i][0],marcador[i][1], };
		janela->draw(linha, 2, sf::Lines);
	}
	Circulo* t = listaMarcadores;
	while (t != NULL)
	{
		janela->draw(*(t->circulo));
		t = t->prox;
	}

}

void Tabuleiro:: criaTabuleiro()
{
	//letreiro vertical cima
	linhas[0][0] = sf::Vertex(sf::Vector2f(1, (COMP / 4) - 1), sf::Color::Yellow);
	linhas[0][1] = sf::Vertex(sf::Vector2f(1, 0), sf::Color::Yellow);
	//letreiro vertical baixo
	linhas[1][0] = sf::Vertex(sf::Vector2f(LARG, (COMP / 4) - 1), sf::Color::Yellow);
	linhas[1][1] = sf::Vertex(sf::Vector2f(LARG, 0), sf::Color::Yellow);
	//letreiro horizontal dir
	linhas[2][0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Yellow);
	linhas[2][1] = sf::Vertex(sf::Vector2f(LARG, 0), sf::Color::Yellow);
	//letreiro horizontal esq
	linhas[3][0] = sf::Vertex(sf::Vector2f(0, (COMP / 4) - 1), sf::Color::Yellow);
	linhas[3][1] = sf::Vertex(sf::Vector2f(LARG, (COMP / 4) - 1), sf::Color::Yellow);
	//linhaHorizontal1
	linhas[4][0] = sf::Vertex(sf::Vector2f(0, COMP / 4), sf::Color::Blue);
	linhas[4][1] = sf::Vertex(sf::Vector2f(LARG, COMP / 4), sf::Color::Blue);
	//linhaHorizontal2
	linhas[5][0] = sf::Vertex(sf::Vector2f(0, COMP), sf::Color::Blue);
	linhas[5][1] = sf::Vertex(sf::Vector2f(LARG, COMP), sf::Color::Blue);
	// linhaHorizontal3
	linhas[6][0] = sf::Vertex(sf::Vector2f(0, COMP / 2), sf::Color::Blue);
	linhas[6][1] = sf::Vertex(sf::Vector2f(LARG, COMP / 2), sf::Color::Blue);
	//linhaHorizontal4
	linhas[7][0] = sf::Vertex(sf::Vector2f(0, 3 * (COMP / 4)), sf::Color::Blue);
	linhas[7][1] = sf::Vertex(sf::Vector2f(LARG, 3 * (COMP / 4)), sf::Color::Blue);
	//linhaVertical1
	linhas[8][0] = sf::Vertex(sf::Vector2f(1, COMP / 4), sf::Color::Blue);
	linhas[8][1] = sf::Vertex(sf::Vector2f(1, COMP), sf::Color::Blue);
	// linhaVertical2
	linhas[9][0] = sf::Vertex(sf::Vector2f(LARG, COMP / 4), sf::Color::Blue);
	linhas[9][1] = sf::Vertex(sf::Vector2f(LARG, COMP), sf::Color::Blue);
	//linhaVertical3
	linhas[10][0] = sf::Vertex(sf::Vector2f(LARG / 3, COMP / 4), sf::Color::Blue);
	linhas[10][1] = sf::Vertex(sf::Vector2f(LARG / 3, COMP), sf::Color::Blue);
	//linhaVertical4
	linhas[11][0] = sf::Vertex(sf::Vector2f(2 * (LARG / 3), COMP / 4), sf::Color::Blue);
	linhas[11][1] = sf::Vertex(sf::Vector2f(2 * (LARG / 3), COMP), sf::Color::Blue);
}



bool Tabuleiro::colocaPeça(sf::Vector2i pos, sf::Color cor)
{
	if (matrizTab[pos.x][pos.y] == 0)
	{
		sf::CircleShape* circulo = new sf::CircleShape();
		circulo->setRadius(75);
		circulo->setPosition((pos.y * 200) + 25, (pos.x * 200) + 225);
		circulo->setFillColor(cor);
		listaMarcadores = insert(circulo);

		if (cor == P1_COR)
		{
			matrizTab[pos.x][pos.y] = 1;

		}
		else
		{
			matrizTab[pos.x][pos.y] = 2;
		}
		return true;
	}
	return false;
}

void Tabuleiro::moverMarcador(sf::Vector2i pos, sf::Color cor)
{
	marcador[0][0] = sf::Vertex(sf::Vector2f(pos.y * 200, (pos.x * 200) + 200), cor);
	marcador[0][1] = sf::Vertex(sf::Vector2f((pos.y + 1) * 200, (pos.x * 200) + 200), cor);

	marcador[1][0] = sf::Vertex(sf::Vector2f(pos.y * 200, ((pos.x + 1) * 200) + 200), cor);
	marcador[1][1] = sf::Vertex(sf::Vector2f((pos.y + 1) * 200, ((pos.x + 1) * 200) + 200), cor);

	marcador[2][0] = sf::Vertex(sf::Vector2f(pos.y * 200+1, ((pos.x) * 200) + 200), cor);
	marcador[2][1] = sf::Vertex(sf::Vector2f(pos.y * 200+1, (pos.x + 1) * 200 + 200), cor);

	marcador[3][0] = sf::Vertex(sf::Vector2f((pos.y + 1) * 200, ((pos.x) * 200) + 200), cor);
	marcador[3][1] = sf::Vertex(sf::Vector2f((pos.y + 1) * 200, (pos.x + 1) * 200 + 200), cor);


}

void Tabuleiro::setWindow(sf::RenderWindow* jal)
{
	janela = jal;
}

int Tabuleiro::checaJogo()
{
	int flag = 0;
	for (int i = 0; i < CASAS; i++)
		for (int j = 0; j < CASAS; j++)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					if ((matrizTab[i][j] == 1 && matrizTab[i + 1][j + 1] == 1 && matrizTab[i + 2][j + 2] == 1) ||
						(matrizTab[i][j] == 2 && matrizTab[i + 1][j + 1] == 2 && matrizTab[i + 2][j + 2] == 2))
						return matrizTab[i][j];
					else if ((matrizTab[i][j] == 1 && matrizTab[i + 1][j] == 1 && matrizTab[i + 2][j] == 1) ||
						(matrizTab[i][j] == 2 && matrizTab[i + 1][j] == 2 && matrizTab[i + 2][j] == 2))
						return matrizTab[i][j];
				}
				if ((matrizTab[i][j] == 1 && matrizTab[i][j + 1] == 1 && matrizTab[i][j + 2] == 1) ||
					(matrizTab[i][j] == 2 && matrizTab[i][j + 1] == 2 && matrizTab[i][j + 2] == 2))
					return matrizTab[i][j];
			}
			if (i == 0)
			{
				if ((matrizTab[i][j] == 1 && matrizTab[i + 1][j] == 1 && matrizTab[i + 2][j] == 1) ||
					(matrizTab[i][j] == 2 && matrizTab[i + 1][j] == 2 && matrizTab[i + 2][j] == 2))
					return matrizTab[i][j];
				if (j == 2)
				{
					if ((matrizTab[i][j] == 1 && matrizTab[i + 1][j - 1] == 1 && matrizTab[i + 2][j - 2] == 1) ||
						(matrizTab[i][j] == 2 && matrizTab[i + 1][j - 1] == 2 && matrizTab[i + 2][j - 2] == 2))
						return matrizTab[i][j];
				}
			}
			if (matrizTab[i][j] == 0)
				flag++;
		}
	if (flag == 0)
		return 3;
	else
		return 0;
}

void Tabuleiro::resetaTab()
{
	for (int i = 0; i < CASAS; i++)
		for (int j = 0; j < CASAS; j++)
		{
			matrizTab[i][j] = 0;
		}
	while (listaMarcadores != NULL)
	{
		Circulo* tmp = listaMarcadores;
		listaMarcadores = listaMarcadores->prox;
		delete tmp;
	}
}