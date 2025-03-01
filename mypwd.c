#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100


int main(int argc , char * argv[]){

	char buf[BUF_SIZE];

	if(argc > 1){					
	  /* Ensure that no extra command line arguments are provided */
		printf("Usage : %s\n " , argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Getting the current working directory */
	if(getcwd(buf , BUF_SIZE) == NULL){
		printf("Error : Couldn't get the current working directory ");
                exit(EXIT_FAILURE);
	}

	/* Write the following current working directory */
	if(write(STDOUT_FILENO , buf  , strlen(buf) ) < 0){
		printf("Error : Couldn't write \n");
		exit(EXIT_FAILURE);
	}

	/* Write Newline */
	if(write(1 , "\n" , 1) < 0){
		printf("Error : Couldn't write a new line");
		exit(EXIT_FAILURE);
	}
	return 0;
}
