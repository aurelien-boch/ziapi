# IClient

The IClient interface defines `Client` methods that must be implemented.
As long as all method are implemented with the required behavior, you are free to chose how the class will work.

### Listener:

This interface will be used in the Listener. You are free to chose how your listener socket work and how it will interact
with the Client.

### ReplySender:

This interface will also be used in the reply sender which will call (normally) only the `send()` method.
