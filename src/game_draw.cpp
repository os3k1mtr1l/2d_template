#include"header/game.h"

void Game::drawScene() const
{
    BeginTextureMode(m_scene);
    {
        ClearBackground(BLACK);

        int fontSize = 40;
        int width = MeasureText("2D Template", fontSize);

        static int framesCounter = 0;
        float dt = GetFrameTime() * 10;
        if(framesCounter * dt > 360) framesCounter = 0;

        Color color = ColorFromHSV(static_cast<float>(framesCounter) * dt, 1.0f, 1.0f);

        DrawText(
            "2D Template",
            m_ConfigManager.GetConfig().windowWidth / 2 - width / 2,
            m_ConfigManager.GetConfig().windowHeight / 2 - fontSize / 2,
            fontSize,
            color);
        framesCounter++;

        DrawFPS(10, 10);
    }
    EndTextureMode();
}

void Game::composeFrame() const
{
    BeginDrawing();
    {
        ClearBackground(BLACK);

        DrawTextureRec(
            m_scene.texture,
            {0, 0, static_cast<float>(m_scene.texture.width), static_cast<float>(-m_scene.texture.height)},
            {0, 0},
            WHITE);
    }
    EndDrawing();
}

void Game::draw() const
{
    drawScene();
    
    composeFrame();
}