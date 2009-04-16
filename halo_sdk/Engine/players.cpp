#include "players.h"

CPlayers::CPlayers()
{
	PlayerData	= (APlayerData*)	PLAYER_ADDRESS;
	LocalPlayer	= (ALocalPlayer*)	LOCAL_PLAYER_ADDRESS;
}

CPlayers::~CPlayers()
{
}

wchar_t* CPlayers::GetPlayerName(unsigned char player_index)
{
		return PlayerData->Player[player_index].Name;
}

long CPlayers::GetPlayerTeam(unsigned char player_index)
{
	return PlayerData->Player[player_index].Team;
}

bool CPlayers::IsPlayerLocal(unsigned char player_index)
{
	short temp = PlayerData->Player[player_index].IsLocal;

	if(!temp)
		return true;
	else
		return false;
}

bool CPlayers::IsPlayerSpawned(unsigned char player_index)
{
	short id = PlayerData->Player[player_index].CurrentBiped.ID;

	if(id && id != INVALID)
		return true; 
	else
		return false;
}

bool CPlayers::IsPlayerValid(unsigned char player_index)
{
	short id = PlayerData->Player[player_index].PlayerID;

	if(id && id != INVALID)
		return true;
	else
		return false;
}

ident CPlayers::GetPlayerObjectIdent(unsigned char player_index)
{
	return PlayerData->Player[player_index].CurrentBiped;
}