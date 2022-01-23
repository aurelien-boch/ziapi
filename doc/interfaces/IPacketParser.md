# IPacketParser

### Description
The IPacketParser interface defines methods that `PacketParser` must implement.
The goal of the packet parser is to parse packets received as raw bytes and transform them to parsed requests.

### How it works
When the `parse` method is called, it may parse the request (can be an HTTP / HTTPS or even another protocol request
(such as FTP)) and fill a RequestDataType variable (provided in template) which will be returned.
