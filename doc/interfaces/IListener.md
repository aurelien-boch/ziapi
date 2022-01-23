# IListener

### Description
The IListener interface defines methods that `Listener` must implement.
The goal of the `Listener` is to listen for new connections and wait for full packet before calling the callback method,
that was provided using the `onPacket` method.

You are free to chose how the internal `Listener` will work (as long as it matches your client implementation obviously).

###  Packet Decryption
If the packet is encrypted (using SSL / TLS for example) the `Listener` must decrypt it to know when the packet is complete
and then send the decrypted version to the callback.

### Client lifetime
The `Listener` is responsible for the lifetime of the `Client`. It MUST close it when necessary (for example:
in `HTTP protocol`, the `Client` must be closed when the reply is sent, whereas in FTP protocol, the `Client` must be closed
when the "close" command is received).

*note: in the text above, the `Client` term is used, it stands for your IClient implementation which contains a socket.
However, in some cases it can be something else than a socket.*
