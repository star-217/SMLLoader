#include "SMLFile.h"

void SMLFile::Load(const char* fileName)
{

	FILE* fp;
	auto hr = fopen_s(&fp, fileName, "rb");
	if (hr != 0)
	{
		MessageBoxA(nullptr, "smlファイルが開けません。", "エラー", MB_OK);
		return;
	}
	LoadVertex(fp);
	LoadIndex(fp);
}

void SMLFile::LoadVertex(FILE* fp)
{
	fread(&numVertex, 4, 1, fp);

	vertices.resize(numVertex);
	for (int i = 0; i < numVertex; i++)
	{
		fread(&vertices[i], sizeof(SVertex), 1, fp);
	}

}

void SMLFile::LoadIndex(FILE* fp)
{
	fread(&numVertex, 4, 1, fp);
	indeces.resize(numVertex);
	for (int i = 0; i < numVertex; i++)
	{
		fread(&indeces[i], sizeof(int), 1, fp);
	}
}

