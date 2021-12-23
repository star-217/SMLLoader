#include "Base/pch.h"
#include "Base/dxtk.h"

#include "DX12Shader.h"

#include <d3dcompiler.h>

void DX12Shader::LoadPS(const LPCWSTR fileName, const char* entryName)
{
	Load(fileName, entryName,"ps_5_0");
}

void DX12Shader::LoadVS(const LPCWSTR fileName, const char* entryName)
{
	Load(fileName, entryName, "vs_5_0");
}

void DX12Shader::Load(const LPCWSTR fileName, const char* entryName, const char* shaderMode)
{
	ComPtr<ID3DBlob> error_blob;
	auto result = D3DCompileFromFile(
		fileName,
		nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
		entryName, shaderMode,
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0,
		m_blob.ReleaseAndGetAddressOf(),
		error_blob.ReleaseAndGetAddressOf()
	);

	if (FAILED(result))
	{
		MessageBoxA(nullptr, "シェーダーの読み込みを失敗しました　\n", "error", MB_OK);
		std::abort();
	}

}
