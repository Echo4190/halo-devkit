#ifndef OBJECTS_H
#define OBJECTS_H

#include <windows.h>
#include "types.h"

#define OBJECT_ADDRESS 0x400506B4

struct AObjectHeader;
struct AObjectData;
struct AObject;
struct ABiped;
struct AWeapon;
struct ASniperRifle;
struct APistol;
struct AAssaultRifle;
struct AShotgun;
struct ARocketLauncher;
struct AFlameThrower;
struct APlasmaRifle;
struct APlasmaPistol;
struct ANeedler;
struct APlasmaCannon;

struct AObjectHeader
{
	short			ID;
	unsigned char	Flags;
	unsigned char	Type;
	short			CluserIndex;	// portal rendering (sector)
	short			Size;			// Structure size
	union
	{
		void*				Address;
		AObject*			Object;
		ABiped*				Biped;
		AWeapon*			Weapon;
		ASniperRifle*		SniperRifle;
		APistol*			Pistol;
		AAssaultRifle*		AssaultRifle;
		AShotgun*			Shotgun;
		ARocketLauncher*	RocketLauncher;
		AFlameThrower*		FlameThrower;
		APlasmaRifle*		PlasmaRifle;
		APlasmaPistol*		PlasmaPistol;
		ANeedler*			Needler;
		APlasmaCannon*		PlasmaCannon;
	};
};

struct AObjectData
{
	DataHeader		ObjectsHeader;
	AObjectHeader	ObjectHeader[2048];
};

struct AObject
{
	ident	ModelTag;		// 0x0000
	long	Zero;			// 0x0004
	char	Flags[4];		// 0x0008
	long	Timer;			// 0x000C
	char	Flags2[4];		// 0x0010
	long	Timer2;			// 0x0014
	long	Zero2[17];		// 0x0018
	vect3	World;			// 0x005C
	vect3	Velocity;		// 0x0068
	vect3	LowerRot;		// 0x0074
	vect3	Scale;			// 0x0080
	vect3	UnknownVect1;	// 0x008C
	long	LocationID;		// 0x0098
	long	Unknown1;		// 0x009C
	vect3	UnknownVect2;	// 0x00A0
	float	Unknown2[2];	// 0x00AC		
	long	Unknown3[3];	// 0x00B4
	ident	Player;			// 0x00C0
	long	Unknown4[2];	// 0x00C4
	ident	AntrMeta;		// 0x00CC
	long	Unknown5[4];	// 0x00D0
	float	Health;			// 0x00E0
	float	Shield1;		// 0x00E4
	long	Unknown6[11];	// 0x00E8
	ident	VehicleWeapon;	// 0x0114
	ident	Weapon;			// 0x0118
	ident	Vehicle;		// 0x011C
	short	SeatType;		// 0x0120
	short	Unknown7;		// 0x0122
	long	Unknown8;		// 0x0124
	float	Shield2;		// 0x0128
	float	Flashlight1;	// 0x012C
	float	Unknown9;		// 0x0130
	float	Flashlight2;	// 0x0134
	long	Unknown10[5];	// 0x0138
	ident	UnknownIdent1;	// 0x014C
	ident	UnknownIdent2;	// 0x0150
	long	Zero3[6];		// 0x0154
	ident	UnknownIdent3;	// 0x016C
	ident	UnknownIdent4;	// 0x0170
	D3DXMATRIX UnknownMatrix;	// 0x0174
	D3DXMATRIX UnknownMatrix1;	// 0x01B4
};

struct ABiped
{
	AObject	Object;				// 0x0000
	long	Unknown[4];			// 0x01F4
	long	IsInvisible;		// 0x0204	normal = 0x41 invis = 0x51 (bitfield?)
	char	IsCrouching :	1;	// 0x0208
	char	IsJumping	:	1;
	char	UnknownBit	:	2;
	char	Flashligh	:	1;
	char	UnknownBit2	:	3;
	char	Unknown1[3];		// 0x0209
	char	Unknown2[236];		// 0x020C
	ident	PrimaryWeapon;
	ident	SecondaryWeapon;

	char	Zoom;				// 0x0320
	char	Zoom1;				// 0x0321
	char	Unknown3[610];		// 0x0322
	bone	LeftThigh;			// 0x0584
	bone	RightThigh;			// 0x05B8
	bone	Pelvis;				// 0x05EC
	bone	LeftCalf;			// 0x0620
	bone	RightCalf;			// 0x0654
	bone	Spine;				// 0x0688
	bone	LeftClavicle;		// 0x06BC
	bone	LeftFoot;			// 0x06F0
	bone	Neck;				// 0x0724
	bone	RightClavicle;		// 0x0758
	bone	RightFoot;			// 0x078C
	bone	Head;				// 0x07C0
	bone	LeftUpperArm;		// 0x07F4
	bone	RightUpperArm;		// 0x0828
	bone	LeftLowerArm;		// 0x085C
	bone	RightLowerArm;		// 0x0890
	bone	LeftHand;			// 0x08C4
	bone	RightHand;			// 0x08F8
	char	Unknown4[1216];		// 0x092C
}; // Size - 3564(0x0DEC) bytes

