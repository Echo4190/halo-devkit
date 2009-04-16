#include "blam.h"

CBlam::CBlam()
{
	server_blam = (Blam*)SERVER_BLAM_ADDRESS;
	local_blam = (Blam*)LOCAL_BLAM_ADDRESS;
}
CBlam::~CBlam()
{
}

void CBlam::SetGameTypeName(Blam* blam, wchar_t *wName){ memcpy(blam->GameTypeName, wName, 24); }
wchar_t *CBlam::GetGameTypeName(Blam* blam){ return blam->GameTypeName; }

void CBlam::SetGameType(Blam* blam, long dwType){ blam->GameType = dwType; }
void CBlam::SetTeamPlay(Blam* blam, long dwNum){ blam->TeamPlay = dwNum; }
long CBlam::GetGameType(Blam* blam){ return blam->GameType; }
long CBlam::GetTeamPlay(Blam* blam){ return blam->TeamPlay; }

void CBlam::SetBallIndicator(Blam* blam, bool bNum){ blam->BallIndicator = bNum; }
void CBlam::SetFriendsOnRadar(Blam* blam, bool bNum){ blam->FriendsOnRadar = bNum; }
void CBlam::SetStartEquipment(Blam* blam, bool bNum){ blam->StartEquipment = bNum; }
void CBlam::SetInvisible(Blam* blam, bool bNum){ blam->Invisible = bNum; }
void CBlam::SetShields(Blam* blam, bool bNum){ blam->Shields = bNum; }
void CBlam::SetInfiniteGrenades(Blam* blam, bool bNum){ blam->InfiniteGrenades = bNum; }
void CBlam::SetFriendIndicators(Blam* blam, bool bNum){ blam->FriendIndicators = bNum; }
void CBlam::SetPlayersOnRadar(Blam* blam, bool bNum){ blam->PlayersOnRadar = bNum; }

bool CBlam::GetBallIndicator(Blam* blam){ return blam->BallIndicator; }
bool CBlam::GetFriendsOnRadar(Blam* blam){ return blam->FriendsOnRadar; }
bool CBlam::GetStartEquipment(Blam* blam){ return blam->StartEquipment; }
bool CBlam::GetInvisible(Blam* blam){ return blam->Invisible; }
bool CBlam::GetShields(Blam* blam){ return blam->Shields; }
bool CBlam::GetInfiniteGrenades(Blam* blam){ return blam->InfiniteGrenades; }
bool CBlam::GetFriendIndicators(Blam* blam){ return blam->FriendIndicators; }
bool CBlam::GetPlayersOnRadar(Blam* blam){ return blam->PlayersOnRadar; }
