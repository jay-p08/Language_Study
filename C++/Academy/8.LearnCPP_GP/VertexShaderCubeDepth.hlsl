cbuffer CBuf
{
    matrix transform; // col major
};

float4 main(float3 pos : Position) : SV_Position
{
    return mul(float4(pos, 1.0f), transform); // 벡터 * 매트릭스
}