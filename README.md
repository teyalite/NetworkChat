# Network Chat
This project is about building a network chat software. It will allow local network connection and also connections through internet.
For this project I will use TCP/IP protocol to make sure that a message is entirely sent to the destination.
The project will be based on the model Client/Server.

## How Chat works:
For now, i will keep some functionalities simple, i may make them more complex in the future.
A client send a message to the server.
The server distribute the message to all connected clients and it will be shown on their windows.
[Here are some screenshots of the applications](https://github.com/teyalite/NetworkChat/tree/main/ScreenShots).

## Tests
To run test run the command:
```
cd Client/tests
```
After that follow the qt tutorial on executing tests [here](https://doc.qt.io/qt-5/qttestlib-tutorial1-example.html).
After running tests successfully it should show something similar to:
![tests](https://github.com/teyalite/NetworkChat/blob/main/ScreenShots/running%20tests.png)