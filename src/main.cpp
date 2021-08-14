#include <iostream>

#include "main.h"
#include "../include/discord_rpc.h"

void handleDiscordReady(const DiscordUser* request) {

}

void handleDiscordError(int errorCode, const char* message) {

}

void handleDiscordDisconnected(int errorCode, const char* message) {

}

void handleDiscordJoinGame(const char* joinSecret) {

}

void handleDiscordSpectateGame(const char* spectateSecret) {

}

void handleDiscordJoinRequest(const DiscordUser* request) {

}

void InitDiscord(const char* clientID)
{
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = handleDiscordReady;
    handlers.errored = handleDiscordError;
    handlers.disconnected = handleDiscordDisconnected;
    handlers.joinGame = handleDiscordJoinGame;
    handlers.spectateGame = handleDiscordSpectateGame;
    handlers.joinRequest = handleDiscordJoinRequest;

    // Discord_Initialize(const char* applicationId, DiscordEventHandlers* handlers, int autoRegister, const char* optionalSteamId)
    Discord_Initialize(clientID, &handlers, 0, "1233");
}

void UpdatePresence()
{
    char buffer[256];
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "In a Group";
    sprintf_s(buffer, "Ranked | Mode:");
    discordPresence.details = buffer;
    discordPresence.endTimestamp = time(0) + 5 * 60;
    discordPresence.largeImageKey = "canary-large";
    discordPresence.smallImageKey = "ptb-small";
    discordPresence.partyId = "123";
    discordPresence.partySize = 1;
    discordPresence.partyMax = 6;
    discordPresence.matchSecret = "4b2fdce12f639de8bfa7e3591b71a0d679d7c93f";
    discordPresence.spectateSecret = "e7eb30d2ee025ed05c71ea495f770b76454ee4e0";
    discordPresence.instance = 1;
    Discord_UpdatePresence(&discordPresence);
}

int main() {

    const char* str = "875580955472068619";

    InitDiscord(str);

    return 1;
}