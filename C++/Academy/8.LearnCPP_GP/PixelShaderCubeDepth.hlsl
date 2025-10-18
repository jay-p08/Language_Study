cbuffer CBuf
{
    float4 face_colors[6];
};

// PixelShaderCube2.hlsl 파일에서 속성 -> HLSL 컴파일 -> 일반 -> 셰이더 모델 : Shader Model 4(/4_0) 세팅
float4 main(uint tid : SV_PrimitiveID) : SV_Target
{
    return face_colors[tid / 2];
}