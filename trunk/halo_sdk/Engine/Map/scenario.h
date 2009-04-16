#ifndef SCENARIO_H
#define SCENARIO_H

//#include "map.h"
//#include "bsp.h"

struct ScenarioHeader
{
	char			Unknown1[16];			// 0x0000
	char			Unknown2[16];			// 0x0010
	char			Unknown3[16];			// 0x0020
	TagBlock		SkyBox;					// 0x0030
	unsigned long	Unknown4;				// 0x003C
	TagBlock		ChildScenarios;			// 0x0040
	unsigned long	UnNeeded1[46];			// 0x004C
	unsigned long	EditorScenarioSize;		// 0x0104
	unsigned long	Unknown5;				// 0x0108
	unsigned long	Unknown6;				// 0x010C
	void*			PointerToIndex;			// 0x0110
	unsigned long	UnNeeded2[2];			// 0x0114
	void*			PointerToEndOfIndex;	// 0x011C
	unsigned long	Zeros[57];				// 0x0120
	TagBlock		ObjectNames;			// 0x0204
	TagBlock		Scenery;				// 0x0210
	TagBlock		SceneryRef;				// 0x021C
	TagBlock		Biped;					// 0x0228
	TagBlock		BipedRef;				// 0x0234
	TagBlock		Vehicle;				// 0x0240
	TagBlock		VehicleRef;				// 0x024C
	TagBlock		Equip;					// 0x0258
	TagBlock		EquipRef;				// 0x0264
	TagBlock		Weap;					// 0x0270
	TagBlock		WeapRef;				// 0x027C
	TagBlock		DeviceGroups;			// 0x0288
	TagBlock		Machine;				// 0x0294
	TagBlock		MachineRef;				// 0x02A0
	TagBlock		Control;				// 0x02AC
	TagBlock		ControlRef;				// 0x02B8
	TagBlock		LightFixture;			// 0x02C4
	TagBlock		LightFixtureRef;		// 0x02D0
	TagBlock		SoundScenery;			// 0x02DC
	TagBlock		SoundSceneryRef;		// 0x02E8
	TagBlock		Unknown7[7];			// 0x02F4
	TagBlock		PlayerStartingProfile;	// 0x0348
	TagBlock		PlayerSpawn;			// 0x0354
	TagBlock		TriggerVolumes;			// 0x0360
	TagBlock		Animations;				// 0x036C
	TagBlock		MultiplayerFlags;		// 0x0378
	TagBlock		MpEquip;				// 0x0384
	TagBlock		StartingEquip;			// 0x0390
	TagBlock		BspSwitchTrigger;		// 0x039C
	TagBlock		Decals;					// 0x03A8
	TagBlock		DecalsRef;				// 0x03B4
	TagBlock		DetailObjCollRef;		// 0x03C0
	TagBlock		Unknown8[7];			// 0x03CC
	TagBlock		ActorVariantRef;		// 0x0420
	TagBlock		Encounters;				// 0x042C
	TagBlock		CommandLists;			// 0x0438
	TagBlock		Unknown9;				// 0x0444
	TagBlock		StartingLocations;		// 0x0450
	TagBlock		Platoons;				// 0x045C
	TagBlock		AiConversations;		// 0x0468
	unsigned long	ScriptSyntaxDataSize;	// 0x0474
	unsigned long	Unknown10;				// 0x0478
	TagBlock		ScriptCrap;				// 0x047C
	TagBlock		Commands;				// 0x0488
	TagBlock		Points;					// 0x0494
	TagBlock		AiAnimationRefs;		// 0x04A0
	TagBlock		GlobalsVerified;		// 0x04AC
	TagBlock		AiRecordingRefs;		// 0x04B8
	TagBlock		Unknown11;				// 0x04C4
	TagBlock		Participants;			// 0x04D0
	TagBlock		Lines;					// 0x04DC
	TagBlock		ScriptTriggers;			// 0x04E8
	TagBlock		VerifyCutscenes;		// 0x04F4
	TagBlock		VerifyCutsceneTitle;	// 0x0500
	TagBlock		SourceFiles;			// 0x050C
	TagBlock		CutsceneFlags;			// 0x0518
	TagBlock		CutsceneCameraPoi;		// 0x0524
	TagBlock		CutsceneTitles;			// 0x0530
	TagBlock		Unknown12[8];			// 0x053C
	unsigned long	Unknown13[2];			// 0x059C
	TagBlock		StructBsp;				// 0x05A4
	// Binary Space Partitioning (BSP Tree) - The actual map layout ( excluding objects! )
};	/* ScenarioHeader Size = 0x05B0 ( 1456 bytes ) */

struct SkyBox
{
	TagReference	SkyBoxRef;
};

struct ScenerySpawn
{
	short			NumID;
	short			Flag;
	unsigned long	Unknown;
	vect3			World;
	vect3			Rotation;
	long			Unknown1[10];
};

struct SceneryRef
{
	TagReference	SceneryRef;
	unsigned long	Zero[8];
};

struct VehicleSpawn
{
	short			NumID;
	short			Flag;
	unsigned long	Unknown;
	vect3			World;
	vect3			Rotation;
	unsigned long	Unknown1[22];
};

struct VehicleRef
{
	TagReference	VehicleRef;
	unsigned long	Zero[8];
};

struct PlayerSpawn
{
	vect3			World;
	float			Yaw;
	long			Team;
	unsigned long	Unknown[8];
};

struct MpEquip
{
	unsigned long	Unknown[16];
	vect3			World;
	float			Yaw;
	TagReference	MpEquipRef;
	unsigned long	Unknown1[12];
};

#endif /* SCENARIO_H */