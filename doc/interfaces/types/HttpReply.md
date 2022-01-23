# HttpReply

### Description

This structure is an example module communication structure for the HTTP protocol.
The goal of this structure is to contain necessary information to build an HTTP reply.
It will be transferred between `Modules` where it will be mutated and then, the structure will be
provided to the `ReplySender` to send it to the client.

To get extra information, feel free to read [header](../../../include/types/HttpReply.hpp), it contains a lot of
comments explaining each field.
