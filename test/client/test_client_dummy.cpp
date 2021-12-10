#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>
#include "client.h"


using namespace ::client;
using namespace ::state;

const float STRENGTH     = 2;
const float  NEUTRAL     = 1;
const float WEAK     = 0.5;

BOOST_AUTO_TEST_SUITE( test_client_dummy1 )


BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestSFML)
{
  {
    ::sf::Texture texture;
    BOOST_CHECK(texture.getSize() == ::sf::Vector2<unsigned int> {});
  }
}

BOOST_AUTO_TEST_CASE(TestCommand){
  {
/*     Engine UUT_Engine;
    state::Character UUT_Character_IS("IS", state::INFO, state::ALIVE);
    state::Character UUT_Character_SIA("SIA", state::SIGNAL, state::ALIVE);

    UUT_Character_IS.SetCharacterStats(LIFE_POINTS, 80);
    UUT_Character_IS.SetCharacterStats(ATTACK, 140);
    UUT_Character_IS.SetCharacterStats(POWER, 140);
    UUT_Character_IS.SetCharacterStats(DEFENSE, 80);
    UUT_Character_IS.SetCharacterStats(LUCK, 5);
    UUT_Character_IS.SetCharacterAction(state::ATTACK_1, 80, LUCK, 0, true);
    UUT_Character_IS.SetCharacterAction(state::ATTACK_2, 60, POWER, 20, true);
    UUT_Character_IS.SetCharacterAction(state::SPELL_1, 80, POWER, 0, true);
    UUT_Character_IS.SetCharacterAction(state::SPELL_2, 60, ATTACK, 20, true);




    UUT_Character_SIA.SetCharacterStats(LIFE_POINTS, 110);
    UUT_Character_SIA.SetCharacterStats(ATTACK, 80);
    UUT_Character_SIA.SetCharacterStats(POWER, 150);
    UUT_Character_SIA.SetCharacterStats(DEFENSE, 60);
    UUT_Character_SIA.SetCharacterStats(LUCK, 3);
    UUT_Character_SIA.SetCharacterAction(state::ATTACK_1, 60, LUCK, 3, false); 
    UUT_Character_SIA.SetCharacterAction(state::ATTACK_2, 80, LUCK, 0, true); 

    UUT_Character_SIA.SetCharacterAction(state::SPELL_1, 80, LUCK, 0, true); 
    UUT_Character_SIA.SetCharacterAction(state::SPELL_2, 60, LUCK, 3, true); 

    BOOST_CHECK_EQUAL(UUT_Engine.DEBUG_GetGameStatus(), state::IN_COMBAT);
 */



    //UUT_Engine.mCommand.ComputeAction(*(&UUT_Character_IS), *(&UUT_Character_SIA), CommandID::ATTACK_2);

    
    

/*     for(int i = 0; i<2;i++){
      //UUT_Engine.mCommand.ComputeCriticalHit(UUT_Character_IS.GetCharacterStats(LUCK));
      UUT_Engine.mCommand.ComputeAction(*(&UUT_Character_SIA), *(&UUT_Character_IS), CommandID::ATTACK_1);
      UUT_Engine.mCommand.ComputeAction(*(&UUT_Character_IS), *(&UUT_Character_SIA), CommandID::ATTACK_1);
      
    } */
     

  }




}

/* BOOST_AUTO_TEST_CASE(TestEngine){
  {
  Engine NewEngine;
  
  RandomIA IA1;
  RandomIA IA2;
  JSON_tools tools;
  Character test;
  CombatStatus GameStatus = INITIALISATION;
  int turn = 0;


  IA1.AddEngineObserver(&NewEngine);
  IA2.AddEngineObserver(&NewEngine);

  while(GameStatus != GAME_OVER){

    if(turn%2 == 0 && GameStatus == IN_COMBAT){
        IA1.GenerarateRandomCommand();
    }

    else if(GameStatus == IN_COMBAT){
        IA2.GenerarateRandomCommand();
    }
    turn++;
    GameStatus = NewEngine.GameLoop();
  }
  
  NewEngine.GameLoop();
 
 
  }
} */

BOOST_AUTO_TEST_SUITE_END()