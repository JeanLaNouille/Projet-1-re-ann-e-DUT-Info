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

//Constantes d'environnement
    int const LARGEUR_TITRE = 100;
    int const HAUTEUR_TITRE = 80;
    int const LARGEUR_MENU = 80;
    int const HAUTEUR_MENU = 95;
    int const NB_BOUTONS = 6;
    float const ECHELLE = 3.f;


//Definition des textures
    Texture texTitleCard;
    Texture texTitleCard2;
    Texture textMenuList1;
    Texture textMenuList2;
    Texture textMenuList3;
    Texture textMenuList4;
    Texture textMenuList5;

    Texture textMenuBackground;

//Textures des boutons du menu options
    Texture textVSync;
    Texture textSound;
    Texture textMusic;

    Texture textCheckBox;
//    Texture textchoixRes;


//Definition des sprites
    Sprite titleCard;
    Sprite MenuList;
    Sprite menuBackground;

//Def des sprites des otions
    Sprite choixVSync;
    Sprite choixSon;
    Sprite choixMusic;
    Sprite checkBox;
//    Sprite choixRes;

//Definition des evenements
    Event evenement;

//Definition du buffer

//sf::SoundBuffer bgMusicBuff;
    sf::SoundBuffer buttonSoundBuff;
    sf::Music bgMusic;

//Test du chargement des sons
    if (!bgMusic.openFromFile("P:/projet/ressources/music/menu/menu_bg.ogg"))
        printf("Erreur de chargement de la musique!\n");
    else
        printf("Musique chargee !\n");

    if (!buttonSoundBuff.loadFromFile("P:/projet/ressources/sounds/menu/button_sound.ogg"))
        printf("Erreur de chargement du son!\n");
    else
        printf("Son charge !\n");



//definition des sons
    //bgMusic.setBuffer(bgMusicBuff);
    sf::Sound buttonSound;
    buttonSound.setBuffer(buttonSoundBuff);

//Test du chargement des textures
    if (!texTitleCard.loadFromFile("P:/projet/ressources/sprites/menu/titleCard2.png"))
        printf("PB de chargement de l'image !\n");
    if (!texTitleCard2.loadFromFile("P:/projet/ressources/sprites/menu/titleCard2.2.png"))
        printf("PB de chargement de l'image !\n");

    if (!textMenuList1.loadFromFile("P:/projet/ressources/sprites/menu/choix1.png"))
        printf("PB de chargement de l'image !\n");
    if (!textMenuList2.loadFromFile("P:/projet/ressources/sprites/menu/choix2.png"))
        printf("PB de chargement de l'image !\n");
    if (!textMenuList3.loadFromFile("P:/projet/ressources/sprites/menu/choix3.png"))
        printf("PB de chargement de l'image !\n");
    if (!textMenuList4.loadFromFile("P:/projet/ressources/sprites/menu/choix4.png"))
        printf("PB de chargement de l'image!\n");
    if (!textMenuList5.loadFromFile("P:/projet/ressources/sprites/menu/choix5.png"))
        printf("PB de chargement de l'image!\n");
    if (!textMenuBackground.loadFromFile("P:/projet/ressources/sprites/menu/menu_background.jpg"))
        printf("PB de chargement de l'image !\n");

//textures des options
    if (!textVSync.loadFromFile("P:/projet/ressources/sprites/menu/vsync.png"))
        printf("PB de chargement de l'image !\n");
    if (!textSound.loadFromFile("P:/projet/ressources/sprites/menu/sound.png"))
        printf("PB de chargement de l'image !\n");
    if (!textMusic.loadFromFile("P:/projet/ressources/sprites/menu/music.png"))
        printf("PB de chargement de l'image !\n");
    if (!textCheckBox.loadFromFile("P:/projet/ressources/sprites/menu/checkBox.png"))
        printf("PB de chargement de l'image !\n");


//    if (!textchoixRes.loadFromFile("P:/projet/ressources/sprites/menu/800X600.png"))
//        printf("PB de chargement de l'image !\n");


//affectation des textures aux sprites
    titleCard.setTexture(texTitleCard);
    MenuList.setTexture(textMenuList1);
    menuBackground.setTexture(textMenuBackground);

