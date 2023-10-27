#pragma once

class GameCore
{
private:
    GameCore();
    GameCore(GameCore&);
    GameCore(GameCore&&);
    static GameCore* instance;
    ~GameCore();
public:
    static GameCore* Get_Instance(); 
    static void Destroy_Instance();
};