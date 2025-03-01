#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Ensure the correct Usage of echo */
    if (argc == 1) {
        printf("Usage : %s   String  \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {

	/* Writing the given String */
        if (write(STDOUT_FILENO, argv[i], strlen(argv[i])) < 0) {
            printf("Error : Couldn't write\n");
            exit(EXIT_FAILURE);
        }

	/*Writing Space between the strings*/

	if(write(STDOUT_FILENO , " " , 1) < 0){
		printf("Error : Couldn't write space \n");
		exit(EXIT_FAILURE);
	}
    }

    /* Writing Newline */
    if (write(STDOUT_FILENO, "\n", 1) < 0) {
        printf("Error : Couldn't write new line \n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

