#ifndef TAGS_H
#define TAGS_H

#include "../types.h"

#define TAG_INDEX_ADDRESS 0x40440000

struct ATagIndex;
struct ATagInstance;

class CTags
{
public:
	CTags();
	~CTags();

	ATagIndex*	TagIndex;

	char* GetTagPath(unsigned short tag_index);
	ATagInstance* GetTagInstance(unsigned long tag_index);

};

struct ATagIndex
{
	void*			FirstTagAddress;	// 0x00
	ident			FirstTag;			// 0x04
	long			Unknown;			// 0x08
	unsigned long	TagCount;			// 0x0C
	unsigned long	VertexCount;		// 0x10
	unsigned long	VertexOffset;		// 0x14
	unsigned long	IndicesCount;		// 0x18
	unsigned long	IndicesOffest;		// 0x1C
	unsigned long	CRC;				// 0x20
	unsigned long	Signature;			// 0x24		'tags'
}; // Size = 40 bytes(0x28)

struct ATagInstance
{
	union
	{
		unsigned long	TagGroup;		// 0x00
		char			TagGroupC[4];	// 0x00
	};
	union
	{
		unsigned long	TagChild;		// 0x04
		char			TagChildC[4];	// 0x04
	};
	union
	{
		unsigned long	TagParent;		// 0x08
		char			TagParentC[4];	// 0x08
	};
	ident			Tag;				// 0x0C
	char*			Name;				// 0x10
	void*			Address;			// 0x14
	long			Location;			// 0x18
	long			_Unused;			// 0x1C
}; // Size = 32 bytes(0x20)

struct TagReference
{
	unsigned long	TagGroup;			// 0x00
	char*			Name;				// 0x04
	long			NameLength;			// 0x08
	ident			Tag;				// 0x0C
}; // Size = 16 bytes(0x10)

struct TagBlock
{
	unsigned long	Count;				// 0x00
	void*			Address;			// 0x04
	unsigned long	Padding;			// 0x08
}; // Size = 12 bytes(0x0C)

struct TagData
{
	long			Size;				// 0x00
	long			Padding;			// 0x04
	long			Offset;				// 0x08
	void*			Address;			// 0x0C
	unsigned long	Pad;				// 0x10
}; // Size = 20 bytes(0x14)

// ************************
//      Tags
// ************************
// unknown = cont, foot, str#

#define TAG_GROUP_ACTOR_VARIANT 'actv'
#define TAG_GROUP_ANIMATION_TRIGGER 'antr'
#define TAG_GROUP_ANTENNA 'ant!'
#define TAG_GROUP_BIPED 'bipd'
#define TAG_GROUP_BITMAP 'bitm'
#define TAG_GROUP_COLLISION_MODEL 'coll'
#define TAG_GROUP_DAMAGE 'jpt!'
#define TAG_GROUP_DECAL 'deca'
#define TAG_GROUP_DIALOG 'udlg'
#define TAG_GROUP_EFFECT 'effe'
#define TAG_GROUP_EQUIPMENT 'eqip'
#define TAG_GROUP_FONT 'font'
#define TAG_GROUP_GAME_GLOBALS 'matg'
#define TAG_GROUP_GRENADE_HUD_INTERFACE 'grhi'
#define TAG_GROUP_HUD_GLOBALS 'hudg'
#define TAG_GROUP_HUD_MESSAGE_TEXT 'hmt '
#define TAG_GROUP_HUD_NUMBER 'hud#'
#define TAG_GROUP_ITEM_COLLECTION 'itmc'
#define TAG_GROUP_LENS 'lens'
#define TAG_GROUP_LIGHT 'ligh'
#define TAG_GROUP_LIGHT_VOLUME 'mgs2'
#define TAG_GROUP_LOOPING_SOUND 'lsnd'
#define TAG_GROUP_METER 'metr'
#define TAG_GROUP_MODEL 'mod2'
#define TAG_GROUP_PARTICLE 'part'
#define TAG_GROUP_PARTICLE_SYSTEM 'pctl'
#define TAG_GROUP_PHYSICS 'phys'
#define TAG_GROUP_POINT_PHYSICS 'pphy'
#define TAG_GROUP_PROJECTILE 'proj'
#define TAG_GROUP_SCENERY 'scen'
#define TAG_GROUP_SHADER_ENVIRONMENT 'senv'
#define TAG_GROUP_SHADER_GLASS 'sgla'
#define TAG_GROUP_SHADER_METAL 'smet'
#define TAG_GROUP_SHADER_MODEL 'soso'
#define TAG_GROUP_SHADER_PLASMA 'spla'
#define TAG_GROUP_SHADER_TRANSPARENCY_VARIANT 'schi'
#define TAG_GROUP_SKY 'sky '
#define TAG_GROUP_SOUND 'snd!'
#define TAG_GROUP_SOUND_ENVIRONMENT 'snde'
#define TAG_GROUP_SOUND_SCENERY 'ssce'
#define TAG_GROUP_STRUCTURE_BSP 'sbsp'
#define TAG_GROUP_TRACK 'trak'
#define TAG_GROUP_UNICODE_STRING 'ustr'
#define TAG_GROUP_UNIT_HUD_INTERFACE 'unhi'
#define TAG_GROUP_UNKNONW_PC_SHADER 'scex'
#define TAG_GROUP_VEHICLE 'vehi'
#define TAG_GROUP_WEAPON 'weap'
#define TAG_GROUP_WEAPON_HUD_INTERFACE 'wphi'
#define TAG_GROUP_WIND 'wind'

