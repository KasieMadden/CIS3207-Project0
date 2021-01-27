//Kasie E. Madden
//CIS 3207
//Professor John Fiore
//Assignment 0- Part A
//Date Created 1/25/2021


//wgrep: searches for fixed strings or basic regular expressions; patterns

//standard library
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//start of the main function
int main(int argc,  char *argv[]){

    int i;
    char buff[max];


    //wgrep to read in from a file
    //when argc <=1
    //when no command-line args print "wgrep: searchterm [file...]\n"
    if(argc <= 1){
        printf("wgrep: searchterm [file...]\n")
        exit(1);
    }//end of if


    //when argc =2
    for(i = 2; i < argc; i++){

        //create a file pointer to open and read file
        FILE *fp = fopen(argv[i],"r");

        //check if pointer is null
        //if null then print error message
        if( fp = NULL){
            printf("wgrep: cannot open file\n")
            exit(1);
        }//end of if for error

        else{

            //else fgets input line by line'
            //using srtsrt() to search the term and return it

    //close file

    //exit with code 0
    exit(0);


        }//end of else

    }//end of for argc = 2








}//end of main function