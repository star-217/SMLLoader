#include "Base/pch.h"
#include "Base/dxtk.h"

#include "IndexBuffer.h"

void IndexBuffer::Init(int size, int stride)
{
	if (stride == 2)
	{
		m_sizeInBytes = size * 2;
	}
	else
	{
		m_sizeInBytes = size;
	}
	auto heapProp = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	auto rDesc = CD3DX12_RESOURCE_DESC::Buffer(m_sizeInBytes);
	auto hr = DXTK->Device->CreateCommittedResource(
		&heapProp,
		D3D12_HEAP_FLAG_NONE,
		&rDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(m_indexBuffer.ReleaseAndGetAddressOf())
	);
	DX::ThrowIfFailed(hr);


	//インデックスバッファのビューを作成。
	m_indexBufferView.BufferLocation = m_indexBuffer->GetGPUVirtualAddress();


	//ストライドは４バイト固定。
	m_strideInBytes = 4;
	m_indexBufferView.Format = DXGI_FORMAT_R32_UINT;
	m_indexBufferView.SizeInBytes = m_sizeInBytes;

	m_count = m_sizeInBytes / m_strideInBytes;
}

void IndexBuffer::Copy(int* srcIndecies)
{
	void* pData;
	m_indexBuffer->Map(0,nullptr, &pData);
	CopyMemory(pData, srcIndecies, m_count);

}
