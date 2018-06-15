 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
#include <fcntl.h>
#include "shared.h"

       int main(int argc, char *argv[])
       {
           int flags, opt, op,fd;
           int nsecs, tfnd;
	   int firstNumber, secondNumber, score;
	   char* type;
	  char* fileName;
		mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	
           while ((opt = getopt(argc, argv, "t:f:")) != -1) {
               switch (opt) {
               case 't':
		type=optarg;
                printf("Type = %s\n", type);
                   break;
		case 'f':
		fileName=optarg;
		printf("FileName: %s\n", fileName);
		break;
               default: /* '?' */
                   exit(EXIT_FAILURE);
               }
           }
	printf("Give me firstNumber \n");
	scanf("%d", &firstNumber);
	printf("FirstNumber: %d \n", firstNumber);

	printf("Give me secondNumber \n");
        scanf("%d", &secondNumber);
        printf("SecondNumber: %d \n", secondNumber);
	if(type[0] == '+'){
		printf("Adding numbers \n");
		score = firstNumber + secondNumber;
	} else if(type[0] == '-'){
		  printf("Substracting numbers \n");
                score = firstNumber - secondNumber;
	}else if(type[0] == '*'){
		  printf("Multiplying numbers \n");
                score = firstNumber * secondNumber;
	}

	save(fileName, score, type);

	/*
	for library:
	1.create sth.h file with interface of function like shared.h
	2.create sth.c file with implementation of sth.h(needs to be imported) like shared.c
	3.compile sth.c eq:  			gcc -c shared.c -o libshared.so
	4.compile f.c and link sth.so eq: 	gcc f.c libshared.so -o f	
	5.import in f.c sth.h and use it's functions

        */
           exit(EXIT_SUCCESS);
       }

