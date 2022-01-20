# IClient

### Description
The IClient interface defines methods that `Client` must implement.
The goal of this interface is to abstract the communication method to the rest of the pipeline.

### Listener
This interface will be used in the Listener. You are free to chose how your listener work and how it will interact
with the Client.

### ReplySender
This interface will also be used in the reply sender which will call (normally) only the `send()` method.
