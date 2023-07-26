
# sl Straylight

## Introduction

    

## Demo

## Dependency

    - ncurses  
    - PDCurses  

## Setup

### For Windows

    

### For Ubuntu 22.04

    sudo apt install build-essential  
    sudo apt install libncursesw6-dev  

## Build

### For Ubuntu 22.04

    - gcc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0  

    cmake -S . -B build  
    cmake --build build  


### For windows 10

    - Ninja + LLVM 16.0  

    powershell.exe cmake -S . -B build -G "\"Ninja Multi-Config"\"  
    powershell.exe cmake --build build  


    - MSVC(Default)  

    powershell.exe cmake -S . -B build  
    powershell.exe cmake --build build  



