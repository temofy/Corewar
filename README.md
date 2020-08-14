# Corewar
## About
> Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which
> two or more battle programs (called "warriors") compete for control of a virtual computer.
> These battle programs are written in an abstract assembly language called Redcode.

## Project Structure

This project consists of two parts:

+ Virtual Machine
+ Visualizer

You can find in the folder [vm_champs][champs] files with .cor extension which can be run in programm "corewar"

## How to clone
If you want to clone it, you can use the following command:

	git clone https://github.com/temofy/Corewar

## Installation
Clone repository and then go into the created directory and run the following command:

	make

## Usage

### `corewar`
	Usage: ./corewar [-a] [-dump N] [-vi] [-v N] [-n N] <champion.cor> <...>
	-a		: Print output from "aff"
	-dump N		: Dumps memory after N cycles then exits
	-dumpc N	: Dumps memory in color mode after N cycles then exits
	-n N		: set the champion number
	-vi		: visual mode
	-v N		: verbose
			- 1  :	Show opearions information
			- 2  :	Show cycles information
			- 3  :	Show lives information
			- 4  :	Show deaths information
			- 5  :	Show PC movement information
			- 30 :	Show all information

If you want to change resolution of a vizualize window, find file `vizualizator.h` in `Vizualizator` folder
and change the parameters `SCREEN_WIDTH` and `SCREEN_HEIGHT` to the ones you need. After that you will need to recompile project.
Run command `make new` in project's root folder or just `make` if you haven't done it yet.


	
