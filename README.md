<div id="header" align = center>
  <img src="https://github.com/Javisanchezf/media/blob/main/pc-gif.webp" width="200"/>
</div>

<h1 align = center>42 Malaga Minitalk</h1>

> School 42 Málaga cursus project.

This repository contains all archives for the project __minitalk__ in the __School 42 Málaga core cursus__.

<h2 align = center>
	<a href="#about">About</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instuctions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
	<span> · </span>
	<a href="#license">License</a>
</h2>

## About

The Minitalk project is designed to test your ability to communicate between two processes using signals. The project consists of two programs: the server and the client. The server program waits for incoming signals from the client program and then decodes them to reconstruct a message. The client program takes a string as input, converts it to binary code, and sends it bit by bit to the server using signals.
[You can find more information in the subject](https://github.com/Javisanchezf/42Malaga-pdfs/blob/main/minitalk_subject.pdf).

The code in this repository follows [the rules of the Norminette](https://github.com/Javisanchezf/42Malaga-pdfs/blob/master/norme.pdf).

## Requirements
The project is written in __C language__ and needs:
- Compiler `gcc`.
-  The following  standard libraries:
	- `<stdlib.h>`
	- `<unistd.h>`
	- `<signal.h>`
- Software development tool `GNU Libtool`.

## Instructions

### 1. Download the repository

To download the repository, go to the console and run:
```
git clone --recursive https://github.com/Javisanchezf/42Malaga-minitalk.git
cd 42Malaga-minitalk
```

### 2. Compiling the library

To compile the library, go to its path and run:

```
make
```

### 3. Cleaning all binary (.o) executable files (.a) and the program

To delete all files generated with make, go to the path and run:
```
make fclean
```

### 4. Using it


To use the programs, start the server program in one terminal window:

```
./server
```
The server will then output its process ID (PID) to the console. Keep this window open, as the PID is needed to start the client program.

In another terminal window, start the client program, passing the server's PID as an argument:
```
./client [server PID] [message]
```
Replace [server PID] with the PID outputted by the server program, and [message] with the message you want to send to the server. The message can only contain ASCII characters.

The client program will then send the message to the server, which will decode it and output it to the console.



## Testing
To test the program, you can try sending different messages from the client to the server and see if they are correctly decoded. You can also try sending messages with special characters or messages that exceed the maximum length, to see how the programs handle these cases.

## License
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).

You are free to:
* Share: copy and redistribute the material in any medium or format.
* Adapt: remix, transform, and build upon the material.

Under the following terms:
* Attribution: You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
* NonCommercial: You may not use the material for commercial purposes.
* ShareAlike: If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

<h3 align = right>Share the content!</h3>

[<img src="https://github.com/Javisanchezf/media/blob/main/whatsapp-icon.png" width="50" height="50" align = right></img>](https://api.whatsapp.com/send?text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.%20%0ahttps://github.com/Javisanchezf/42Malaga-minitalk)
[<img src="https://github.com/Javisanchezf/media/blob/main/telegram-icon.webp" width="50" height="50" align = right></img>](https://t.me/share/url?url=https://github.com/javisanchezf/42Malaga-minitalk&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.)
[<img src="https://github.com/Javisanchezf/media/blob/main/twitter-icon.png" width="50" height="50" align = right></img>](https://twitter.com/intent/tweet?url=https://github.com/Javisanchezf/42Malaga-minitalk&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github)
[<img src="https://github.com/Javisanchezf/media/blob/main/linkedin-icon.png" width="50" height="50" align = right></img>](https://www.linkedin.com/sharing/share-offsite/?url=https://github.com/javisanchezf/42Malaga-minitalk)