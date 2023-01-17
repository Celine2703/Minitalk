MINITALK 42

This project contains 2 programs that communicates through UNIX signals.

How to run these programs :

    make
    
First, run the server program

    ./sever
    
The PID of this program will be display. You can then run the client program

    ./client PID_of_server " string i want to send to the server"
   
The string will be displayed by the client.
You can run the client program as many times as you want.

If you want to exit it properly, send the string "EXIT" to the server through the client.
