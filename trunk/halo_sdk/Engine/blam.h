#ifndef BLAM_H
#define BLAM_H

#include <windows.h>
typedef unsigned long BITFIELD;

// This is the entire blam file structure. It is loaded into memory ( static )
// when you join / start a game. I am mainly using it for a teamplay check
// but there are other uses. You can edit a gametype during game and such.

// Server .blam storage ( if you are host )
#define SERVER_BLAM_ADDRESS 0x0087A620;
// Local .blam storage ( if you are NOT host )
#define LOCAL_BLAM_ADDRESS 0x0087A6C0;

struct Blam
{
	wchar_t GameTypeName[24];	// Unicode
	long GameType;				// 1 CTF, 2 Slayer, 3 Oddball, 4 KOTH, 5 Race
	long TeamPlay;				// 0 Off, 1 On

	BITFIELD BallIndicator		:	1;
	BITFIELD FriendsOnRadar		:	1;
	BITFIELD StartEquipment		:	1;	// 0 Generic, 1 Custom
	BITFIELD Invisible			:	1;
	BITFIELD Shields			:	1;  
	BITFIELD InfiniteGrenades	:	1;
	BITFIELD FriendIndicators	:	1;
	BITFIELD PlayersOnRadar		:	1;

	long Indicator;            // 0 Motion tracker, 1 Navpoints, 2 None
	long OddManOut;            // 0 No, 1 Yes
	long RespawnTimeGrowth;	// 0 Off, 30 units per second eg: 150(0x96) = 30*5 secs
	long RespawnTime;
	long SuicidePenalty;
	long NumOfLives;			// 0 Unlimited, 1 1 life, 3 3 lives, 5 5 lives
	float fUnknown;               // 1.0f
	long ScoreLimit;           // Captures for CTF, laps for RACE, kills for Slayer, minutes for King, etc
	long WeaponSet;            // 0 Normal, 1 Pistols, 2 Rifles, 3 Plasma, 4 Sniper, 5 No sniping, 6 Rockets, 
									// 7 Shotguns, 8 Shortrange, 9 Human, 10 Convenant, 11 Classic, 12 Heavy

	/* Red Team Vehicle Settings */
	BITFIELD RedCustom			:	4;
	BITFIELD RedWarthog			:	3;
	BITFIELD RedGhost			:	3;
	BITFIELD RedScorpion		:	3;
	BITFIELD RedRocketWarthog	:	3;
	BITFIELD RedBanshee			:	3;
	BITFIELD RedTurret			:	3;
	BITFIELD RedZero			:	2;
	BITFIELD RedUnused			:	8;

	/* Blue Team Vehicle Settings */
	BITFIELD BlueCustom			:	4;
	BITFIELD BlueWarthog		:	3;
	BITFIELD BlueGhost			:	3;
	BITFIELD BlueScorpion		:	3;
	BITFIELD BlueRocketWarthog	:	3;
	BITFIELD BlueBanshee		:	3;
	BITFIELD BlueTurret			:	3;
	BITFIELD BlueZero			:	2;
	BITFIELD BlueUnused			:	8;

	long VehicleRespawnTime;

	long FriendlyFire;			// 0 Off, 1 On
	long TKPenalty;
	long AutoTeamBalance;		// 0 Off, 1 On
	long GameTimeLimit;
	long TypeFlags;			// Moving hill 0 Off; 1 On (KOTH)
									// Racetype 0 Normal; 1 Any order; 2 Rally (Race)
									// Random start 0 No; 1 Yes (Oddball)
	char TeamScoring;			// Team scoring 0 Minimum; 1 Maximum; 2 Sum (Race)
									// Ballspeed 0 Slow; 1 Normal; 2 Fast (Oddball)
	char AssaultTimeLimit;		// 0 Two flags
	WORD Unused1;
	long TraitWithBall;		// 0 None, 1 Invisible, 2 Extra damage, 3 Damage Resistent 
	long TraitWithoutBall;		// 0 None, 1 Invisible, 2 Extra damage, 3 Damage Resistent
	long BallType;             // 0 Normal, 1 Reverse Tag, 2 Juggernaut 
	long BallCountSpawn;
	BYTE One;                    // Always 1 ( 0 if custom )
	char GameTypeNum;            // # of the game in the game list ( 0000 - for a custom game type )
	WORD Unused2;
	DWORD Checksum;
};

///////////////////////////////
// Blam Methods

class CBlam
{
public:
	Blam* server_blam;
	Blam* local_blam;

	CBlam();
	~CBlam();

	void SetGameTypeName(Blam* blam, wchar_t *wName);	// Unicode, 24 characters max
	void SetGameType(Blam* blam, long dwType);		// 1 CTF, 2 Slayer, 3 Oddball, 4 KOTH, 5 Race
	void SetTeamPlay(Blam* blam, long dwNum);

	wchar_t *GetGameTypeName(Blam* blam);
	long GetGameType(Blam* blam);
	long GetTeamPlay(Blam* blam);

	// 0 Off, 1 On
	void SetBallIndicator(Blam* blam, bool bNum);
	void SetFriendsOnRadar(Blam* blam, bool bNum);
	void SetStartEquipment(Blam* blam, bool bNum);
	void SetInvisible(Blam* blam, bool bNum);
	void SetShields(Blam* blam, bool bNum);
	void SetInfiniteGrenades(Blam* blam, bool bNum);
	void SetFriendIndicators(Blam* blam, bool bNum);
	void SetPlayersOnRadar(Blam* blam, bool bNum);

	bool GetBallIndicator(Blam* blam);
	bool GetFriendsOnRadar(Blam* blam);
	bool GetStartEquipment(Blam* blam);
	bool GetInvisible(Blam* blam);
	bool GetShields(Blam* blam);
	bool GetInfiniteGrenades(Blam* blam);
	bool GetFriendIndicators(Blam* blam);
	bool GetPlayersOnRadar(Blam* blam);
};

#endif /* BLAM_H */