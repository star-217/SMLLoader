#pragma once

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class VertexBuffer {
public:
	void Init(int size, int stride);
	void Copy(void* srcVertices);

	D3D12_VERTEX_BUFFER_VIEW GetView() { return m_vertexBufferView; }
private:
	ComPtr<ID3D12Resource> m_vertexBuffer = nullptr;
	D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
};