#pragma once
#include<cstdint>
#include<filesystem>

#pragma pack(push, 1)

struct Config
{
    uint16_t windowWidth;
    uint16_t windowHeight;
    uint8_t fps;
};

#pragma pack(pop)

class ConfigManager
{
    public:
        ConfigManager();

        void LoadConfig(const std::filesystem::path& path);
        void SaveConfig(const std::filesystem::path& path);
        const Config& GetConfig() const;

    private:
        Config m_Config;
};