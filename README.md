# Watchdog

#Description
This program is supposed to detect any faulty, unresponsive and unpredictable states of other programs in our ChadChat messenger application. 
When it detects such states, it deals with them appropriately (detecting, killing and/or restarting threads).  
The Watchdog component consists of two subcomponents - LifeMonitor and DeathManager: 
  - LifeMonitor is responsible for running the watchdog timer, checking the status of a thread and starting the DeathManager. 
  - DeathManager is responsible for killing, restarting, handling unresponsive states and making sure that the thread is properly killed.

