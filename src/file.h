#pragma once

#include <string>

struct discord_fields {
    std::string clientID;
    std::string state;
    std::string details;
    int64_t startTimestamp;
    int64_t endTimestamp;
    std::string largeImageKey;
    std::string largeImageText;
    std::string smallImageKey;
    std::string smallImageText;
    std::string partyID;
    int partySize;
    int partyMax;
};

void GetFile();

void WriteFile();

void ReadFile();