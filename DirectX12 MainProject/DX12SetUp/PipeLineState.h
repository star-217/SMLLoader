#pragma once

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class PipelineState
{
public:
	~PipelineState() {};

	void Init(D3D12_GRAPHICS_PIPELINE_STATE_DESC desc);
	void Init(D3D12_COMPUTE_PIPELINE_STATE_DESC desc);

	ComPtr<ID3D12PipelineState> Get() { return m_pipelineState; }
private:
	
	ComPtr<ID3D12PipelineState> m_pipelineState;
};