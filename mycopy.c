#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024


int main(int argc , char * argv[]){

	char buf[BUF_SIZE];
	int Fd_Input , Fd_Output , num_read;

	/* Ensure the correct Usage */

	if(argc != 3){
		printf("Usage : %s (first file) (second file)\n" , argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Open the input file */

	Fd_Input = open(argv[1] , O_RDONLY);

	if(Fd_Input == -1){
		printf("Error : Couldn't open the Input file \n");
		exit(EXIT_FAILURE);
	}

	Fd_Output = open(argv[2] , O_CREAT | O_WRONLY | O_TRUNC , 0644);

	/* Open the output file */

	if(Fd_Output == -1){
		printf("Error : Couldn't Open the output file \n");
		exit(EXIT_FAILURE);
	}

	/* Reading the input file */

	while((num_read = read(Fd_Input , buf , BUF_SIZE)) > 0){

		/* Writing to the Output file */
		if(write(Fd_Output , buf , num_read) != num_read){
			printf("Error : Couldn't write the Whole buffer \n");
			exit(EXIT_FAILURE);
		}
	}


	if(num_read == -1){
		printf("Error : Couldn't read \n");
		exit(EXIT_FAILURE);
	}

	/* Closing Input file */

	if(close(Fd_Input) < 0){
		printf("Error : Couldn't close the Input file \n");
		exit(EXIT_FAILURE);
	}

	/* Closing Output file */

	if(close(Fd_Output) < 0){
		printf("Error : Couldn't close the Output file \n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
