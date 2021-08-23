#include <string>

#include "discord.h"
#include "file.h"
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

//void UpdatePresence(struct discord_fields data)
//{
//	DiscordRichPresence discordPresence;
//	memset(&discordPresence, 0, sizeof(discordPresence));
//	discordPresence.state = data.state;
//	discordPresence.details = data.details;
//	discordPresence.startTimestamp = data.startTimestamp;
//	discordPresence.endTimestamp = data.endTimestamp;
//	discordPresence.largeImageKey = data.largeImageKey;
//	discordPresence.largeImageText = data.largeImageText;
//	discordPresence.smallImageKey = data.smallImageKey;
//	discordPresence.smallImageText = data.smallImageText;
//	discordPresence.partyId = data.partyID;
//	discordPresence.partySize = data.partySize;
//	discordPresence.partyMax = data.partyMax;
//	discordPresence.joinSecret = "";
//	Discord_UpdatePresence(&discordPresence);
//}

//.c_str()

void UpdatePresence(struct discord_fields data)
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "adasd";
	discordPresence.details = "asdasd";
	discordPresence.startTimestamp = 234234;
	discordPresence.endTimestamp = 2342342;
	discordPresence.largeImageKey = "hayasaka";
	discordPresence.largeImageText = "asdasd";
	discordPresence.smallImageKey = "hayasaka";
	discordPresence.smallImageText = "asdasd";
	discordPresence.partyId = "asdasd";
	discordPresence.partySize = 2;
	discordPresence.partyMax = 7;
	discordPresence.joinSecret = "";
	Discord_UpdatePresence(&discordPresence);
}