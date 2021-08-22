#include "discord.h"
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

void InitDiscord(std::string clientID)
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	handlers.ready = handleDiscordReady;
	handlers.errored = handleDiscordError;
	handlers.disconnected = handleDiscordDisconnected;
	handlers.joinGame = handleDiscordJoinGame;
	handlers.spectateGame = handleDiscordSpectateGame;
	handlers.joinRequest = handleDiscordJoinRequest;

	// Discord_Initialize(const char* applicationId, DiscordEventHandlers * handlers, int autoRegister, const char* optionalSteamId);
	Discord_Initialize(clientID.c_str(), &handlers, 1, NULL);
}

//void UpdatePresence()
//{
//    char buffer[256];
//    DiscordRichPresence discordPresence;
//    memset(&discordPresence, 0, sizeof(discordPresence));
//    discordPresence.state = "In a Group";
//    sprintf_s(buffer, "Ranked | Mode:");
//    discordPresence.details = buffer;
//    discordPresence.endTimestamp = time(0) + 5 * 60;
//    discordPresence.largeImageKey = "canary-large";
//    discordPresence.smallImageKey = "ptb-small";
//    discordPresence.partyId = "123";
//    discordPresence.partySize = 1;
//    discordPresence.partyMax = 6;
//    discordPresence.matchSecret = "4b2fdce12f639de8bfa7e3591b71a0d679d7c93f";
//    discordPresence.spectateSecret = "e7eb30d2ee025ed05c71ea495f770b76454ee4e0";
//    discordPresence.instance = 1;
//    Discord_UpdatePresence(&discordPresence);
//}

void UpdatePresence()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Playing Solo";
	discordPresence.details = "Competitive";
	discordPresence.startTimestamp = 2432423;
	discordPresence.endTimestamp = 1507665886;
	discordPresence.largeImageKey = "hayasaka";
	discordPresence.largeImageText = "Numbani";
	discordPresence.smallImageText = "Rogue - Level 100";
	discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
	discordPresence.partySize = 1;
	discordPresence.partyMax = 5;
	discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
	Discord_UpdatePresence(&discordPresence);
}