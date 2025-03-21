#pragma once
#include<raylib/raylib.h>
#include"config.h"

class Game
{
    public:
        Game();
        ~Game();
        void Run();

    private:
        void initResources();
        void initGameAttributes();

        void update();
        void draw() const;

        void drawScene() const;
        void composeFrame() const;

        ConfigManager m_ConfigManager;
        RenderTexture2D m_scene;
};