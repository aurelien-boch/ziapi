# HttpRequest

### Description

This structure is an example module communication structure for the HTTP protocol.
The goal of this structure is to contain all information provided to the server in the user's request.

It will be created by the parser when a request is provided. Then, it will be transferred to all `Modules`
that will use it to build a reply and/or mutate it.

To get extra information, feel free to read [header](../../../include/types/HttpRequest.hpp), it contains a lot of
comments explaining each field.
