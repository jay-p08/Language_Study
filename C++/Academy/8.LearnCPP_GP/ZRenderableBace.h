#pragma once
#include "ZD3D11.h"
#include "ZRenderable.h"
#include "ZIndexBuffer.h"
#include "ZConditionalNoexcept.h"

template<class T>
class ZRenderableBase : public ZRenderable
{
protected:
    static bool IsStaticInitialized() noexcept
    {
        return !staticBinds.empty();
    }
    static void AddStaticBind(std::unique_ptr<Bind::ZBindable> bind) noxnd
    {
        assert("Must use AddStaticIndexBuffer to bind index buffer" && typeid(bind) != typeid(Bind::ZIndexBuffer));
        staticBinds.push_back(std::move(bind));
    }
    void AddStaticIndexBuffer(std::unique_ptr<Bind::ZIndexBuffer> ibuf) noxnd
    {
        assert("Attempting to add index buffer a second time" && pIndexBuffer == nullptr);
        pIndexBuffer = ibuf.get();
        staticBinds.push_back(std::move(ibuf));
    }
    void SetIndexFromStatic() noxnd
    {
        assert("Attempting to add index buffer a second time" && pIndexBuffer == nullptr);
        for (const auto& b : staticBinds) 
        {
            if (const auto p = dynamic_cast<Bind::ZIndexBuffer>(b.get()))
            {
                // 바인더 중에서 인덱스 버퍼 찾아서 포인터 재활용한다.
                pIndexBuffer = p;
                return;
            }
        }
        assert("Failed to find index buffer in static binds" && pIndexBuffer != nullptr);
    }
private:
    const std::vector<std::unique_ptr<Bind::ZBindable>>& GetStaticBinds() const noexcept override
    {
        return staticBinds;
    }
private:
    static std::vector<std::unique_ptr<Bind::ZBindable>> staticBinds;
};

template<class T>
std::vector<std::unique_ptr<Bind::ZBindable>> ZRenderableBase<T>::staticBinds;