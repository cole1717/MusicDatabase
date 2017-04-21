Cole Bush and Tyler McCarthy

Manage music with MyMusic!

Qt Creator and the necessary modules/plugins will be installed if you go to this link and download Qt Open Source: https://www.qt.io/#
You also need MySQL Workbench from: https://dev.mysql.com/downloads/workbench/ 

To setup and install: 
Download and install Qt Creator / Qt 5.7 from the first link.
Download and install MySQL Workbench from the second link.
Open MySql Workbench and run the createMusicDB.sql script we uploaded. Make sure the Sql server username and password is known.
Open Qt Creator and import the project file. 
In the connector.h file, change lines: “db.setUserName(“user”);” and “db.setPassword(“pass”);” to what the username and password for the local Sql server is.
With the Sql Server running, build/run the application.
