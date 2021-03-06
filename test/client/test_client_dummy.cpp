#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>
#include "engine.h"
#include "ai.h"
#include "render.h"

using namespace ::engine;
using namespace ::state;
using namespace ::ai;
using namespace ::render;

const float STRENGTH     = 2;
const float  NEUTRAL     = 1;
const float WEAK     = 0.5;

BOOST_AUTO_TEST_SUITE( test_engine_dummy1 )


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


BOOST_AUTO_TEST_CASE(TestRandomAI){
  {
  Engine NewEngine;
  RenderLayer lRender(&NewEngine);
  RandomAI IA1;
  RandomAI IA2;
  State* Game_State;
  CombatStatus GameStatus = INITIALISATION;
  int turn = 0;


  IA1.AddEngineObserver(&NewEngine);
  IA2.AddEngineObserver(&NewEngine);
  lRender.NotifyEndRendering();
  IA1.GenerarateRandomCommand();
  Game_State = NewEngine.GameLoop();
  

 
  }

}

BOOST_AUTO_TEST_CASE(TestHeuristicIA){
  {
  Engine NewEngine;
  RenderLayer lRender(&NewEngine);
  HeuristicAI IA1;
  HeuristicAI IA2;
  State* Game_State;
  CombatStatus GameStatus = INITIALISATION;
  int turn = 0;


  IA1.AddEngineObserver(&NewEngine);
  IA2.AddEngineObserver(&NewEngine);
  lRender.NotifyEndRendering();
  IA1.GenerateHeuristicCommand();
  Game_State = NewEngine.GameLoop();
  IA2.GenerateHeuristicCommand();

 
  }

}
BOOST_AUTO_TEST_CASE(TestDeepIA){
  {
  Engine NewEngine;
  RenderLayer lRender(&NewEngine);
  DeepAI IA1(5);
  DeepAI IA2(5);
  State* Game_State;
  CombatStatus GameStatus = INITIALISATION;
  int turn = 0;


  IA1.AddEngineObserver(&NewEngine);
  IA2.AddEngineObserver(&NewEngine);
  lRender.NotifyEndRendering();
  IA1.GenerateDeepCommand(5);
  Game_State = NewEngine.GameLoop();
  IA2.GenerateDeepCommand(5);

 
  }

}

/* ******* TEST UNITAIRE DES CLASSES DU RENDER ********** */

BOOST_AUTO_TEST_CASE(TestRenderLayer){
  {
    RenderLayer lRender;
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "ENSEAi");
    int lArena_Number = 1;
    lRender.LoadBackground(lArena_Number);
    lRender.UpdateCharacterOnScreen(1,1);
    lRender.UpdateCharacterOnScreen(5,2);
    lRender.UpdateCharacterOnScreen(10,3);
    lRender.UpdateCharacterOnScreen(7,4);


    lRender.UpdateCharacterOnScreen(3,5);

    lRender.AnimateCharacters();
    lRender.GoNextCombat(window);
    lRender.GoNextArena();

    lRender.UpdateCharacterOnScreen(1,1);
    lRender.LoadUI();

    lRender.draw(window,0,IN_COMBAT);          
  }
}

BOOST_AUTO_TEST_CASE(TestRenderObserver){
  {
    Engine GameEngine;
    RenderLayer lRender(&GameEngine);

  }
}

BOOST_AUTO_TEST_CASE(NewTestSurface){
  {
    render::BackgroundSurface lBackgroundSurface;
    render::CharacterSurface lCharacterSurface;
    sf::RenderWindow window;


    lBackgroundSurface.LoadShape("backgrounds/Arena1.png",0,0);
    lCharacterSurface.LoadCharacterSprite("sprites/Character1.png",0,0,0);
    lBackgroundSurface.LoadBackgroundSprite("backgrounds/Arena2.png");
    lCharacterSurface.SetCharacterAnimation(0);
    lCharacterSurface.UpdateCharacterAnimation(1);

    lBackgroundSurface.MoveBackgroundView(window,0);
    lCharacterSurface.MoveCharacterSprite();
    lCharacterSurface.ResetPosition(0);
    lBackgroundSurface.ResetViewPosition();

    lCharacterSurface.DrawSurface(window);
    lBackgroundSurface.DrawSurface(window);

  }
}

