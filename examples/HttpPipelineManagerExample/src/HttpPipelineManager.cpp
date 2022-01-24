#include <iostream>

#include "HttpPipelineManager.hpp"

namespace api::pipelines
{
    void HttpPipelineManager::listen()
    {
        _listener.listen();
    }

    void HttpPipelineManager::stop()
    {
        _listener.stop();
    }

    void HttpPipelineManager::configurePipeline(const PipelineConfig &config)
    {
        // load config.listenerPath lib as listener
        // load config.parserPath lib as parser
        // load config.senderPath lib as sender

        _modules.erase(_modules.begin(), _modules.end());
        for (const auto &e : config.modulesPaths)
        {
            // replace this lambda by the extern "C" function loaded from the shared library that instantiate the module
            std::function<std::unique_ptr<IModule<RequestDataType, ReplyDataType>> ()> loadModule{
                []() -> std::unique_ptr<IModule<RequestDataType, ReplyDataType>> {
                    std::cout << "Module loaded !" << std::endl;
                    return nullptr;
                }
            };

            // replace this lambda by the extern "C" function loaded form the shared library that returns the typeid of
            // the type of the module. This step is optional, it just ensures that the module is compatible with the
            // pipeline
            std::function<std::size_t ()> typeCheck(
                []() -> std::size_t {
                    return typeid(std::unique_ptr<IModule<RequestDataType, ReplyDataType>>).hash_code();
                }
            );

            std::unique_ptr<IModule<RequestDataType, ReplyDataType>> ptr = loadModule();

            // compare the modules with the type and check if they are compatible (this step is optional)
            if (typeCheck() != typeid(decltype(ptr)).hash_code())
                throw std::runtime_error("Error, incompatible module provided");
            _modules.emplace_back(std::move(ptr));
        }
        _listener.onPacket([this] (std::vector<std::byte> &&packet, IClient const &client) -> void {
            // preparation
            _onPacket(std::forward<std::vector<std::byte>>(packet), client);
            // cleanup
        });
    }

    void HttpPipelineManager::_onPacket(std::vector<std::byte> &&packet, IClient const &client)
    {
        RequestDataType request = _parser.parse(packet);
        ReplyDataType reply;

        for (const auto &e : _modules)
            e->process(request, reply);
        _sender.send(reply, client);
    }
}
