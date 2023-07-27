
# SL Straylight

## Introduction

    This is a straylight version of the SL command.  

## Demo


## Dependency

    - ncurses  
    - PDCurses  

### Note

PDCurses builds v3.9 and includes the generated libraries and DLLs in this repository.  

## Setup

### For Windows

There is nothing in particular to install.  

### For Ubuntu 22.04

    sudo apt install build-essential  
    sudo apt install libncursesw6-dev  

## Build

### For Ubuntu 22.04
gcc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0  

    cd src
    cmake -S . -B build  
    cmake --build build  

### For windows 10 with WSL(Ubuntu 22.04)
Ninja + LLVM 16.0  

    cd src
    powershell.exe cmake -S . -B build -G "\"Ninja Multi-Config"\"  
    powershell.exe cmake --build build  

MSVC(Default)  

    cd src
    powershell.exe cmake -S . -B build  
    powershell.exe cmake --build build  

## How to use

1. Build this repository.  
2. Run the generated binary from the console.  
i.e, ./sl  

## Options

Options are available for this software according to several arguments.  
Only numerical values can be used as arguments.  
The following parameters are available.  

### 0

Default parameter. If no argument is specified, this value is used.  
Scroll through the default logo. See Demo No.1 for behavior.  

### 1

Display the color version of the logo.  
See Demo No.2 for behavior.  

### 99

Display the usage.  



