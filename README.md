# Unix-like Utilities in C

This repository contains custom implementations of common Unix utilities written in C. These implementations provide simplified versions of the standard utilities with basic functionality.

## Programs Included

## 1. mypwd.c
○ A simplified implementation of the `pwd` (print working directory) command.

### Compilation:
```bash
gcc mypwd.c -o mypwd.
```

### Usage : 

``` bash
./mypwd
```

### Example Output : 
```bash
Current working directory: /home/user/unix-utils
```


## 2. echo.c
○ A simplified implementation of the echo command that displays text.

### Compilation:
```bash
gcc myecho.c -o myecho
```

### Usage : 
``` bash
./echo "Hello World"
```
### Example Output : 
```bash
$ ./myecho Hello World
Hello World
```

## 3. copy.c
○ A simplified implementation for copying files (similar to cp).

### Compilation:
```bash
gcc mycopy.c -o mycopy
```
### Usage : 
``` bash
./copy source_file destination_file
```

### Example Output : 
```bash
$ ./mycopy file1.txt file2.txt
File successfully copied from file1.txt to file2.txt
```


## 4. mv.c
○ A simplified implementation for moving or renaming files (similar to mv).

### Compilation:
```bash
gcc mymv.c -o mymv
```
### Usage : 
``` bash
./mymv file destination_directory
```
### Example Output : 
```bash
$ ./mymv file.txt destination directory
File successfully moved from current directory to destination directory
```
