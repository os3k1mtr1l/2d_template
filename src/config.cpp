#include"header/config.h"
#include<iostream>
#include<fstream>
#include<raylib/raylib.h>
#include<memory.h>

ConfigManager::ConfigManager()
{
    m_Config.windowWidth = 800;
    m_Config.windowHeight = 600;
    m_Config.fps = 60;
}

const Config& ConfigManager::GetConfig() const
{
    return m_Config;
}

void ConfigManager::SaveConfig(const std::filesystem::path& path)
{
    std::ofstream file(path);

    if(!file.is_open())
    {
        TraceLog(LOG_WARNING, "CONFIG: Failed to open file: %s. Save discarded", reinterpret_cast<const char*>(path.c_str()));
        return;
    }

    file.write(reinterpret_cast<const char*>(&m_Config), sizeof(Config));
    
    TraceLog(LOG_INFO, "CONFIG: Saved");
    file.close();
}

void ConfigManager::LoadConfig(const std::filesystem::path& path)
{
    std::ifstream file(path);
    TraceLog(LOG_INFO, "CONFIG: Loading config from: %s", reinterpret_cast<const char*>(path.c_str()));

    if(!file.is_open())
    {
        TraceLog(LOG_WARNING, "CONFIG: Failed to open file: %s. Loading default settings", reinterpret_cast<const char*>(path.c_str()));
        SaveConfig(path);
    }
    else
        file.read(reinterpret_cast<char*>(&m_Config), sizeof(Config));

    TraceLog(LOG_INFO, "CONFIG: Loaded config: %dx%d %d fps", m_Config.windowWidth, m_Config.windowHeight, m_Config.fps);
    file.close();
}