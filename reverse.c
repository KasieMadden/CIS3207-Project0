//Kasie E. Madden
//CIS 3207
//Professor John Fiore
//Assignment 0- Part B
//Date Created 2/01/2021

/*reverse.c will reverse line by line the contents  of an input
 * stdin -> stdout
 * stdin -> file
 * file -> file
 *
 * to reverse the contents a stack will be implement.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//References used to create a stack of stings:
//https://stackoverflow.com/questions/1919975/creating-a-stack-of-strings-in-c


// Stack structure for node
struct stackNode{
    char *data;
    struct  stackNode *next;

};//end of stackNode



struct stackHead{
    struct stackNode *head;
    size_t size;

};//end of stackHead

struct stackHead *newStack(void){
    struct stackHead *stack = malloc(sizeof *stack);
        if(stack){
            stack->head = NULL;
            stack->size = 0;
        }//end of if stack
        return stack;

}//end of *new()


//storing a copy of the string
char *copyline(char *string){
    char *temp = malloc(strlen(string)+1);
    if(temp){
        strcpy(temp, string);
    }
    return temp;

}// end of *cline

//push function
void push(struct stackHead *stack, char *value ){
    struct stackNode *entry = malloc(sizeof *entry);
    if(entry){
        entry->data = copyline(value);
        entry->next = stack->head;
        stack->head = entry;
        stack->size++;
    }//end of if(entry)

}//end push

char *top( struct stackHead *stack){
    if(stack && stack->head){
        return stack->head->data;

    }//end of if
    else{
        return NULL;
    }//end of else

}//end of top


//pop function
void pop(struct stackHead *stack){
    if((*stack).head != NULL){
        struct stackNode *temp = stack->head;
        stack->head = stack->head->next;
        free(temp->data);
        free(temp);
        stack->size--;
    }//end of if
}




int main(int argc,  char *argv[]){

    //if no args passed (1)=  stdin -> stdout
    if(argc == 1){

        //initializing for s
        struct stackHead *sp = newStack();
        char *string = NULL;
        size_t buff = 0;

        printf("Input Sting to be reversed: \n");
        getline(&string, &buff ,stdin);


        while(strcmp(string, "\n") != 0){
            push(sp, string);
            getline(&string, &buff ,stdin);

        }//end of while

        printf("Output is:\n");
        while(top(sp) != NULL) {
            printf("%s",top(sp));
            pop(sp);
        }
        exit(0);


    }//end of if for argc 1

    //pass (2) args = file -> stdout
    if(argc == 2){

        FILE *fp = fopen(argv[1],"r");
        struct stackHead *sp = newStack();
        char *string = NULL;
        size_t buff = 0;

        if( fp == NULL){
            printf("Error: Cannot open file\n");
            exit(1);
        }//end of if for error


            while (getline(&string, &buff, fp) != -1) {
                printf("%s", string);
                push(sp, string);
                //getline(&string, &buff, stdin);
            }//end of while

            printf("Output is:\n");
            while (top(sp) != NULL) {
                printf("%s", top(sp));
                fputs(top(sp), fp);
                pop(sp);
            }//end of while

            fclose(fp);
            exit(0);





    }//end of argc 2


    //If (3) args passed = file to file
    if(argc == 3){

        FILE *fp = fopen(argv[1],"r");
        FILE *tp = fopen(argv[2], "w");
        struct stackHead *sp = newStack();
        char *string = NULL;
        size_t buff = 0;

        if( fp == NULL){
            printf("Error: Cannot open file\n");
            exit(1);
        }//end of if for error


        while (getline(&string, &buff, fp) != -1) {
            printf("%s", string);
            push(sp, string);
            //getline(&string, &buff, stdin);
        }//end of while

       // printf("Output is:\n");
        while (top(sp) != NULL) {
            printf("%s", top(sp));
            fputs(top(sp), tp);
            pop(sp);
        }//end of while

        fclose(fp);
        exit(0);


    }//end of argc3



    // (>3) is an error
    else if(argc > 3){
        fprintf(stderr,"usage: reverse <input> <output>/n");
        exit(1);

    }//end of argc >3
    return 0;

}// end of main

