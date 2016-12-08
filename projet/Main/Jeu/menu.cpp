#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define HAUTEUR_FENETRE 600
#define LARGEUR_FENETRE 800

using namespace sf;


int main()
{

        RenderWindow fenetre(sf::VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Game");

        int const LARGEUR_TITRE = 100;
        int const HAUTEUR_TITRE = 80;
        int const ECHELLE = 3.f;

        Texture texTitleCard;
        Sprite titleCard;
        /*titleCard.setOrigin(sf::Vector2f(0,0));*/

        if (!texTitleCard.loadFromFile("P:/projet/ressources/titleCard2.png"))
            printf("PB de chargement de l'image !\n");

        titleCard.setTexture(texTitleCard);

        titleCard.setScale(ECHELLE,ECHELLE);
        titleCard.setPosition((LARGEUR_FENETRE-LARGEUR_TITRE*ECHELLE)/2,0);

        fenetre.draw(titleCard);
        fenetre.display();

        system("pause");
        return 0;
}
