#pragma once
#include <DirectXMath.h>
#include "ZConditionalNoexcept.h"

namespace Bind
{
    class ZBindable;
    class ZIndexBuffer;
}

class ZGraphics;

class ZRenderable
{
    template <class T>
    friend class ZRenderableBase;

private:
    virtual const std::vector<std::unique_ptr<Bind::ZBindable>> &GetStaticBinds() const noexcept = 0;

private:
    const Bind::ZIndexBuffer *pIndexBuffer = nullptr;
    std::vector<std::unique_ptr<Bind::ZBindable>> binds;

public:
    ZRenderable() = default;
    ZRenderable(const ZRenderable &) = delete;
    virtual DirectX::XMMATRIX GetTransformXM() const noexcept = 0;
    void Render(ZGraphics &gfx) const noxnd;
    virtual void Update(float dt) noexcept = 0;
    virtual ~ZRenderable() = default;

protected:
    template <class T>
    T *QueryBindable() noexcept
    {
        for (auto &pb : binds)
        {
            if (auto pt = dynamic_cast<T *>(pb.get()))
            {
                return pt;
            }
        }
        return nullptr;
    }
    void AddBind(std::unique_ptr<Bind::ZBindable> bind) noxnd;
    void AddIndexBuffer(std::unique_ptr<Bind::ZIndexBuffer> ibuf) noxnd;
};