#pragma once

#include "pch.h"
#include "dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class SMLFile {
public:
	struct SVertex
	{
		XMFLOAT3 pos;
		XMFLOAT3 normal;
		XMFLOAT2 uv;
	};



	void Load(const char* fileName);

	int GetnumVertex() { return numVertex; }
	std::vector<SVertex> GetVertex() { return vertices; }
	std::vector<int> GetIndex() { return indeces; }


private:
	void LoadVertex(FILE* fp);
	void LoadIndex(FILE* fp);

	int numVertex;

	std::vector<SVertex> vertices;
	std::vector<int> indeces;

};