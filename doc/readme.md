# Documentation
Here is a summary containing links to all interfaces.

## Summary
 * [IClient interface documentation](interfaces/IClient.md)
 * [IListener interface documentation](interfaces/IClient.md)
 * [IModule interface documentation](interfaces/IClient.md)
 * [IPacketParser interface documentation](interfaces/IClient.md)
 * [IPipelineManager interface documentation](interfaces/IClient.md)
 * [IReplySender interface documentation](interfaces/IClient.md)
 * [Interfaces UML](interfaces.puml)

## Description

This API uses both composition and inheritance to provide a generic way to set up
a custom server with a custom communication protocol and custom middlewares.

You can for instance put an HTTP server as well as an FTP or SMTP one.
Here is a small overview of how a pipeline works:

  - Setup phase
    - The `PipelineManager` contains an instance of the `Listener`, `PacketParser`, `ReplySender` and a vector of all
      `Modules` used by the pipeline.
    - The `PipelineManager` will send it's `processRequest()` method as a callback to the `onPacket()` method of the
      listener
    - When the `listen()` method of the `Listener` is called, the `Listener` starts listen for new packets.

  - Processing phase
    - When the `Listener` receives a full packet, it just calls corresponding callback (the `processRequest()` method from the
      `PipelineManager`)
    - The `PipelineManager` will then call the `PacketParser`, giving it the raw request. The `PacketParser` will return
      the parsed request.
    - The `PipelineManager` will next call each `Module` in the order they have been registered with the parsed request
      and a blank response. The modules will then mutate the request and/or the response.
    - When all modules are called, the `PipelineManager` will call the reply sender to send back the reply to the client.
