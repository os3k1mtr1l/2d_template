#include"header/game.h"
#include<rlImGui.h>

void Game::initResources()
{
    m_scene = LoadRenderTexture(m_ConfigManager.GetConfig().windowWidth, m_ConfigManager.GetConfig().windowHeight);
}

void Game::initGameAttributes()
{
    
}

Game::Game()
{
    InitWindow(0, 0, "2D Template");
    m_ConfigManager.LoadConfig("config.cfg");

    int monitor = GetCurrentMonitor();
    SetWindowMinSize(800, 600);
    SetWindowMaxSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    SetWindowSize(m_ConfigManager.GetConfig().windowWidth, m_ConfigManager.GetConfig().windowHeight);
    SetWindowPosition(GetMonitorWidth(monitor) / 2 - m_ConfigManager.GetConfig().windowWidth / 2, GetMonitorHeight(monitor) / 2 - m_ConfigManager.GetConfig().windowHeight / 2);

    SetTargetFPS(m_ConfigManager.GetConfig().fps);

    rlImGuiSetup(true);
    initResources();
    initGameAttributes();
}

Game::~Game()
{
    rlImGuiShutdown();
    UnloadRenderTexture(m_scene);
    CloseWindow();
}

void Game::Run()
{
    while(!WindowShouldClose())
    {
        update();
        draw();
    }
}