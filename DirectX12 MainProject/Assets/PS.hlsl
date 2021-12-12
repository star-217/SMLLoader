
struct VSOUT
{
	float4 svpos  : SV_POSITION;
	float4 normal : NORMAL;
	float2 uv     : TEXCOORD;
};

float4 BasicPS(VSOUT input) : SV_TARGET
{
	float3 light = normalize(float3(1,-1,5));
	float brightness = max(dot(-light, input.normal), 0.0f);
	brightness = min(brightness + 0.25f, 1.0f);

	return float4(brightness, brightness, brightness, 1.0f);
}