#include <state/State.h>  // Included from library shared_static
#include "State.h"
namespace state {
    


State::State(CombatStatus rCombatStatus) {
    
}

std::vector<Character> State::GetCharacter() {
    
}

void State::MoveNextTurn() {
    
}

void State::SetCombatState(CombatStatus rNewCombatState) {
    this->mCombatStatus = rNewCombatState;
}

CombatStatus State::GetCombatState(){
    return this->mCombatStatus;
}

void State::InitializeEnemyCharactersList() {
    
}

void State::BeginFight() {
    
}

void State::BeginRandomEvent() {
    
}

void State::GotoNextArena() {
    
}

void State::AddPlayerCharacter(Character rNewCharacter) {
    
}

}