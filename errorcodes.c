/********************************************************
*	"errorcodes.c"										*
* 	TODO replace occurrences of printMsg() with fatal()	*
*	Provides a helper function to print error messages.	*
*	See "errocodes.h" for the actual error codes.		*
********************************************************/
#include <stdio.h>
#include "errorcodes.h"
#include <stdlib.h>

void 	printMsg(int);
void	fatal(const char*);

void printMsg(int errorCode){
	/*
		Prints the message corresponding to an error code.
	*/
	switch (errorCode){
		case ERR__FILE_OPEN:
			printf("File access error.\n");
			break;
		case ERR__MEMORY_ALOCATION:
			printf("Memory allocation error.\n");
		default:
			printf("There was an error.\n");
			break;
	}
}

void fatal(const char* message){
	/*
		Prints a message and exits terminates the program.
		Closes all open i/o streams befre exiting.
	*/
	printf("%s\n", message);
	fflush(NULL);			//flushes all i/o streams.
	exit(EXIT_FAILURE);
}
