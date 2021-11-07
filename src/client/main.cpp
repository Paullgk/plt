#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <render/RenderLayer.h>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>



using namespace std;
using namespace state;
using namespace sf;
using namespace render;

int main(int argc,char* argv[])
{
    sf::Clock clock;
    RenderLayer lRender;

    if(argc > 1){
        if(strcmp(argv[1], "hello") == 0){
            cout << "Bonjour le monde" << endl;
        }


        else if(strcmp(argv[1], "render") == 0){
            RenderWindow window(VideoMode(800, 600, 32), "ENSEAi");
            lRender.LoadBackground();
            lRender.LoadCharacters(1, 100, 200);

            while (window.isOpen())
            {

                Event event;

                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed){
                        window.close();
                    }
                    

                }


                window.clear();

                lRender.draw(window);
                    
                if(clock.getElapsedTime().asSeconds() > 0.2f){
                    lRender.AnimateCharacters();
                    clock.restart();
                }

                    
                
                
                    //lDrawSurface.Draw(window);
                window.display();  

                    
            }       


        }
            

    }

    

    return 0;
}
