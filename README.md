# 0x16. C - Simple Shell
## About
This is focused on how to code and execute C program and for partial fulfillment of simple_shell project. 
This project, `simple_shell`, is a custom implementation of a simple UNIX shell as a requirement to complete the first sprint in the ALX - Holberton school 12-month SE program. Taking a minimalistic approach, the following functions have been implemented: `access, execve, exit, fork, free, fstat, getline, malloc, perror, signal, stat, wait, write.

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All files were compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -         Wextra -pedantic -std=gnu89`
- Betty coding style is followed.
- The simple shell has no known memory leaks.

##Installation
To run this shell locally, you need to have GCC installed on your machine.

Clone this repository and navigate to the project folder:
git clone https://github.com/NatholiR/simple_shell.git
cd simple_shell
Compile the files into an executable using the GCC compiler:
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
Run the executable file:
./hsh

#Correct Betty error
sed -i 's/^[ \t]*//' <your file>
sed -i 's/[[:space:]]*$//' <your file>

## Mandatory Tasks
 - 0. README, man, AUTHORS
 - 1. Betty would be proud
 -  2. Simple shell 0.1
 -  3. Simple shell 0.2
 -  4. Simple shell 0.3
 -  5. Simple shell 0.4
 -  6. Simple shell 1.0
 -  7. What happens when you type `ls -l \*.c` in the shell
## Advanced Tasks
 -  8. Test suite
 -  9. Simple shell 0.1.1
 -  10. Simple shell 0.2.1
 -  11. Simple shell 0.4.1
 -  12. Simple shell 0.4.2
 -  13. setenv, unsetenv
 -  14. cd
 -  15. ;
 -  16. && and ||
 -  17. alias
 -  18. Variables

## Bugs
No known bugs exists within the program as of this writing.

## Authors
Ahmed Seid <kedi3340@gmail.com>
Natnael Abera <nathiabera@gmail.com>

## License
Given the open source nature of the project, no special licenses or license whatsoever is needed to use, modify, and redistribute the simple_shell program.

