#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int exit_flag = 0;
char completeflag = '0';

void redirection(char* args, char *red1, char *red2) {

    int fd;
    pid_t pid;

    if(red1!=NULL) { // '>'
        int i = 0;
        char *redh=NULL, *redt=NULL, *redh_p=NULL;
        char *head[10]={NULL};

        redh = strtok(args,">"); //gets args before >
        redt = strtok(NULL," >"); //gets file name after >. Handles both '>' and ' '

        redh_p = strtok(redh," "); //separates arguments into command and sub-command ex) ls -al

        while(redh_p!=NULL) {
            head[i] = redh_p;
            redh_p = strtok(NULL," ");
            i++;
        }

        pid = fork();

        if(pid == -1) {
            perror("fork");
            completeflag = '1';
            return;
        }

        else if(pid == 0) {
            fd=open(redt, O_CREAT | O_RDWR, 0644);
            if(fd == -1) {
                write(STDOUT_FILENO, "Error: no output file\n", 22);
                completeflag = '1';
                return;
            }

            dup2(fd,1);
            close(fd);
            execvp(head[0],head);
        }

        else wait(NULL);
    }

    else { // '<'
        int i = 0;
        char *redh=NULL, *redt=NULL, *redh_p=NULL;
        char *head[10]={NULL};

        redh = strtok(args,"<"); //gets args before <
        redt = strtok(NULL,"< "); //gets file name after <. Handles both '<' and ' '

        redh_p = strtok(redh," "); //separates arguments into command and sub-command ex) ls -al

        while(redh_p!=NULL) {
            head[i] = redh_p;
            redh_p = strtok(NULL," ");
            i++;
        }

        pid = fork();

        if(pid == -1) {
            perror("fork");
            completeflag = '1';
            return;
        }

        else if(pid == 0) { //child
            fd=open(redt, O_RDONLY, 0644);
            if(fd == -1) {
                perror(redt);
                completeflag = '1';
                return;
            }

            head[i] = redt; //puts file name after sequence of arguments in the array

            //dup2(fd,1);
            close(fd);
            execvp(head[0],head);
        }

        else wait(NULL);

    }

}

int main(int argc, char **argv) {    
     
    pid_t pid;     
    char arr[512],complete[512];
    int status;     
    char args[512];
    char completeflag = '0';
    int exit_flag = 0;
    printf("Enter 'exit' to exit the Shell at anytime \n");
    printf("Shell$ ");

    /*
    @@@
    keep on repeating as long as we get user input.
    @
    */
    while(fgets(args, 512, stdin) != NULL ){

         
        char *cmd[512];
        char **next = cmd;
        char *temp = strtok(args, " \n");
        int retval;
        char *head, *head2[10], *red1=NULL, *red2=NULL;
        red1 = strchr(args,62); //check if ">" is included
        red2 = strchr(args,60); //check if "<" is included

       // redirection(cmd[0],red1,red2); 
        char *in[5];
        char **nxt = in;
        char *new = strtok(args, " ");
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

        while(new != NULL){
            *nxt++ = new;
            printf(" %s\n", new);
            new = strtok(NULL, ">");
        }
        *nxt = NULL; 
        
        /*
        creating child process
        */
        pid = fork();  
        if (pid == 0) {                 //Child   
            execvp(cmd[0], cmd); 
            exit(EXIT_FAILURE);  
        } 

        else if (pid > 0) {             //Parent 

            waitpid(-1, &status, 0);
            if( strncmp(args,"exit",4)==0 || strncmp(args,"exit ",5)==0 ){
                char *q ="Bye...";
                fprintf(stderr, "%s \n", q);
              break;
            }
            else if(strncmp(args,"cd",2)==0 ){
                int ret;
                ret = chdir (cmd[1]);
            }
            fprintf(stderr, " + completed '%s %s' [%d]\n", cmd[0], cmd[1], retval );
            retval = 0; 
            } 

        else {                          //if fork fails
            perror("fork");        
        }     
    char arr[512],complete[512];
    int i = 0, flag = 0;
    int input_char = 0;
    
    printf("Shell$ ");
    }
return 0; 
}
