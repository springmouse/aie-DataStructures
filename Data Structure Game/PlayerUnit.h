#pragma once
#include "Unit.h"

class PlayerUnit :
    public Unit
{
public:
    PlayerUnit();
    ~PlayerUnit();

    void Update(float deltaTime);
};

