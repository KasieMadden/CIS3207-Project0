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

#define max 100000



//start of the main function
int main(int argc,  char *argv[]){

    int i;
    char buff[max];

/**
    //wgrep to read in from a file
    //when argc <=1
    //when no command-line args print "wgrep: searchterm [file...]\n"
    if(argc <= 1){
        printf("\nwgrep: searchterm [file...]\n");
        exit(1);
    }//end of if


    //when argc =2
    for(i = 2; i < argc; i++){

        //create a file pointer to open and read file
        FILE *fp = fopen(argv[i],"r");

        //check if pointer is null
        //if null then print error message
        if( fp == NULL){
            printf("\nwgrep: cannot open file\n");
            exit(1);
        }//end of if for error

        else{
            //else fgets input line by line
            while(fgets(buff, max, fp) !=NULL) {

                //using srtsrt() to search the term and return it
                //starting array at index 1, using index 0 search term
                //will run until it is null
                if(strstr(buff,argv[1]) != NULL){

                    //%s used to print string. print buffer, holds content input
                    printf("%s\n", buff);

                }//end of if

            }//end of while

            //close file
            fclose(fp);
        }//end of else

        //exit with code 0
        exit(0);
    }//end of for argc = 2
**/
//******************************USING STANDARD INPUT***************************************************

    //using the same idea as for reading from a file
    //if argc >= 2 will accept input
    if(argc >= 2) {


        // fgets input line by line
        while(fgets(buff, max, stdin) !=NULL) {
            //using srtsrt() to search the term and return it
            //will run until it is null
            if(strstr(buff,argv[1]) != NULL) {

                printf("%s\n", buff);

            }//end  of if
        }//end of while

        //exit code
        exit(0);

    }//end of if

}//end of main function