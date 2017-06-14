#include "GameStateManagmeant.h"
#include "Factory.h"


GameStateManagmeant::GameStateManagmeant(unsigned int stateCount)
{
}


GameStateManagmeant::~GameStateManagmeant()
{
    m_registeredStates.DeleteAll();
}

void GameStateManagmeant::pushState(int id)
{
    m_pushedStates.PushBack(m_registeredStates.GetElemeantAt(id));
}

void GameStateManagmeant::popState()
{
    m_popState = true;
}

void GameStateManagmeant::Update(float deltaTime)
{
    while (m_popState)
    {
        m_popState = false;

        m_stateStack.Last()->exit();
        auto temp = m_stateStack.Last();
        m_stateStack.PopBack();
        temp->onPopped();

        if (m_stateStack.Empty() == false)
        {
            m_stateStack.Last()->enter();
        }
    }

    for (auto pushedState : m_pushedStates)
    {
        if (m_stateStack.Empty() == false)
        {
            m_stateStack.Last()->exit();
        }

        pushedState->onPushed();
        m_stateStack.PushBack(pushedState);
        m_stateStack.Last()->enter();
    }

    m_pushedStates.DeleteAll();

    for  (auto state : m_stateStack)
    {
        state->onUpdate(deltaTime);
    }

}
