#pragma once
#include <Vector2.h>
#include <Vector3.h>
#include <Matrix3.h>
#include "Input.h"

enum eUnitTypes
{
    PLAYER,
    BASICENEMY
};

class Unit
{
public:
    Unit();
    ~Unit();

    virtual void Update(float deltaTime) {};

    Matrix3 m_globalPos;

protected:

    Matrix3 m_localPos;

    float m_speed;
    float m_movemeantTimer;

    float m_rotateTimer;
};

