#include "GameCore.h"
#include "EntityManager.h"

GameCore* GameCore::instance = nullptr;

GameCore::GameCore() 
{
    win = new sf::RenderWindow(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y), "Far Lands", sf::Style::Titlebar | sf::Style::Close);
    world = World::GetInstance();
    win->setFramerateLimit(FRAME_LIMIT);
    
    view = new sf::View;
    view->setCenter({ WIN_SIZE.x/2, WIN_SIZE.y / 2 });
    view->setSize(WIN_SIZE);
    win->setView(*view);

    player = Player::GetInstance();
    entityManager = EntityManager::GetInstance();
}

GameCore::~GameCore() 
{
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
        {
            win->close();
        }
        break;

        case sf::Event::MouseButtonPressed:
        {
            if (ev.mouseButton.button == sf::Mouse::Right)
                player->Use(sf::Vector2f{(float) ev.mouseButton.x, (float)ev.mouseButton.y });
        }
        break;
         
        case sf::Event::MouseWheelScrolled:
        {
            player->EditCurElem(ev.mouseWheelScroll.delta * -1);
        }
        break;

        case sf::Event::KeyPressed:
        {
            switch (ev.key.code)
            {
            case sf::Keyboard::E:
                player->OpenInventory();
                break;

            case sf::Keyboard::Tab:
                player->EditCurLine();
            }
        }
        break;

        }
    
    } 

    Move();
}

void GameCore::Draw()
{
    win->clear();

    world->Draw(win, player->GetTilePosition());

    entityManager->Draw(win);

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

        entityManager->Update();

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
    float speed = player->GetSpeed();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        shift.x += -speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        shift.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        shift.y += -speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        shift.y += speed;


    world->CheckCollision(shift, player->GetPosition());

    player->Move(shift);
    view->setCenter(player->GetCenter());
    win->setView(*view);
}




