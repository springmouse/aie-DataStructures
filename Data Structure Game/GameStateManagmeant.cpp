#include "GameStateManagmeant.h"
#include "Information.h"
#include "Factory.h"


GameStateManagmeant::GameStateManagmeant()
{
}


GameStateManagmeant::~GameStateManagmeant()
{
	//cleans up all the lists
    m_registeredStates.DeleteAll();
	m_pushedStates.DeleteAll();
	m_stateStack.DeleteAll();
}

void GameStateManagmeant::pushState(int id)
{
	assert(id < eGameStateType::Total && "Game State ID was not valid");
	//adds the picked state to be pushed onto m_stateStack
    m_pushedStates.PushBack(m_registeredStates.GetElemeantAt(id));
}

void GameStateManagmeant::Update(float deltaTime)
{
	//checks if we need to call on the pushState() functions before continuing with
	//the Update
    if (INFOMATION->push)
    {
        INFOMATION->push = false;
        pushState(INFOMATION->pushID);
    }

	//checks if we need to pop a state off
    while (INFOMATION->pop)
    {
        INFOMATION->pop = false;

		//runs the closing functions of the GameState
        m_stateStack.Last()->exit();
        auto temp = m_stateStack.Last();
        m_stateStack.PopBack();

        temp->onPopped();

		//runs the enter functions for the last elemeant in the list
        if (m_stateStack.Empty() == false)
        {
            m_stateStack.Last()->enter();
        }
    }

	//loops throught the sataes being held in m_pushedStates
    for (auto pushedState : m_pushedStates)
    {
		//runs the exit function on the last elemeant in m_stateStack
        if (m_stateStack.Empty() == false)
        {
            m_stateStack.Last()->exit();
        }

		//runs the opening functions for the state just added
        pushedState->onPushed();
        m_stateStack.PushBack(pushedState);
        m_stateStack.Last()->enter();
    }

	//clears pushed states
    m_pushedStates.DeleteAll();

	//goes through all the states in the list and runs there update functions
    for  (auto state : m_stateStack)
    {
        state->onUpdate(deltaTime);
    }
    
}
