#ifndef CLASSEJOUEUR_H_INCLUDED
#define CLASSEJOUEUR_H_INCLUDED

class joueur
{
    public:
        joueur();
        joueur(int m_posX, m_posY);

        void setX(int m_x);
        void setY(int m_y);
        void setPosition(int m_x, int m_y);
        void setHP(int m_hp);


    private:
        int j_posX;
        int j_posY;
        int j_hp;
        int j_walkSpeed;
};

#endif // CLASSEJOUEUR_H_INCLUDED
