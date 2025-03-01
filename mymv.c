#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>  // For PATH_MAX

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    int Fd_Input, Fd_Output, num_read;
    
    /* Ensure the correct usage */
    if (argc != 3) {
        printf("Usage: %s <InputFile> <DestinationDirectory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /* Open the input file */
    Fd_Input = open(argv[1], O_RDONLY);
    if (Fd_Input == -1) {
        printf("Error: Couldn't open the input file");
        exit(EXIT_FAILURE);
    }
    
    /* Extract the basename from the input file path */
    char *filename = strrchr(argv[1], '/');
    if (filename != NULL) {
        filename++;  // Skip the '/' character
    } else {
        filename = argv[1];  // argv[1] contains only the filename
    }
    
    /* Construct the output file path: <DestinationDirectory>/<basename> */
    char outFilePath[PATH_MAX];
    if (snprintf(outFilePath, sizeof(outFilePath), "%s/%s", argv[2], filename) >= sizeof(outFilePath)) {
        printf("Error: Destination path too long\n");
        exit(EXIT_FAILURE);
    }
    
    /* Open the output file */
    Fd_Output = open(outFilePath, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (Fd_Output == -1) {
        printf("Error: Couldn't open the output file");
        exit(EXIT_FAILURE);
    }
    
    /* Read from the input file and write to the output file */
    while ((num_read = read(Fd_Input, buf, BUF_SIZE)) > 0) {
        if (write(Fd_Output, buf, num_read) != num_read) {
            printf("Error: Couldn't write the whole buffer");
            exit(EXIT_FAILURE);
        }
    }
    if (num_read == -1) {
        printf("Error: Couldn't read");
        exit(EXIT_FAILURE);
    }
    
    /* Close the input file */
    if (close(Fd_Input) < 0) {
        printf("Error: Couldn't close the input file");
        exit(EXIT_FAILURE);
    }
    
    /* Close the output file */
    if (close(Fd_Output) < 0) {
        printf("Error: Couldn't close the output file");
        exit(EXIT_FAILURE);
    }
    
    /* Delete the input file */
    if (remove(argv[1]) != 0) {
        printf("Error: Couldn't delete the input file");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}

