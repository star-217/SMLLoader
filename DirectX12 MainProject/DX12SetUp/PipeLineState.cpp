#include "Base/pch.h"
#include "Base/dxtk.h"

#include "PipeLineState.h"

void PipelineState::Init(D3D12_GRAPHICS_PIPELINE_STATE_DESC desc)
{
	auto result = DXTK->Device->CreateGraphicsPipelineState(&desc, IID_PPV_ARGS(m_pipelineState.ReleaseAndGetAddressOf()));
	if (FAILED(result)) {
		MessageBoxA(nullptr, "パイプラインステートの作成に失敗しました \n", "error", MB_OK);
		std::abort();
	}
}

void PipelineState::Init(D3D12_COMPUTE_PIPELINE_STATE_DESC desc)
{
	auto result = DXTK->Device->CreateComputePipelineState(&desc, IID_PPV_ARGS(m_pipelineState.ReleaseAndGetAddressOf()));
	if (FAILED(result)) {
		MessageBoxA(nullptr, "パイプラインステートの作成に失敗しました \n", "error", MB_OK);
		std::abort();
	}
}
