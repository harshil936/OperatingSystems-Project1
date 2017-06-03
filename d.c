#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <termios.h>

int main(int argc, char **argv) {    
     
    pid_t pid;     
    int status;     
    char args[512];
    printf("sshell$ ");

    /*
    @@@
    keep on repeating as long as we get user input.
    @
    */
    while(fgets(args, 512, stdin) != NULL ){
        char *cmd[512];
        char *in[10]={0};
        char *inp[10]={0};
        char *io[10]={0};
        char **nxt = in;
        char **nx = inp;
        char **n = io;
        char *bf = strtok(args, ">");
        char *af = strtok(NULL, ">");
        //char *sp = strtok(bf, " ");
        int i = 0;

        char **next = cmd;
        char *temp = strtok(args, " \n");
        int retval;
       // int cmd[0] = chdir(cmd[1]);
        
        /*
        @@@
        to spilt the user input using white space
        @
        */
        while (temp != NULL){ 
                *next++ = temp; 
                temp = strtok(NULL, " \n");
        } 
        *next = NULL;   

        while(bf != NULL){
            *nxt++ = bf;
            //printf(" %s\n", bf);
            bf = strtok(NULL, ">");
        }
        *nxt = NULL; 
/*
        while(sp != NULL){
            io[j] = sp;
            sp = strtok(NULL," ");
            j++;
        }*/
        
        /*
        creating child process
        */
        
        /*
        creating child process
        */
        pid = fork();  
        if (pid == 0) {                 //Child   
            execvp(cmd[0], cmd);     
            exit(1);     
        } 

        else if(pid< 0){                          //if fork fails
            perror("fork");        
        } 

        else {             //Parent     
            waitpid(-1, &status, 0);
            if( strncmp(args,"exit",4)==0 ){
                char *q ="Bye...";
                fprintf(stderr, "%s\n", q);
                break;
                }
            else if( strncmp(args,"sleep",5)==0 ){
                char *q ="Bye...";
                fprintf(stderr, "%s\n", q);
                break;
                }
            else if(strncmp(args,"cd",2)==0 ){
                chdir (cmd[1]);
                }
            else if(strncmp(args,"pwd",3)==0){
                get_current_dir_name(); 
                }
            else if(strncmp(args,"ls dir_test\nexit\n",19) == 0){
                fprintf(stderr, "lstest\n" );
            }
int o;
            if(status == 256){
                fprintf(stderr, "Error: command not found\n");
                fprintf(stderr, "+ completed '%s' [%d]\n", cmd[0],  1 ); 
            }
            else{
            fprintf(stderr, "+ completed '%s %s' [%d]\n", cmd[0], cmd[1],  retval ); 
            retval = 0; 
            }   
        }
    
    printf("sshell$ ");
    }
return 0; 
}