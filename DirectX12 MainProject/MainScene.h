//
// MainScene.h
//

#pragma once

#include "Scene.h"
#include "Base/SMLFile.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class MainScene final : public Scene {
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	MainScene(MainScene&&) = default;
	MainScene& operator= (MainScene&&) = default;

	MainScene(MainScene const&) = delete;
	MainScene& operator= (MainScene const&) = delete;

	// These are the functions you will implement.
	void Initialize() override;
	void LoadAssets() override;

	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;

private:
	SMLFile sml;

	unique_ptr<DescriptorHeap> descHeaps;

	ComPtr<ID3D12Resource> vertexbuffer;
	D3D12_VERTEX_BUFFER_VIEW vbView;

	ComPtr<ID3D12Resource> indexbuffer;
	D3D12_INDEX_BUFFER_VIEW idxView;

	ComPtr<ID3D12Resource> constBuff;

	ComPtr<ID3DBlob> vsBlob;
	ComPtr<ID3DBlob> psBlob;

	ComPtr<ID3D12RootSignature> rootSignature;
	ComPtr<ID3D12PipelineState> pipelineState;

	DX12::CAMERA mainCamera;

	struct VSOUT
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX proj;
	};

};