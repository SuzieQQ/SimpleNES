SimpleNES
=============


An NES emulator written in C++ for nothing but fun.

Roughly 40-50% of games should work (ie. games that use either no mapper or mappers 1, 2 ,3 ,4 (BUG),7 & 66 partial 11).
Added APU experimental works with the sdl2 library
in linux i have encountered a problem 
with apu enabled only the debug mode works 
and few games crash.

the build release gives a black screen maybe there is a bug in the apu.





Examples of games that have been tested to run (but NOT limited to):

(USA/Japan or World versions only i.e. NTSC compatible)

* Super Mario Bros.
* Contra
* Adventure Island
* Ninja Gaiden
* Wrecking Crew
* Megaman and Megaman 2
* Mario Bros.
* Donky Kong and Donkey Kong Jr.
* Battle City
* Paperboy
* Legend of Zelda
* Pacman
* Tennis
* Excitebike
* Nightmare Elm Street
* Cabal
* Battletoads
* Battletoads & Double Dragon
* Arch Rivals
* etc...
* 

[Here's](https://gist.github.com/amhndu/5b6da39ee06959d93dc706a0b165fb80) a big list of games that match the supported specs from SimpleNES.
(Unlike the list above, these aren't tested. Some may or may not work)


Screenshots
------------------------
![Screenshot 1](http://amhndu.github.io/screenshots/nes1.png)
![Screenshot 2](http://amhndu.github.io/screenshots/nes2.png)
![Screenshot 3](http://amhndu.github.io/screenshots/nes3.png)
![Screenshot 4](http://amhndu.github.io/screenshots/nes4.png)
![Screenshot 5](http://amhndu.github.io/screenshots/nes5.png)
![Screenshot 6](http://amhndu.github.io/screenshots/nes6.png)
![Screenshot 7](https://github.com/SuzieQQ/screennes/blob/main/nes7.png)
![Screenshot 8](https://github.com/SuzieQQ/screennes/blob/main/nes8.png)
![Screenshot 9](https://github.com/SuzieQQ/screennes/blob/main/nes9.png)
![Screenshot 10](https://github.com/SuzieQQ/screennes/blob/main/nes10.png)
![Screenshot 11](https://github.com/SuzieQQ/screennes/blob/main/nes11.png)

![Screenshot 12](https://github.com/SuzieQQ/screennes/blob/main/Metal%20Fighter-11.png)
![Screenshot 13](https://github.com/SuzieQQ/screennes/blob/main/Shockwave-11.png)
![Screenshot 14](https://github.com/SuzieQQ/screennes/blob/main/DBJAPAN-66.png)
![Screenshot 15](https://github.com/SuzieQQ/screennes/blob/main/Gundam-66.png)
![Screenshot 16](https://github.com/SuzieQQ/screennes/blob/main/URBANPOWER-2-66.png)

![Screenshot 17](https://github.com/SuzieQQ/screennes/blob/main/TEST-MAPPER-4-GAME-SCREEN/BONKS.png)
![Screenshot 18](https://github.com/SuzieQQ/screennes/blob/main/TEST-MAPPER-4-GAME-SCREEN/CONTRA.png)
![Screenshot 19](https://github.com/SuzieQQ/screennes/blob/main/TEST-MAPPER-4-GAME-SCREEN/Schermata%20del%202022-02-22%2003-54-56.png)
![Screenshot 20](https://github.com/SuzieQQ/screennes/blob/main/TEST-MAPPER-4-GAME-SCREEN/Schermata%20del%202022-02-22%2003-53-43.png)


Videos
------------
[YouTube Playlist](https://www.youtube.com/playlist?list=PLiULt7qySWt2VbHTkvIt9kYPMPcWt01qN)


Download
-----------
Executables:

[Windows 32-bit](https://www.dropbox.com/s/1gqhtbmvzo1ozsz/SimpleNES-win32.rar?dl=0)
[Linux 64-bit](https://www.dropbox.com/s/7eswcdektlkdz65/SimpleNES-linux64?dl=0)


Compiling
-----------

You need:
* SFML 2.0+ development headers and library
* C++11 compliant compiler
* CMake build system

Compiling is straight forward with cmake, just run cmake on the project directory with CMAKE_BUILD_TYPE=Release
and you'll get Makefile or equivalent for your platform, with which you can compile the emulator

For e.g., on Linux/OS X/FreeBSD:
```
$ git clone https://github.com/amhndu/SimpleNES
$ cd SimpleNES
$ mkdir build/ && cd build/
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make -j4    #Replace 4 with however many cores you have to spare
```

Running
-----------------

Just pass the path to a .nes image like

```
$ ./SimpleNES ~/Games/SuperMarioBros.nes
```
To set size of the window,
```
$ ./SimpleNES -w 600 ~/Games/Contra.nes
```
For supported command line options, try
```
$ ./SimpleNES -h
```

Controller
-----------------

Keybindings can be configured with keybindings.conf


Default keybindings:

**Player 1**

 Button        | Mapped to
 --------------|-------------
 Start         | Return/Enter
 Select        | Right Shift
 A             | J
 B             | K
 Up            | W
 Down          | S
 Left          | A
 Right         | D


**Player 2**

 Button        | Mapped to
 --------------|-------------
 Start         | Numpad9
 Select        | Numpad8
 A             | Numpad5
 B             | Numpad6
 Up            | Up
 Down          | Down
 Left          | Left
 Right         | Right


