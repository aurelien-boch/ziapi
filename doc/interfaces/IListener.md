# IListener

### Description
The IListener interface defines `Listener` methods that must be implemented.
The goal of this class is listen for new connections and wait for full packet before calling the callback method,
that was provided using the `onPacket()` method.

You are free to chose how will the internal listener work (as long as it matches your client implementation obviously).

###  Packet Decryption
If the packet is encrypted (using SSL / TLS for example) the listener must decrypt it to know when the packet is complete
and then send the decrypted version to the callback.

### Client lifetime
The listener is responsible for the lifetime of the `client`. It MUST it close it when necessary (for example:
in HTTP protocol, the `client` must be closed when the reply is sent, whereas in FTP protocol, the `client` must be closed
when the "close" command is received).

*note: in the text above, the `client` term is used, it stands for your IClient implementation which contains a socket.
However, in some cases it can be something else than a socket.*
