#include <state/Character.h>  // Included from library shared_static
#include "Character.h"
namespace state {




state::Character::Character(Major rCharacterMajor) {
    
    

    
    
    
    switch (rCharacterMajor)
    {

        
    case ELEC:
        this->mCharacterMajor = ELEC;



        break;
    
    case SIGNAL:

        break;

    case AUTO:

        break;

    case INFO:
        break;

    case SCIENCES_HUMAINES:
        break;

    default:
        break;
    }
    
    



}

int state::Character::DoAttack() {
    
}

int state::Character::GetStats() {
    
}

CharacterStatus state::Character::GetState() {
    
}

void state::Character::SetStats(Stats stats) {
    
}

void state::Character::SetState(CharacterStatus rNewState) {
    
}

int state::Character::GetMajor(){
    return this->mCharacterMajor;

}



}