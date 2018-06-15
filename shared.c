#include "shared.h"
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
#include <fcntl.h>

void save(char* fileName, int score, char* type){
	int fd;
	 mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	 fd = creat(fileName, mode);
        if(fd != -1){
        printf("Created and saved to file: %s\n", fileName);
                FILE *f = fopen(fileName, "w");
                fprintf(f, "Score of %s is %d \n", type, score);
                fprintf(f, "PID = %d \n", getpid());
        }




}
