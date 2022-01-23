#include <string>

#include "main.h"
#include "discord.h"
#include "file.h"
#include "../include/discord_rpc.h"

extern discord_fields values;

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

void UpdatePresence(struct discord_fields values)
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = values.state.c_str();
	discordPresence.details = values.details.c_str();
	discordPresence.startTimestamp = values.startTimestamp;
	discordPresence.endTimestamp = values.endTimestamp;
	discordPresence.largeImageKey = values.largeImageKey.c_str();
	discordPresence.largeImageText = values.largeImageText.c_str();
	discordPresence.smallImageKey = values.smallImageKey.c_str();
	discordPresence.smallImageText = values.smallImageText.c_str();
	discordPresence.partySize = values.partySize;
	discordPresence.partyMax = values.partyMax;
	Discord_UpdatePresence(&discordPresence);
}