#define TAG_CHILD_DEVICE 'devi'
#define TAG_CHILD_ITEM 'item'
#define TAG_CHILD_OBJECT 'obje'
#define TAG_CHILD_SHADER 'shdr'
#define TAG_CHILD_UNIT 'unit'

#define TAG_PARENT_OBJECT 'obje'

struct ActorVariant // 'actv'
{
	unsigned long	Flags;						// 0x0000
	TagReference	ActorDefinition;			// 0x0004
	TagReference	Unit;						// 0x0014
	TagReference	MajorVariant;				// 0x0024

	// Movement Switching
	long			Zero[12];					// 0x0034

	// Ranged Combat
	TagReference	Weapon;						// 0x0064
	float			MaximumFiringDistance;		// 0x0074
	float			RateOfFire;					// 0x0078
	float			ProjectileError;			// 0x007C
	float			FirstBurstDelayTimeLow;		// 0x0080
	float			FirstBurstDelayTimeHigh;	// 0x0084
	float			NewTargetFiringPatternTime;	// 0x0088
	float			SupriseDelayTime;			// 0x008C
	float			SupriseFireWildlyTime;		// 0x0090
	float			DeathFireWildlyChance;		// 0x0094
	float			DeathFireWildlyTime;		// 0x0098
	float			DesiredCombatRangeLow;		// 0x009C
	float			DesiredCombatRangeHigh;		// 0x00A0
	vect3			CustomStandGunOffset;		// 0x00A4
	vect3			CustomCrouchGunOffset;		// 0x00B0
	float			TargetTracking;				// 0x00BC
	float			TargetLeading;				// 0x00C0
	float			WeaponDamageModifier;		// 0x00C4
	float			DamagePerSecond;			// 0x00C8

	// Burst Geometry
	float			BurstOriginRadius;			// 0x00CC
	float			BurstOriginAngle;			// 0x00D0
	float			BurstReturnLengthLow;		// 0x00D4
	float			BurstReturnLengthHigh;		// 0x00D8
	float			BurstReturnAngle;			// 0x00DC
	float			BurstDurationLow;			// 0x00E0
	float			BurstDurationHigh;			// 0x00E4
	float			BurstSeparationLow;			// 0x00E8
	float			BurstSeparationHigh;		// 0x00EC
	float			BurstAngularVelocity;		// 0x00F0
	float			SpecialDamageModifier;		// 0x00F4
	float			SpecialProjectileError;		// 0x00F8

	// Firing Patterns
	float			Unknown;					// 0x00FC
	float			NewTargetBurstDuration;		// 0x0100
	long			Zero1[31];					// 0x0104
	TagReference	Ojpr;						// 0x0180
	long			Zero2[12];					// 0x0190
	TagReference	Equip;						// 0x01C0
	long			Zero3[26];					// 0x01D0
}; // Size = 0x0238(568 bytes)

struct AnimationTrigger // 'antr'
{
	TagBlock		Objects;		// 0x0000
	TagBlock		Units;
	TagBlock		Weapons;
	TagBlock		Vehicles;
	TagBlock		Devices;
	TagBlock		UnitDamage;
	TagBlock		FirstPersonWeapons;
	TagBlock		SoundReferences;
	char			Unknown[8];
	TagBlock		Nodes;
	TagBlock		Animations;
};

