#include "GameCore.h"
#include "EntityManager.h"

GameCore* GameCore::instance = nullptr;

GameCore::GameCore() 
{
    win = new sf::RenderWindow(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y), "Far Lands", sf::Style::Titlebar | sf::Style::Close);
    world = new World;
    win->setFramerateLimit(FRAME_LIMIT);
    
    view = new sf::View;
    view->setCenter({ WIN_SIZE.x/2, WIN_SIZE.y / 2 });
    view->setSize(WIN_SIZE);
    win->setView(*view);

    player = Player::GetInstance();
    entityManager = EntityManager::GetInstance();

    entityManager->Create(Type::CHICKEN, { 300, 300 });
    entityManager->Create(Type::EGG, { 1000, 1000 });
    world->SetObject(Type::WALL, {10, 10});

}

GameCore::~GameCore() 
{
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

        case sf::Event::MouseButtonPressed:
            if (ev.mouseButton.button == sf::Mouse::Right)
                entityManager->CreateProjectile(Type::ARROW, player->GetCenter(),
                    { view->getCenter().x - WIN_SIZE.x / 2 + ev.mouseButton.x,
                    view->getCenter().y - WIN_SIZE.y / 2 + ev.mouseButton.y });
                break;
            
        }
    
    } 

    Move();
}

void GameCore::Draw()
{
    win->clear();

    world->Draw(win);

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


    world->CheckCollision(shift, player->GetPosition(), player->GetTilePosition());

    player->Move(shift);
    view->setCenter(player->GetCenter());
    win->setView(*view);
    
}