//affectation des textures aux sprites des options
    choixVSync.setTexture(textVSync);
    choixSon.setTexture(textSound);
    choixMusic.setTexture(textMusic);
    checkBox.setTexture(textCheckBox);
    checkBox.setTextureRect(sf::IntRect(0,0,20,20));
//    choixRes.setTexture(textchoixRes);


//Placement et echelle du logo et des boutons
    MenuList.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE/1.5))/2, HAUTEUR_TITRE*(ECHELLE)+10*(ECHELLE));
    MenuList.setScale(ECHELLE/1.5,ECHELLE/1.5);
    titleCard.setScale(ECHELLE,ECHELLE);
    titleCard.setPosition((LARGEUR_FENETRE-LARGEUR_TITRE*ECHELLE)/2,10*ECHELLE);
    menuBackground.setPosition(-(LARGEUR_FENETRE-LARGEUR_MENU)/2, -(HAUTEUR_FENETRE-HAUTEUR_MENU)/2);

////Placement et echelle du logo et des boutons des options
    choixVSync.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))/2,80);
    choixMusic.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))/2,100+20*ECHELLE);
    choixSon.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))/2,120+40*ECHELLE);
//    choixRes.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))/2,140+60*ECHELLE);

    choixVSync.setScale(ECHELLE,ECHELLE);
    choixMusic.setScale(ECHELLE,ECHELLE);
    choixSon.setScale(ECHELLE,ECHELLE);
    checkBox.setScale(ECHELLE,ECHELLE);
//    choixRes.setScale(ECHELLE,ECHELLE);

//La musique demarre
    bgMusic.play();
    bgMusic.setLoop(true);


    bool choixOptions=false;
    int comptPosition = 1;
    int comptPositionOption = 1;

    bool checkVSync = true;
    bool checkMusic = true;
    bool checkSound = true;

//image du logo
    int textureLogo=0;


    while (fenetre.isOpen())
    {
        fenetre.clear();
        textureLogo++;
        if (textureLogo>=200)
            titleCard.setTexture(texTitleCard2);
        else if(textureLogo<200)
            titleCard.setTexture(texTitleCard);
        if (textureLogo==400)
            textureLogo=0;
        while (fenetre.pollEvent(evenement))
        {
            switch (evenement.type)
            {
            case Event::KeyPressed:
                switch (evenement.key.code)
                {
                case Keyboard::Down:
                    buttonSound.play();
                    comptPosition++;
                    if (comptPosition>NB_BOUTONS-1)
                    {
                        comptPosition=1;
                    }
                    break;

                case Keyboard::Up:
                    buttonSound.play();
                    comptPosition--;
                    if (comptPosition<1)
                    {
                        comptPosition=NB_BOUTONS-1;
                    }
                    break;
                case Keyboard::BackSpace:
                    fenetre.close();
                    break;
                case Keyboard::Escape:
                    fenetre.close();
                    break;
                }
            default:
                break;
                break;
            case Event::Closed:
            {
                fenetre.close();
                break;
            }
            }
        }


//Les textures sont changées en fonctio de la position du curseur
        switch (comptPosition)
        {
        case 1:
        {
            MenuList.setTexture(textMenuList1);
            break;
        }
        case 2:
        {
            MenuList.setTexture(textMenuList2);
            break;
        }
        case 3:
        {
            MenuList.setTexture(textMenuList3);
            break;
        }
        case 4:
            MenuList.setTexture(textMenuList4);
            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                choixOptions=true;
                //debug
                printf("%d\n", choixOptions);
            }
            break;
        case 5:
            MenuList.setTexture(textMenuList5);
            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                fenetre.close();

            }
            break;

        }

//Affichage des éléments du menu
        fenetre.draw(menuBackground);
        fenetre.draw(titleCard);
        fenetre.draw(MenuList);
        fenetre.display();

