# Unix-like Utilities in C

This repository contains custom implementations of common Unix utilities written in C. These implementations provide simplified versions of the standard utilities with basic functionality.

## Programs Included

**1. mypwd.c**  
A simplified implementation of the `pwd` (print working directory) command.

**Compilation:**  
```bash
gcc -o mypwd mypwd.c
Usage:

bash
Copy
Edit
./mypwd
Example Output:

sql
Copy
Edit
Current working directory: /home/user/unix-utils
2. myecho.c
A simplified implementation of the echo command that displays text.

Compilation:

bash
Copy
Edit
gcc -o myecho myecho.c
Usage:

bash
Copy
Edit
./myecho [string to echo]
Example Output:

bash
Copy
Edit
$ ./myecho Hello World
Hello World
3. mycopy.c
A simplified implementation for copying files (similar to cp).

Compilation:

bash
Copy
Edit
gcc -o mycopy mycopy.c
Usage:

bash
Copy
Edit
./mycopy source_file destination_file
Example Output:

bash
Copy
Edit
$ ./mycopy file1.txt file2.txt
File successfully copied from file1.txt to file2.txt
4. mymv.c
A simplified implementation for moving or renaming files (similar to mv).

Compilation:

bash
Copy
Edit
gcc -o mymv mymv.c
Usage:

bash
Copy
Edit
./mymv source_file destination_file
Example Output:

bash
Copy
Edit
$ ./mymv old_name.txt new_name.txt
File successfully moved from old_name.txt to new_name.txt
Implementation Details
mypwd.c
This program uses the POSIX function getcwd() to retrieve the current working directory path.

myecho.c
This program iterates through command-line arguments and prints them with spaces in between.

mycopy.c
This program reads the content of a source file and writes it to a destination file using file I/O functions.

mymv.c
This program uses the rename() system call to move/rename files. If the source and destination are on different file systems, it falls back to copying the file and then deleting the original.

Compilation
To compile all programs at once, you can use:

bash
Copy
Edit
gcc -o mypwd mypwd.c
gcc -o myecho myecho.c
gcc -o mycopy mycopy.c
gcc -o mymv mymv.c
