#pragma once

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class IndexBuffer {
public:
	void Init(int size, int stride);
	void Copy(int* srcIndecies);

	D3D12_INDEX_BUFFER_VIEW GetView() { return m_indexBufferView; }

private:
	ComPtr<ID3D12Resource> m_indexBuffer = nullptr;
	D3D12_INDEX_BUFFER_VIEW m_indexBufferView;
	int m_count = 0;
	int m_strideInBytes = 0;
	int m_sizeInBytes = 0;
};