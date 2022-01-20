# IModule

### Description
The IModule interface defines methods that `Module` must implement.
The goal of the modules is to process request doing basic actions (each `Module` process a small part of the request), for
example, a `Module` can log the request, another one can ensure the user is authenticated, etc.

### How it works
The `Module` has a `process()` method that takes two arguments:
 * The parsed request
 * The reply to send back to the client.

The `Module` can mutate both request and reply, for example, you can create a module that will parse the Authorization
header of a client and set the JWT token in the request.
