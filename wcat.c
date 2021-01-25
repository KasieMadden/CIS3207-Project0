//Kasie E. Madden
//CIS 3207
//Professor John Fiore
//Assignment 0- Part A
//Date Created 1/25/2021


//wcat: This exercise is to build a simple version of the cat command.
//      This program will concatenate 2 more from files when called.

//standard library
#include<stdio.h>
#include<stdlib.h>

//start of the main function

//pass command lines
int main(int argc,  char *argv[]){

    //loop to invoke each file in turn
    int i;
    for(i = 1, i < argc; i++) {

        //create a file pointer to open and read file
        FILE *fp = fopen(argv[i],"r");

        //check if pointer is null
        if(fp == NULL) {

            //if null then print error message
            printf("Cannot open file\n");
            //exit with error code 1 when null
            exit(1);

        }//end of if

        // if true enter else loop

        //loop to read line by line until EOF.

        //close file

    }//end of for loop

                //exit program with code 0










}//end of main function

