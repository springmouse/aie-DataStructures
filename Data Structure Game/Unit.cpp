#include "Unit.h"



Unit::Unit()
{
    m_movemeantTimer = 0;

    m_globalPos = Matrix3().SetIdentity();
    m_localPos = Matrix3().SetIdentity();
}


Unit::~Unit()
{
}
