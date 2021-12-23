#pragma once

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class DX12Shader {
public:

	void LoadPS(const LPCWSTR fileName, const char* entryName);
	void LoadVS(const LPCWSTR fileName, const char* entryName);

	ComPtr<ID3DBlob> Get() { return m_blob; }
private:
	void Load(const LPCWSTR fileName, const char* entryName,const char* shaderMode);

private:
	ComPtr<ID3DBlob> m_blob;
};