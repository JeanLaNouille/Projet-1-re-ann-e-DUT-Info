#ifndef CLASSEENNEMI_H_INCLUDED
#define CLASSEENNEMI_H_INCLUDED

class ennemi
{
    public:
        ennemi();
        ennemi(int m_posX, int m_posY,int m_type);
        void setPosition(int m_posX, int m_posY);
        void setX(int m_x);
        void setY(int m_y);
        void setEtat(int m_etat);
        void setType(int m_type);
        void setHP(int m_hp);


        void isAlerted(int posXjoueur, int posYjoueur);

        void deplacementAlerte();
        void deplacementNormal();


        int getX();
        int getY();
        int getEtat();


    private:
        int e_posX;
        int e_posY;
        int e_etat;
        int e_type;
        int e_hp;
        int e_walkStep;
        int e_fov;
        int e_walkSpeed;
        enum e_orientation;
};


#endif // CLASSEENNEMI_H_INCLUDED
