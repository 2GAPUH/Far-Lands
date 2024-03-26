#include "GameCore.h"
#include "EntityManager.h"


GameCore* GameCore::instance = nullptr;
bool GameCore::playerAlive = ALIVE;

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

    entityManager->Create(EnemyType::CHICKEN, { 300, 300 });
    entityManager->Create(EnemyType::CHICKEN, { 400, 300 });
    entityManager->Create(EnemyType::CHICKEN, { 500, 300 });
}

GameCore::~GameCore() 
{
    world = nullptr;
    delete win;
    win = nullptr;
}

enum class GameState { NOTHING, INVENTORY };

void GameCore::Update()
{
    static GameState gameState = GameState::NOTHING;
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
            if (ev.mouseButton.button == sf::Mouse::Left)
            {
                if(gameState == GameState::NOTHING)
                    player->Use(sf::Vector2f{ (float)ev.mouseButton.x, (float)ev.mouseButton.y });
            }
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
                if (gameState == GameState::INVENTORY)
                    gameState = GameState::NOTHING;
                else if (gameState == GameState::NOTHING)
                    gameState = GameState::INVENTORY;

                player->OpenInventory();
                break;

            case sf::Keyboard::Tab:
                player->EditCurLine();
                break;

            case sf::Keyboard::C:
                player->ChangeHero();
                break;
            }
        }
        break;

        }
    
    } 

    Move();

    player->Update(win);
    world->Update();
    entityManager->Update();
}

void GameCore::Draw()
{
    win->clear();

    world->Draw(win, player->GetPosition());

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
    while (win->isOpen() && playerAlive)
    {
        Update();

        Draw();
    }
}

sf::RenderWindow* GameCore::GetWin()
{
    return win;
}

void GameCore::EndGame()
{
    playerAlive = DEAD;

    // Создаем текстуру и спрайт для гиф-анимации
    std::vector<sf::Texture> frames;
    for (int i = 1; i <= 97; ++i) {
        sf::Texture texture;
        std::string filename = "Death\\death" + std::to_string(i) + ".png"; // Замените на реальные имена файлов
        if (!texture.loadFromFile(filename)) {
            return; // Ошибка при загрузке кадра
        }
        frames.push_back(texture);
    }

    // Установка начального кадра
    int current_frame = 1;
    sf::Sprite sprite;
    sprite.setTexture(frames[current_frame]);
    sprite.setScale(win->getSize().x / sprite.getLocalBounds().width,
        win->getSize().y / sprite.getLocalBounds().height);

    sf::Clock clock;
    float frame_duration = 0.1f; // Длительность каждого кадра в секундах

    ResourceManager::GetInstance()->StopMusic(MusicList::SPRING_DAY);

    ResourceManager::GetInstance()->PlaySound(SoundList::DEATH);

    while (win->isOpen() && current_frame <= 90) {
        sf::Event event;
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter)
                    win->close();
            }
        }

        // Переключение кадров с задержкой
        if (clock.getElapsedTime().asSeconds() >= frame_duration) {
            clock.restart();
            current_frame = (current_frame + 1) % frames.size();
            sprite.setTexture(frames[current_frame]);
        }

        win->clear();
        win->draw(sprite);
        win->display();
    }
}

void GameCore::Move()
{
    sf::Vector2f shift = { 0, 0 };
    float speed = player->GetSpeed();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
        speed /= ROOT_CONST;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        shift.x += -speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        shift.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        shift.y += -speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        shift.y += speed;

    if (CollisionInfo::OUT_WORLD == world->CheckCollision(shift, player->GetPosition()))
        player->Respawn();
    player->Move(shift);
    player->CheckViewDerection(shift);
    view->setCenter(player->GetCenter());
    win->setView(*view); 

    for (EntityManager::Iterator it = entityManager->begin(); it != entityManager->end(); ++it)
    {
        CollisionInfo tmp = world->CheckCollision((*it)->GetMovementVector(), (*it)->GetGlobalBounds());
        if (tmp == CollisionInfo::OUT_WORLD)
            entityManager->AddInDestroyList((*it)->GetID());
        else if (tmp == CollisionInfo::TRUE)
            (*it)->WorldCollision();
    }
}