struct Antenna // 'ant!'
{
	char			AttachmentMarkerName[32]; // antenna
	TagReference	Bitmaps;
	TagReference	Physics;
	long			Zero[20];
	float			SprintStrengthCoefficient;
	float			FalloffPixels;
	float			CutoffPixels;
	float			Unknown;
	long			Zero1[9];
	TagBlock		AntennaVertices;
};

	struct AntennaVertices
	{
		float SpringStrengthCoefficient;
		char Unknown[32];
		float Length;
		unsigned long SequenceIndex;
		float Color[4]; //argb
		char Unknown2[68];
	};

struct Biped // 'bipd'
{
	unsigned long	Flags; // bitfield
	float			BoundingRadius;
	vect3			BoundingOffset;
	vect3			OriginOffset;
	float			AccelerationScale;
	long			Unknown;
	TagReference	Model;
	TagReference	AnimationTrigger;
	long			Zero[10];
	TagReference	CollisionModel;
	TagReference	Physics;
	TagReference	ShaderPlasma;
	TagReference	CreationEffect;
	long			Zero1[21];
	float			Unknown1;
	short			Unknown2[2];
	long			Zero2[13];
	TagBlock		UnkBlock;
	long			Zero3[3];
	TagBlock		UnkBlock1;
	TagBlock		UnkBlock2;
	TagBlock		UnkBlock3;
	short			Unknown3[2];
	long			Unknown4;
	long			Zero4;
	TagReference	Effe1;
	long			Zero5;
	long			Unknown5;
	float			Unknown6;
	long			Zero6[20];
	TagBlock		UnkBlock4;
	long			Zero7[7];
	float			Unknown7[2];
	long			Zero8[10];
	TagReference	Actv;
	long			Zero9[11];
	TagReference	Jpt;
	long			Zero10[4];
	TagBlock		UnkBlock5;
	TagBlock		UnkBlock6;
	float			Unknown8;
	short			Unknown9[4];
	//long zero


	// TODO: Finish this struct.
};

/////////////////////////////
// Start Bitmap Structures //
/////////////////////////////
struct Bitmap // 'bitm'
{
	// Sprite Processing
	unsigned long	SpriteBudgetSize;
	unsigned long	SpriteBudgetCount;

	// Post Processing
	unsigned long	DetailFadeFactor;
	unsigned long	SharpenAmount;
	unsigned long	BumpHeight;

	// Usage
	unsigned short	Usage;

	// Format
	unsigned short	Format;

	// Color Plate
	unsigned short	ColorPlateWidth;
	unsigned short	ColorPlateHeight;
	unsigned long	CompressedColorPlateData;
	char			Unknown[24];

	// Processed Pixel Data
	unsigned long	ProcessedPixelData;
	char			Unknown2[20];

	// ...More Sprite Processing
	unsigned long	SpriteSpacing;
	TagBlock		Sequences;
	TagBlock		Bitmaps;
};
//----------------------------------------------
	struct BitmapSequence
	{
		char		Name[32];
		char		Unknown[20];
		TagBlock	Sprites;
	};
//----------------------------------------------
		struct BitmapSprite
		{
			float			Unknown;
			unsigned long	BitmapIndex;
			float			Left;
			float			Right;
			float			Top;
			float			Bottom;
			vect2			RegistrationPoint;
		};
//----------------------------------------------
	struct BitmapBitmap
	{
		unsigned long	Signature; // 'bitm'
		unsigned short	Width;
		unsigned short	Height;
		unsigned short	Depth;
		unsigned short	Type;
		unsigned short	Format;
		unsigned short	Flags;
		unsigned short	RegistrationPointX;
		unsigned short	RegistrationPointY;
		unsigned short	MipMapCount;
		unsigned long	PixelsOffset;
		unsigned long	Size;
		ident			BitmapIdent; // Maybe??
		char			Unknown[12];
	};
///////////////////////////
// End Bitmap Structures //
///////////////////////////


struct collision_model // 'coll'
{
	long zero[28];
	TagReference effe;
	long zero1;
	TagReference effe1;
	long zero2;
	TagReference effe2;
	TagReference effe3;
	long zero3;
	TagReference effe4;
	long zero4[47];
	TagReference effe5;
	TagReference effe6;
	TagReference effe7;
	long zero5[2];
	float unknown;
	long zero6[28];
	TagBlock unkref;
	TagBlock unkref1;
	long zero7[13];
	TagBlock unkref2;
	TagBlock unkref3;
};