//Menu des options
        while(choixOptions)
        {

            fenetre.clear();
            fenetre.draw(menuBackground);
            fenetre.draw(choixMusic);
            fenetre.draw(choixSon);
            fenetre.draw(choixVSync);
            checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,80);
            fenetre.draw(checkBox);
            checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,100+20*ECHELLE);
            fenetre.draw(checkBox);
            checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,120+40*ECHELLE);
            fenetre.draw(checkBox);
//            fenetre.draw(choixRes);



            while (fenetre.pollEvent(evenement))
            {
                switch (evenement.type)
                {
                case Event::KeyPressed:
                    switch (evenement.key.code)
                    {
                    case Keyboard::Down:
                        buttonSound.play();
                        comptPositionOption++;
                        if (comptPositionOption>3)
                        {
                            comptPositionOption=1;
                        }
                        break;

                    case Keyboard::Up:
                        buttonSound.play();
                        comptPositionOption--;
                        if (comptPositionOption<1)
                        {
                            comptPositionOption=3;
                        }
                        break;

                    case Keyboard::Escape:
                        fenetre.close();
                        break;

                    case Keyboard::BackSpace:
                        choixOptions=false;
                        break;
                    }
                default:
                    break;
                    break;

                case Event::Closed:
                {
                    fenetre.close();
                    break;
                }
                }
            }

            switch (comptPositionOption)
            {
            case 1:
            {
                choixVSync.setTextureRect(sf::IntRect(0,0,80,20));
                choixMusic.setTextureRect(sf::IntRect(0,20,80,20));
                choixSon.setTextureRect(sf::IntRect(0,20,80,20));

                if(Keyboard::isKeyPressed(Keyboard::Return) && !checkVSync)
                {
                    checkVSync=true;
                }
                else if (Keyboard::isKeyPressed(Keyboard::Return) && checkVSync)
                    checkVSync=false;



                break;
            }
            case 2:
            {
                choixVSync.setTextureRect(sf::IntRect(0,20,80,20));
                choixMusic.setTextureRect(sf::IntRect(0,0,80,20));
                choixSon.setTextureRect(sf::IntRect(0,20,80,20));

                if(Keyboard::isKeyPressed(Keyboard::Return) && !checkMusic)
                {
                    checkMusic=true;
                }
                else if (Keyboard::isKeyPressed(Keyboard::Return) && checkMusic)
                    checkMusic=false;



                break;
            }
            case 3:
            {
                choixVSync.setTextureRect(sf::IntRect(0,20,80,20));
                choixMusic.setTextureRect(sf::IntRect(0,20,80,20));
                choixSon.setTextureRect(sf::IntRect(0,0,80,20));

                if(Keyboard::isKeyPressed(Keyboard::Return) && !checkSound)
                {
                    checkSound=true;
                }
                else if (Keyboard::isKeyPressed(Keyboard::Return) && checkSound)
                    checkSound=false;

                break;
            }
            }

            if(checkVSync)
            {
                checkBox.setTextureRect(sf::IntRect(0,20,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,80);
                fenetre.draw(checkBox);
                fenetre.setVerticalSyncEnabled(true);

            }
            else
            {
                checkBox.setTextureRect(sf::IntRect(0,0,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,80);
                fenetre.draw(checkBox);
                fenetre.setVerticalSyncEnabled(false);
            }

            if(checkMusic)
            {
                checkBox.setTextureRect(sf::IntRect(0,20,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,100+20*ECHELLE);
                fenetre.draw(checkBox);
                bgMusic.play();
            }
            else
            {
                checkBox.setTextureRect(sf::IntRect(0,0,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,100+20*ECHELLE);
                fenetre.draw(checkBox);
                bgMusic.stop();
            }

            if(checkSound)
            {
                checkBox.setTextureRect(sf::IntRect(0,20,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,120+40*ECHELLE);
                fenetre.draw(checkBox);
            }
            else
            {
                checkBox.setTextureRect(sf::IntRect(0,0,20,20));
                checkBox.setPosition((LARGEUR_FENETRE-LARGEUR_MENU*(ECHELLE))+50,120+40*ECHELLE);
                fenetre.draw(checkBox);
            }

            fenetre.display();
            sleep(milliseconds(50));



        }
        choixOptions=false;

    }

    return 0;
}

