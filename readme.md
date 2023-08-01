
# SL Straylight

## Introduction

    This is a straylight version of the SL command.  

## Demo


## Dependency

    - ncurses  
    - PDCurses  
    - (Straylight)  

### Note

PDCurses builds v3.9 and includes the generated libraries and DLLs in this repository.  

## Setup

### For Windows

There is nothing in particular to install.  

### For Ubuntu 22.04

    sudo apt install build-essential  
    sudo apt install libncursesw6-dev  

### For Raspbian 11(bullseye)

    sudo apt install build-essential  
    sudo apt install libncursesw5-dev  

## Build

### For windows 10 with WSL(Ubuntu 22.04)
Ninja + LLVM 16.0  

    cd src
    powershell.exe cmake -S . -B build -G "\"Ninja Multi-Config"\"  
    powershell.exe cmake --build build  

MSVC(Default)  

    cd src
    powershell.exe cmake -S . -B build  
    powershell.exe cmake --build build  

### For Ubuntu 22.04
gcc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0  

    cd src
    cmake -S . -B build  
    cmake --build build  

### For Raspbian 11(bullseye)
gcc (Debian 10.2.1-6) 10.2.1 20210110  

    cd src
    cmake -S . -B build  
    cmake --build build  

## How to use

1. Build this repository.  
2. Run the generated binary from the console.  
i.e, ./sl  

## Options

Options are available for this software according to several arguments.  
Only numerical values can be used as arguments.  
Up to the second argument can be set.  
The following parameters are available.  

### First argument

Changes the mode of the scrolling logo.  

#### 0

Default parameter. If no argument is specified, this value is used.  
Scroll through the default logo. See Demo No.1 for behavior.  

#### 1

Display the color version of the logo.  
See below gif.  

#### 99

Display the usage.  
If this parameter is set, the second argument is ignored.  
See below image file.  

### Second argument

Enable flash.  
It will be very flashy and cool. Instead, your eyes will break down.  

#### 0

Flash OFF.  
This is default value.  

#### 1

Flash ON.  
See below gif.  
Break down your eyes!!  