struct damage // 'jpt!'
{
};

struct decal // 'deca'
{
};

struct dialog // 'udlg'
{
};

struct effect // 'effe'
{
};

struct equipment // 'eqip'
{
};

struct font // 'font'
{
};

struct game_globals // 'matg'
{
};

struct grenade_hud_interface // 'grhi'
{
};

struct hud_globals // 'hudg'
{
};

struct hud_message_text // 'hmt '
{
};

struct hud_number // 'hud#'
{
};

struct item_collection // 'itmc'
{
};

struct lens // 'lens'
{
	float falloff_angle;
	float cutoff_angle;
	float unknown[2];
	float occlusion_radius;
	float occlusion_offset_direction;
	float near_fade_distance;
	float far_fade_distance;
	TagReference bitm;
	long zero2[20];
	unsigned long rotation_function;
	float rotation_function_scale;
	long zero3[6];
	float unknown3[2];
	long zero4[7];
	TagBlock UnkRef;
	long unknown4[8];
};

struct light // 'ligh'
{
};

struct light_volume // 'mgs2'
{
};

struct looping_sound // 'lsnd'
{
};

struct meter // 'metr'
{
};

struct model // 'mod2'
{
	unsigned long flags;
	unsigned long node_list_checksum;
	unsigned long superhigh_detail_cutoff;
	unsigned long high_detail_cutoff;
	unsigned long medium_detail_cutoff;
	unsigned long low_detail_cutoff;
	unsigned long superlow_detail_cutoff;
	unsigned long superhigh_detail_node_count;
	unsigned long high_detail_node_count;
	unsigned long medium_detail_node_count;
	unsigned long low_detail_node_count;
	unsigned long superlow_detail_node_count;
	float base_map_u_scale;
	float base_map_v_scale;
	unsigned long zero[32];
	TagBlock nodes;
	TagBlock regions;
	TagBlock geometries;
	TagBlock shaders;
};

struct particle // 'part'
{
};

struct particle_system // 'pctl'
{
};

struct physics // 'phys'
{
};

struct point_physics // 'pphy'
{
};

struct projectile // 'proj'
{
};

struct scenery // 'scen'
{
	long unknown;
	float unknown1;
	long zero[8];
	TagReference mod2;
	TagReference antr;
	long zero1[10];
	TagReference coll;
	TagReference phys;
	TagReference shdr;
	TagReference effe;
	long zero2[21];
	float unknown2;
	long zero3[26];
	TagBlock UnkRef;
	long unknown3[32];
};

struct shader_environment // 'senv'
{
};

struct shader_glass // 'sgla'
{
};

struct shader_metal // 'smet'
{
};

struct shader_model // 'soso'
{
};

struct shader_plasma // 'spla'
{
};

struct shader_transparancy_variant // 'schi'
{
	long zero[9];
	long unknown;
	long zero2[4];
	TagReference lens;
	long zero3[3];
	TagBlock bitm;
	long zero4[3];
};

struct sky // 'sky '
{
	TagReference mod2;
	TagReference antr;
	long zero[6];
	float unknown[11];
	long zero2[2];
	float unknown2[6];
	long zero3[2];
	float unknown3[3];
	TagReference fog;
	long zero5[7];
	TagBlock UnkRef;
};

struct sound // 'snd!'
{
};

struct sound_environment // 'snde'
{
};

struct sound_scenery // 'ssce'
{
};

struct structure_bsp // 'sbsp'
{
};

struct track // 'trak'
{
};

struct unicode_string // 'ustr'
{
};

struct unit_hud_interface // 'unhi'
{
};

struct unknown_pc_shader // 'scex'
{
	long zero[9];
	long unknown;
	long zero1[4];
	TagReference lens;
	long zero2[3];
	TagBlock UnkRef;
	TagBlock UnkRef1;
	long zero3[3];
};

struct vehicle // 'vehi'
{
};

struct weapon // 'weap'
{
};

struct weapon_hud_interface // 'wphi'
{
	TagReference ChildHud;
	char Zero[116];
	TagBlock UnknownBlock;
	char Zero2[236];
};//size = 0x017C(380 bytes)

struct wind // 'wind'
{
};

// To be continued...



#endif /* TAGS_H */