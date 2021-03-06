#pragma once

#include <thread>

#include "common_types.h"
#include "Timer.h"

class GameManager;
class MenuManager;

class Game
{
public:
    enum class EGameState
    {
        BeforePlay,
        Play,
        GameOver,
        Menu,
        BackToMenu,
        Demo,
        Exit,
    };

public:
    Game();
    ~Game();
    //
    void Start();
    void Stop();
    //
    void Init();
    //
    void ProcessInput();
    void Update();
    void Render();
    void Reset();
    //
    EGameState GetCurrentState() const { return mState; }
    bool IsRunning() const { return mRunning; }

private:
    void setStateByMenuChoice(EMenuState state);

private:
    EGameState mState;
    //
    MenuManager* mMenuManager;
    GameManager* mGameManager;
    //
    bool mRunning;
    std::thread mUpdateThread;
    std::thread mRenderThread;
    //
    Timer mTimer;
};

