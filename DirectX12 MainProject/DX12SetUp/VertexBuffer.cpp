#include "Base/pch.h"
#include "Base/dxtk.h"

#include "VertexBuffer.h"

void VertexBuffer::Init(int size, int stride)
{
	auto heapProp = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	auto rDesc = CD3DX12_RESOURCE_DESC::Buffer(size);
	auto hr =DXTK->Device->CreateCommittedResource(
		&heapProp,
		D3D12_HEAP_FLAG_NONE,
		&rDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(m_vertexBuffer.ReleaseAndGetAddressOf())
	);
	DX::ThrowIfFailed(hr);

	m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
	m_vertexBufferView.SizeInBytes = size;
	m_vertexBufferView.StrideInBytes = stride;
}

void VertexBuffer::Copy(void* srcVertices)
{
	void* pData;
	m_vertexBuffer->Map(0, nullptr, &pData);
	memcpy(pData, srcVertices, m_vertexBufferView.SizeInBytes);
	m_vertexBuffer->Unmap(0, nullptr);
}
