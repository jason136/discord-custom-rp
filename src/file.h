#pragma once

struct discord_fields {
    const char* clientID;
    const char* state;
    const char* details;
    int64_t startTimestamp;
    int64_t endTimestamp;
    const char* largeImageKey;
    const char* largeImageText;
    const char* smallImageKey;
    const char* smallImageText;
    const char* partyID;
    int partySize;
    int partyMax;
};

void GetFile();

void RefreshFile();

