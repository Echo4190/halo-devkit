#include "d3d9hook.h"

typedef long (__stdcall *pEndScene)(IDirect3DDevice9* pDevice);
pEndScene oEndScene;

long __stdcall hkEndScene(IDirect3DDevice9* pDevice)
{
	return oEndScene(pDevice);
}

typedef long (__stdcall *pReset)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS *pPresentationParameters);
pReset oReset;

// Note: Xfire also hooks Reset, which means the game will crash if device is lost and reset while xfire is open
// TODO: Make xfire compatible with Reset, by hooking deeper into the function, so there are no conflicts

long __stdcall hkReset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	HRESULT hResult = oReset(pDevice, pPresentationParameters);
	return hResult;
}

typedef long (__stdcall *pDrawIndexedPrimitive)(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimType, int BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
pDrawIndexedPrimitive oDrawIndexedPrimitive;

long __stdcall hkDrawIndexedPrimitive(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex,UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

typedef long (__stdcall *pSetStreamSource)(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride);
pSetStreamSource oSetStreamSource;

long __stdcall hkSetStreamSource(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride)
{
	return oSetStreamSource(pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
}

int __stdcall hkD3D9Hook(void)
{
	IDirect3DDevice9*** pHaloDevice = (IDirect3DDevice9***)0x0071D09C;
	vTable_D3D9* vD3D9 = (vTable_D3D9*)**pHaloDevice;
	//oEndScene = (pEndScene)DetourFunction((PBYTE)vD3D9->EndScene, (PBYTE)hkEndScene);
	//oReset = (pReset)DetourFunction((PBYTE)vD3D9->Reset, (PBYTE)hkReset);
	//oDrawIndexedPrimitive = (pDrawIndexedPrimitive)DetourFunction((PBYTE)vD3D9->DrawIndexedPrimitive, (PBYTE)hkDrawIndexedPrimitive);
	//oSetStreamSource = (pSetStreamSource)DetourFunction((PBYTE)vD3D9->SetStreamSource, (PBYTE)hkSetStreamSource);

	return 0;
}