////////////////////
// Generic Weapon //
////////////////////
struct AWeapon
{
	AObject			Object;
	char			Unknown[24];
	ident			UnknownIdent;
	unsigned long	NetworkTime;
	char			Unknown1[36];
	unsigned long	UnknownFlags	:	32;
	unsigned long	UnknownBit		:	1;
	unsigned long	Fire			:	1;
	unsigned long	Grenade			:	1;
	unsigned long	Reload			:	1;
	unsigned long	Melee			:	1;
	unsigned long	UnknownBit1		:	1;
	unsigned long	Zoom			:	1;
	unsigned long	UnknownBit2		:	1;
	unsigned long	UnusedBits		:	24;
	float			Unknown2;
	bool			IsFiring;
	char			Unknown3;
	unsigned short	WeaponReadyWaitTime;
	char			Unknown4[36];
	unsigned long	SomeCounter;
	unsigned long	IsNotFiring;
	unsigned long	Unknown5[2];
	float			Unknown6;
	unsigned long	Unknown7;
	float			Unknown8[2];
	ident			UnknownIdent1;
	unsigned long	AutoReloadCounter;
	unsigned char	Unknown9[40];
	unsigned short	ReloadFlags; // 0=NotReloading,1=Reloading, 2=???, 3=???
	unsigned short	ReloadCountdown;
	unsigned short	Unknown10;
	unsigned short	BulletCountInRemainingClips;
	unsigned short	BulletCountInCurrentClip;
	char			Unknown11[18];
	ident			UnknownIdent2;
	unsigned long	LastBulletFiredTime;
	char			Unknown12[16];
	vect3			Unknown13[2];
	char			Unknown14[12];
	unsigned long	BulletCountInRemainingClips1;
	char			Unknown15[52];
}; // Size - 1644(0x066C)

///////////////////
// Human Weapons //
///////////////////
struct ASniperRifle
{
	AWeapon		Weapon;
	bone		UnknownBone[4];
	float		FloatTable[32];
	char		Unknown[128];
};

struct APistol
{
	AWeapon		Weapon;
	bone		UnknownBone[7];
	float		FloatTable[56];
	char		Unknown[224];
};

struct AAssaultRifle
{
	AWeapon		Weapon;
	bone		UnknownBone[3];
	float		FloatTable[24];
	char		Unknown[96];
};

struct AShotgun
{
	AWeapon		Weapon;
	bone		UnknownBone[2];
	float		FloatTable[16];
	char		Unknown[64];
};

struct ARocketLauncher
{
	AWeapon		Weapon;
	bone		UnknownBone[5];
	float		FloatTable[40];
	char		Unknown[160];
};

struct AFlameThrower
{
	AWeapon		Weapon;
	bone		UnknownBone;
	float		FloatTable[8];
	char		Unknown[32];
};

//////////////////////
// Covenant Weapons //
//////////////////////
struct APlasmaRifle
{
	AWeapon		Weapon;
	bone		UnknownBone[5];
	float		FloatTable[40];
	char		Unknown[160];
};

struct APlasmaPistol
{
	AWeapon		Weapon;
	bone		UnknownBone[4];
	float		FloatTable[32];
	char		Unknown[128];
};

struct ANeedler
{
	AWeapon		Weapon;
	bone		UnknownBone;
	float		FloatTable[8];
	char		Unknown[32];
};

struct APlasmaCannon
{
	AWeapon		Weapon;
	bone		UnknownBone;
	float		FloatTable[8];
	char		Unknown[32];
};

// Main header to the entire array of object classes
struct LoopObjectsHeader
{
	char	Name[32]; // 'loop objects'
	long	Zero;
	void*	Start;
	short	Unknown[4];
	void*	First;
	void*	Last;
};

// Each object class has one of these before it
struct LoopObjectsSubHeader
{
	char			HeadSignature[4];	// 'daeh'
	unsigned long	Size;				// of entire object class, including this header
	void*			Address;			// pointer to the CObjectArray->Offset
	void*			Next;				// pointer to the next subheader
	long			Unknown;
	char			FootSignature[4];	// 'toof'
};

class CObjects
{
private:
	AObjectData*	ObjectData;
public:
	CObjects();
	~CObjects();

	void PrintObjectInfo();
	ident GetObjectIdent(unsigned char object_index);
};
#endif /* OBJECTS_H */