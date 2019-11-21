#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

//custom file headers


#include "../headers/overworld_code_header.h"

using namespace std;

void cursor_move()
{

    if(time_since_last_move.getElapsedTime().asMilliseconds() >= 100)
    {

        player.check_x = player.x;
        player.check_y = player.y;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.y = player.y - 1;
            cout << "W" << endl;

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.y = player.y + 1;
            cout << "S" << endl;

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.x = player.x - 1;
            cout << "A" << endl;

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.x = player.x + 1;
            cout << "D" << endl;

        }
    time_since_last_move.restart();
    }

}

int main()
{

camera.zoom(0.05);
image_load();
setup();
stat_startup();
item_setup();

//colour_setup();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        collision_detection();
        cursor_move();
        collision_detection();

        player.location_update();

        //cout << " x=: "<< player.x << " Y=: " << player.y << endl;
        draw();


    }

    return 0;
}
