# IPipelineManager

### Description
The IPipelineManager interface defines method that `PipelineManager` must implement.
The goal of the `PipelineManager` is to make `Listener`, `Parser`, `Modules` and `ReplySender` work together.
It achieves that by holding an instance of a `Listener`, a `Parser`, some `Modules` and `ReplySender`

### How it works
The `PipelineManager` has two states:
* The setup state
* The listen state

#### The setup state:
During the setup state, the `PipelineManager` will load all the libs provided in the `PipelineConfig` and unload all
unused libs. It will also pass an internal method as callback to the `Listener`.

#### The listen state:
During the listen state, the `PipelineManager` will listen for any new connection and message. When a full message is
received the method bound with the `Listener` will be called. The `PipelineManager` will then call the parser, which will
return a parsed request, that will be passed by reference with a blank request. The modules will next be called (in the
order they have been registered) and will mutate the request / response, the mutated response will then be passed to the
`ReplySender` (as well as the client) that will send the response to client.
