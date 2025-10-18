//struct VSOut
//{
//    float3 color : Color;
//    float4 pos : SV_Position;
//};
//
//VSOut main(float2 pos : Position, float3 color : Color)
//{
//    VSOut vso;
//    vso.pos = float4(pos.x, pos.y, 0.0f, 1.0f);
//    vso.color = color;
//    return vso;
//}

float4 main(float2 pos : Position) : SV_Position // 버텍스 셰이더가 반환하는 float4 값이 클립 공간(Clip Space)에서의 최종 정점 위치임을 렌더링 파이프라인에 알려줍니다.
{
    return float4(pos.x, pos.y, 0.0f, 1.0f);
}