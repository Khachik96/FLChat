     _____________________________                                                                                 |
    |  install   compiler    //   |                                                  |
    |_____________________________|                                                  |                                   |
c++ --                          sudo apt-get install g++                             |
                                                                                     |
fltk --                         sudo apt-get install libfltk1.3-dev                  |
                                sudo apt-get install libx11-dev                      |
                                sudo apt-get install fltk1.3-dev                     |
                                                                                     |
sqlite3 --                      sudo apt-get install sqlite3 libsqlite3-dev          |
                                sudo apt-get install sqlite3                         |
                                                                                     |
crypto algorithm --             sudo apt-get install libssh-gcrypt-dev               |
                                                                                     |
CSmtp                           sudo apt-get install libssl-dev                      |
                                https://packages.ubuntu.com/yakkety/libcrypto++-dev  |
_____________________________________________________________________________________|

    |============================|
    |  Flag compiler             |
    |============================|

fltk --                         fltk-config --compile test.cxx   

sqlite3--                       g++ main.cpp -lsqlite3


CSmtp                           g++ main.cpp -lssl -lcrypto

_____________________________________________________________________________________
