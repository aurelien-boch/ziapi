# IReplySender

## Description
The IReplySender interface defines methods that `ReplySender` must implement.
The goal of the `ReplySender` is to serialize a reply to its final form according the protocol (for example: in HTTP
protocol the structure must be converted to a string that meets rfc7540 requirements).

## How it works
When the `PipelineManager` is done processing the request and applying all the middlewares, it will call the
`send()` method of `IReplySender` with the final reply to send it to client.
