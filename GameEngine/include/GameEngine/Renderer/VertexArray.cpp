#include <GameEngine/Renderer/VertexArray.h>
#include <GameEngine/Renderer/Renderer.h>
#include <GameEngine/platforms/OpenGL/OpenGLVertexArray.h>

namespace RendererEngine{

    Ref<VertexArray> VertexArray::Create(){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLVertexArray>();
        }

        render_core_assert(false, "Unknown renderer API");
        return nullptr;
    }
};
