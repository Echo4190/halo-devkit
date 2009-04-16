#ifndef PLAYERS_H
#define PLAYERS_H

#include <windows.h>
#include "types.h"

#define PLAYER_ADDRESS			0x402AAF94
#define LOCAL_PLAYER_ADDRESS	0x402AD404

struct APlayer
{
	short	PlayerID;
	short	IsLocal;			// 0=Local(no bits set), -1=Other Client(All bits set)
	wchar_t Name[12];			// Unicode
	ident	UnknownIdent;
	long	Team;				// 0=Red, 1=Blue
	ident	SwapObject;
	short	SwapType;
	short	SwapSeat;			// Warthog-Driver=0, Passenger=1, Gunner=2, Weapon=-1
	long	RespawnTimer;		// Counts down when dead, Alive=0
	long	Unknown;
	ident	CurrentBiped;
	ident	PreviousBiped;
	long	ClusterIndex;
	ident	UnknownIdent1;
	long	LastBulletShotTime;	// since game start(0)
	wchar_t Name1[12];
	ident	UnknownIdent2;
	pinfo	PlayerInfo;
	long	Unknown1;
	float	VelocityMultiplier;
	ident	UnknownIdent3[4];
	long	Unknown2;
	long	LastDeathTime;		// since game start(0)
	char	Unknown3[18];
	short	KillsCount;
	char	Unknown4[6];
	short	AssistsCount;
	char	Unknown5[8];
	short	BetrayedCount;
	short	DeathCount;
	short	SuicideCount;
	char	Unknown6[18];
	short	FlagStealCount;
	short	FlagReturnCount;
	short	FlagCaptureCount;
	char	Unknown7[6];
	ident	UnknownIdent4;
	char	Unknown8[8];
	short	Ping;
	char	Unknown9[14];
	ident	UnknownIdent5;
	long	Unknown10;
	long	SomeTime;
	vect3	World;
	ident	UnknownIdent6;
	char	Unknown11[20];
	char	Melee		:	1;
	char	Swap		:	1;
	char	UnknownBit	:   1;
	char	Flashlight	:	1;
	char	UnknownBit1	:	4;
	char	UnknownBit2	:	5;
	char	Reload		:	1;
	char	UnknownBit3	:	2;
	char	Unknown12[26];
	vect2	Rotation;
	float	VerticalVelocityMultiplier;
	float	HorizontalVelocityMultiplier;
	float	RateOfFireVelocityMultiplier;
	char	Unknown13[180];
};

struct ALocalPlayer
{
	ident	UnknownIdent;
	ident	PlayerIdent;
	ident	UnknownIdent1;
	char	Unknown[156];
	ident	Biped;
	char	Unknown1[8];
	vect2	Rotation;
	char	Unknown2[36];
	float	PitchMinimum;
	float	PitchMaximum;
};

struct APlayerData
{
	DataHeader	PlayerHeader;
	APlayer		Player[16];
};

class CPlayers
{
private:
	APlayerData*	PlayerData;
	ALocalPlayer*	LocalPlayer;

public:
	CPlayers();
	~CPlayers();

	wchar_t* GetPlayerName(unsigned char player_index);
	long GetPlayerTeam(unsigned char player_index);
	bool IsPlayerLocal(unsigned char player_index);
	bool IsPlayerSpawned(unsigned char player_index);
	bool IsPlayerValid(unsigned char player_index);
	ident GetPlayerObjectIdent(unsigned char player_index);
};

#endif /* PLAYERS_H */