BOOST_AUTO_TEST_CASE(TestUI){
  {
    sf::RenderWindow window;
    UI lUI;
    lUI.CreateWindow(0,0,100,50);
    lUI.AddTextWindow("Test Unitaire",0,0);
    lUI.SetTextVersion("2.0");
    lUI.DEBUG_SetTextCombatState("En train de tester");
    lUI.DEBUG_SetTextAction1("Test1");
    lUI.DEBUG_SetTextAction2("Test2");
    lUI.DEBUG_SetTextAction3("Test3");
    lUI.DEBUG_SetTextAction4("Test4");
    lUI.DEBUG_SetLifePoints();
    lUI.MoveUI();

  }
}

/*************** TEST UNITAIRE DES CLASSES DE L'ENGINE ************/

BOOST_AUTO_TEST_CASE(TestCommand){
  {
    Command lCommand;

    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(ELEC,ELEC),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(ELEC,INFO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(ELEC,AUTO),WEAK);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(ELEC,SIGNAL),STRENGTH);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(ELEC,SCIENCES_HUMAINES),NEUTRAL);

    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(INFO,ELEC),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(INFO,INFO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(INFO,AUTO),STRENGTH);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(INFO,SIGNAL),WEAK);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(INFO,SCIENCES_HUMAINES),NEUTRAL);

    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(AUTO,ELEC),STRENGTH);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(AUTO,INFO),WEAK);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(AUTO,AUTO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(AUTO,SIGNAL),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(AUTO,SCIENCES_HUMAINES),NEUTRAL);

    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SIGNAL,ELEC),WEAK);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SIGNAL,INFO),STRENGTH);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SIGNAL,AUTO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SIGNAL,SIGNAL),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SIGNAL,SCIENCES_HUMAINES),NEUTRAL);

    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SCIENCES_HUMAINES,ELEC),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SCIENCES_HUMAINES,INFO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SCIENCES_HUMAINES,AUTO),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SCIENCES_HUMAINES,SIGNAL),NEUTRAL);
    BOOST_CHECK_EQUAL(lCommand.ComputeWeakAndStrength(SCIENCES_HUMAINES,SCIENCES_HUMAINES),STRENGTH);

    Character Character1(IS);
    Character Character2(EVE);
    JSON_tools JSON;
    JSON.JSON_Configure_Character(Character1);
    JSON.JSON_Configure_Character(Character2);

    int PVLost;
    PVLost=0;
    PVLost=lCommand.ComputeAction(Character1,Character2,engine::ATTACK_1);


    PVLost=abs(PVLost);


    int valeur_exacte=27;
    
    if (PVLost>50){
      
      BOOST_CHECK_EQUAL(PVLost,valeur_exacte*2);
    }
    if(PVLost<50){
      BOOST_CHECK_EQUAL(PVLost,valeur_exacte);
    }
    

   int i;
   int count=0;
   std::cout.setstate(std::ios_base::failbit);
   for(i=0;i<=10000;i++){
     
     if(lCommand.ComputeCriticalHit(1)==2){
       count++;
     }
   }
   std::cout.clear();
  BOOST_CHECK_SMALL(count,200);
  
    
    
    
    
  }
}

BOOST_AUTO_TEST_CASE(TestPlayer){
  Player lPlayer;
  sf::RenderWindow window; 

  lPlayer.SetStatusCommand(CommandID::ATTACK_1);

  BOOST_CHECK_EQUAL(lPlayer.GetStatusCommand(),CommandID::ATTACK_1);

}



BOOST_AUTO_TEST_SUITE_END()

