#include "GameCore.h"

GameCore* GameCore::instance = nullptr;

GameCore::GameCore() 
{
    win = new sf::RenderWindow(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y), "Far Lands", sf::Style::Titlebar | sf::Style::Close);
    world = new World;
    player = new Player;
    win->setFramerateLimit(FRAME_LIMIT);
    
}

GameCore::~GameCore() 
{
    delete player;
    player = nullptr;
    delete world;
    world = nullptr;
    delete win;
    win = nullptr;
}

void GameCore::Update()
{
    sf::Event ev;
    sf::Vector2f;

    while (win->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            win->close();
            break;


        }
    }

    Move();
}

void GameCore::Draw()
{
    win->clear();

    world->Draw(win);

    player->Draw(win);

    win->display();
}

GameCore* GameCore::GetInstance()
{
    if (instance == nullptr)
        instance = new GameCore();
    return instance;
}

void GameCore::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void GameCore::Start()
{
    while (win->isOpen())
    {
        Update();

        Draw();
    }
}

sf::RenderWindow* GameCore::GetWin()
{
    return win;
}

void GameCore::Move()
{
    sf::Vector2f shift = {0, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shift.x += player->GetSpeed();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shift.x += -player->GetSpeed();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shift.y += player->GetSpeed();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shift.y += -player->GetSpeed();
    }

    world->Move(shift);
}


