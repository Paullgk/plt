
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>
#include "client/Engine.h"

using namespace ::client;
using namespace ::state;

const float STRENGTH     = 2;
const float  NEUTRAL     = 1;
const float WEAK     = 0.5;

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

BOOST_AUTO_TEST_CASE(TestEngine){
  {
    Engine UUT_Engine;
    state::Character UUT_Character_IS("IS", state::INFO, state::ALIVE);
    state::Character UUT_Character_SIA("SIA", state::SIGNAL, state::ALIVE);

    UUT_Character_IS.SetCharacterStats(LIFE_POINTS, 80);
    UUT_Character_IS.SetCharacterStats(ATTACK, 140);
    UUT_Character_IS.SetCharacterStats(POWER, 140);
    UUT_Character_IS.SetCharacterStats(DEFENSE, 80);
    UUT_Character_IS.SetCharacterStats(LUCK, 5);
    UUT_Character_IS.SetCharacterAction(state::ATTACK_1, 80);

    UUT_Character_SIA.SetCharacterStats(LIFE_POINTS, 110);
    UUT_Character_SIA.SetCharacterStats(ATTACK, 80);
    UUT_Character_SIA.SetCharacterStats(POWER, 150);
    UUT_Character_SIA.SetCharacterStats(DEFENSE, 60);
    UUT_Character_SIA.SetCharacterStats(LUCK, 3);

    BOOST_CHECK_EQUAL(UUT_Engine.DEBUG_GetGameStatus(), state::IN_COMBAT);

    //UUT_Engine.mCommand.ComputePVLost(*(&UUT_Character_IS), *(&UUT_Character_SIA), CommandID::ATTACK_1);
    BOOST_CHECK_EQUAL(UUT_Engine.mCommand.ComputeWeakAndStrength(UUT_Character_SIA.GetMajor(), UUT_Character_IS.GetMajor()), WEAK);
    

    for(int i = 0; i<100;i++){
      UUT_Engine.mCommand.ComputeCriticalHit(UUT_Character_IS.GetCharacterStats(LUCK));
    }
      

  }




}



