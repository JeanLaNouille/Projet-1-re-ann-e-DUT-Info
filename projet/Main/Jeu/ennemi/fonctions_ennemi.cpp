#include "classeEnnemi.h"

ennemi::ennemi() : e_posX(0), e_posY(0),e_etat(0),e_type(0),e_hp(0),e_walkStep(0),e_fov(3),e_walkSpeed(100),e_orientation(0)
{

}

ennemi::ennemi(int m_posX, int m_posY,int m_type): e_posX(m_posX), e_posY(m_posY),e_etat(0),e_type(m_type),e_hp(0),e_walkStep(0),e_fov(3),e_walkSpeed(100),e_orientation(0)
{

}

void ennemi::setPosition(int m_posX, int m_posY)
{
    e_posX=m_posX;
    e_posY=m_posY;
}
void ennemi::setX(int m_x)
{
    e_posX=m_x;
}
void ennemi::setX(int m_y)
{
    e_posY=m_y;
}
void ennemi::setEtat(int m_etat)
{
    e_etat=m_etat;
}
void ennemi::setType(int m_type)
{
    e_type=m_type;
}
void ennemi::setHP(int m_hp)
{
    e_hp=m_hp;
}


int ennemi::getX()
{
    return e_posX;
}
int ennemi::getY()
{
    return e_posY;
}
int ennemi::getEtat()
{
    return e_etat;
}

int ennemi::isAlerted(int posXjoueur, int posYjoueur)
{

}

void ennemi::deplacementNormal();
{
    e_orientation="Right";
    int numCase;
    for(int i =0; i<MAP_Y;i++)
    {

        for(int j=0;j<MAP_X;j++)
        {
            if(map[] )

        }
    }
}

void ennemi::depDroite();
{
    int preX, int preY;
    ennemi::setX()=ennemi::getX+e_walkStep;
}


