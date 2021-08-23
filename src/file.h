#pragma once

#ifndef FILE_H
#define FILE_H

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

struct discord_fields GetFile();

void WriteFile();

void ReadFile();

#endif