# Watchdog

## Description
This program is supposed to detect any faulty, unresponsive and unpredictable states of other programs in our ChadChat messenger application. 
When it detects such states, it deals with them appropriately (detecting, killing and/or restarting threads).  
The Watchdog component consists of two subcomponents - LifeMonitor and DeathManager: 
  - LifeMonitor is responsible for running the watchdog timer, checking the status of a thread and starting the DeathManager. 
  - DeathManager is responsible for killing, restarting, handling unresponsive states and making sure that the thread is properly killed.

To make a connection to the components that the watchdog is supposed to monitor, we are using an IPC protocol (!!!).

## Class diagram
The Watchdog component has its own class diagram. It can be found [here](https://trello.com/1/cards/64af1dbb0027475badc66ed4/attachments/64b2f171026ef3fe88ac2146/download/class_v2.png)

## Sequence diagram
The Watchdog component has a strict sequence of work. The diagram can be found [here](https://trello.com/1/cards/64b27008982c544d0c8eeadf/attachments/64b2717ba688d73b0a556f1e/download/sequence.png)

## How to compile
To compile the program, you will need to create new folder build with comand 
mkdir build 
then go to this folder and write 
cmake .. 
to run CMakeLists.txt
after that 
make 
to build the application executable file,then go to folder deploy and run application with comand
./watchdog

As  of now, no extra libraries are neccesary. This might change with the development of this program.
