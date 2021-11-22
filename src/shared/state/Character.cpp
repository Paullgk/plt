#include <state/Character.h>  // Included from library shared_static
#include "Character.h"
namespace state {


state::Character::Character(std::string rCharacterName, Major rCharacterMajor, CharacterStatus rCharacterStatus) {

    this->mName = rCharacterName;
    this->mCharacterMajor = rCharacterMajor;
    this->mCharacterStatus = rCharacterStatus;
}


void state::Character::SetCharacterStats(StatsName rStatsName, int rValue) {
    switch (rStatsName)
    {
    case MAX_LIFE_POINTS:
        mCharacterStats.Set_max_life_points(rValue);
        break;

    case LIFE_POINTS:
        mCharacterStats.Set_life_points(rValue);
        break;

    case ATTACK:
        mCharacterStats.Set_attack(rValue);
        break;

    case POWER:
        mCharacterStats.Set_power(rValue);
        break;
    
    case DEFENSE:
        mCharacterStats.Set_defense(rValue);
        break;

    case LUCK:
        mCharacterStats.Set_luck(rValue);
        break;

        
    default:
        break;
    }  
}

int state::Character::GetCharacterStats(StatsName rStatsName) {
    switch (rStatsName)
    {
    case MAX_LIFE_POINTS:
        return this->mCharacterStats.Get_max_life_points();
        break;

    case LIFE_POINTS:
        return this->mCharacterStats.Get_life_points();
        break;

    case ATTACK:
        return this->mCharacterStats.Get_attack();
        break;

    case POWER:
        return this->mCharacterStats.Get_power();
        break;
    
    case DEFENSE:
        return this->mCharacterStats.Get_defense();
        break;

    case LUCK:
        return this->mCharacterStats.Get_luck();
        break;

        
    default:
        break;
    } 



}

void state::Character::SetCharacterAction(ActionListCommand rAction, int rValue){
    switch (rAction)
    {
    case ATTACK_1:
        mCharacterAction.SetAttack(1, rValue);
        break;
    
    default:
        break;
    }

}


Major state::Character::GetMajor() {
    return this->mCharacterMajor;
}


void state::Character::SetCharacterStatus(CharacterStatus rNewStatus){
    this->mCharacterStatus = rNewStatus;

}

CharacterStatus state::Character::GetCharacterStatus(){

    return this->mCharacterStatus;

}


Action* state::Character::MakeAction(ActionListCommand rActionType){
    switch (rActionType)
    {
    case ATTACK_1:
        return this->mCharacterAction.GetAttack(1);
    
    default:
        break;
    }

    
}




}