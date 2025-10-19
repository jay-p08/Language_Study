#include "ZD3D11.h"
#include "ZRenderable.h"
#include "GraphicsThrowMacros.h"
#include "ZIndexBuffer.h"
#include <cassert>

using namespace Bind;

void ZRenderable::Render(ZGraphics& gfx) const noxnd
{
    for (auto& b : binds)
    {
        b->Bind(gfx);
    }
    for (auto& b : GetStaticBinds())
    {
        b->Bind(gfx);
    }
    gfx.RenderIndexed(pIndexBuffer->GetCount());
}

void ZRenderable::AddBind(std::unique_ptr<Bind::ZBindable> bind) noxnd
{
    assert("Must use AddIndexBuffer to bind index buffer" && typeid(*bind) != typeid(ZIndexBuffer));
    binds.push_back(std::move(bind));
}

void ZRenderable::AddIndexBuffer(std::unique_ptr<ZIndexBuffer> ibuf) noxnd
{
    assert("Attempting to add index buffer a second time" && pIndexBuffer == nullptr);
    pIndexBuffer = ibuf.get();
    binds.push_back(std::move(ibuf));
}