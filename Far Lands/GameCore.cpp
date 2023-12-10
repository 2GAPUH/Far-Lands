#include "GameCore.h"

GameCore* GameCore::instance = nullptr;

GameCore::GameCore() 
{
    win = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Far Lands", sf::Style::Titlebar | sf::Style::Close);
    world = new World;
    player = new Player;
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
    while (win->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            win->close();
            break;


        }
    }
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
