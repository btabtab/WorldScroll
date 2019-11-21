#ifndef OVERWORLD_CODE_HEADER_H_INCLUDED
#define OVERWORLD_CODE_HEADER_H_INCLUDED



using namespace std;

sf::RenderWindow window(sf::VideoMode(600, 600), "spoRePG");

sf::Image background_image;
sf::Texture background_texture;
sf::Sprite background;
sf::View camera;
sf::View minimap;
sf::Clock time_since_last_move;

sf::Color current_pixel;
sf::Color ocean = sf::Color(0, 160, 192);
sf::Color rock = sf::Color(192, 192, 192);
sf::Color rock_dark = sf::Color(128, 128, 128);
sf::Color wood_wall = sf::Color(191, 116, 24);
sf::Color wood_wall_dark = sf::Color(104, 63, 13);
sf::Color wood_wall_darkest = sf::Color(40, 24, 5);

sf::Color zone_change = sf::Color(254, 254, 254);
sf::Color basement_2 = sf::Color(253, 253, 253);
sf::Color return_to_surface = sf::Color(254, 0, 0);

sf::Color Dark_forest = sf::Color(96, 128, 0);
sf::Color Dark_ocean = sf::Color(64, 64, 192);


class entity
{
public:
    sf::Sprite body;
    sf::Texture texture;
    float x; float check_x;
    float y; float check_y;

    float health; float maxhealth;
    float oxygen; float oxygen_max;
    float attack;
    float exp;
    float exp_until_level_up;
    int level;

    float damage_buff;

    bool canswim;

    void location_update()
    {
        //cout <<"--" << time_since_last_move.getElapsedTime().asMilliseconds() << "--" << endl;

        camera.setCenter(x, y);
        body.setPosition(x, y);


    }

    void stat_output()
    {

        cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "hp: " << health << " / " << maxhealth << endl;
        cout << "oxygen: " << oxygen << "/" << oxygen_max << endl;
        cout << "level: " << level << endl;
        cout << "exp: " << exp << endl;
        cout << "exp until next level: " << exp_until_level_up << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
    }

    bool is_hostile;
    bool is_player;

};

entity player;


class item
{
public:
    sf::Sprite body; char body_filename[100];
    sf::Texture texture; char texture_filename[100];

    sf::Color shape;

    sf::Sprite art; char art_filename[100];
    sf::Texture artwork; char artwork_filename[100];

    float x;
    float y;

    bool obtained;
};

item swimsuit;
item sword;

item_setup()
{
    swimsuit.shape = sf::Color(250, 0, 100);
    return 0;
}

void item_check()
{
    player.canswim = false;
    if(swimsuit.obtained == true)
        player.canswim = true;



}

void area_change()
{

}



void image_load()
{
    if (!background_image.loadFromFile("resources/background.bmp"))
    {
        cout << "oh" << endl;
    }


    if (!player.texture.loadFromFile("resources/player_sprite.bmp"))
    {
        cout << "oh" << endl;
    }
}

void setup()
{
    background_texture.update(background_image);
    background_texture.loadFromImage(background_image);
    background.setTexture(background_texture);
    player.body.setTexture(player.texture);

    player.x = 120;
    player.y = 110;
}

void draw()
{

    window.clear();

    window.draw(background);
    window.draw(player.body);
    window.display();

    window.setView(camera);


}

int encounter_chance;

void collision_detection()
{
    current_pixel = background_image.getPixel(player.x, player.y);
    if(current_pixel == ocean)
    {
        if(player.canswim == true)
        {
            player.oxygen--;
            if(player.oxygen == 0)
                player.health--;
        }
        else
        {
            player.x = player.check_x;
            player.y = player.check_y;
        }

    }
    else
    player.oxygen = player.oxygen_max;

    if(current_pixel == rock)
    {
        player.x = player.check_x;
        player.y = player.check_y;
    }

    if(current_pixel == rock_dark)
    {
        player.x = player.check_x;
        player.y = player.check_y;
    }

    if(current_pixel == wood_wall)
    {
        player.x = player.check_x;
        player.y = player.check_y;
    }

    if(current_pixel == wood_wall_dark)
    {
        player.x = player.check_x;
        player.y = player.check_y;
    }

    if(current_pixel == wood_wall_darkest)
    {
        player.x = player.check_x;
        player.y = player.check_y;
    }

    if(current_pixel == zone_change)
    {
        if (!background_image.loadFromFile("dungeon.bmp"))
        {
            cout << "oh" << endl;
        }
        background_texture.loadFromImage(background_image);
        background.setTexture(background_texture);

    }

    if(current_pixel == return_to_surface)
    {
        if (!background_image.loadFromFile("background.bmp"))
        {
            cout << "oh" << endl;
        }
        background_texture.loadFromImage(background_image);
        background.setTexture(background_texture);

    }

    if(current_pixel == swimsuit.shape)
    {
        player.canswim = true;
    }

}

void stat_startup()
{
    player.health = 10;
    player.maxhealth = 10;

    player.level = 1;
    player.attack = 1;
}



#endif // OVERWORLD_CODE_HEADER_H_INCLUDED
