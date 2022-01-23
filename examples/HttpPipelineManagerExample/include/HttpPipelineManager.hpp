#ifndef HTTPPIPELINEMANAGER_HPP
#define HTTPPIPELINEMANAGER_HPP

#include <vector>
#include <memory>
#include <IPipelineManager.hpp>
#include <IModule.hpp>
#include <types/HttpReply.hpp>
#include <types/HttpRequest.hpp>

#include "HttpListener.hpp"
#include "HttpPacketParser.hpp"
#include "HttpReplySender.hpp"

namespace api::pipelines
{
    class HttpPipelineManager : IPipelineManager
    {
        public:
            void listen() override;

            void stop() override;

            void configurePipeline(const PipelineConfig &config) override;

        private:
            // types are to make type change more easy (they are of course optional)
            using RequestDataType = HTTPRequest;
            using ReplyDataType = HTTPReply;

            listeners::HttpListener _listener;
            parsers::HttpPacketParser _parser;
            senders::HttpReplySender _sender;
            std::vector<std::unique_ptr<IModule<RequestDataType, ReplyDataType>>> _modules;

            void _onPacket(std::vector<std::byte> &&packet, IClient const &client);
    };
}

#endif //HTTPPIPELINEMANAGER_HPP
