#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int exit_flag = 0;
char completeflag = '0';

int main(int argc, char *argv[]) 
{
    pid_t pid;     
    int status;     
    char args[512];
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
 
   /*
   if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", cwd);
   else
       perror("getcwd() error"); */
 
printf("Enter 'exit' to exit the Shell at anytime \n");
printf("Shell$ ");
while(fgets(args, 512, stdin) != NULL ){


        char *in[10]={NULL};
        char *inp[10]={NULL};
        char *io[10]={NULL};
        char **nxt = in;
        char **nx = inp;
        char **n = io;
        char *bf = strtok(args, ">");
        char *af = strtok(NULL, ">");
        char *sp = strtok(bf, " ");
        int i = 0, j = 0, k = 0;



        while(bf != NULL){
          *nxt++ = bf;
          printf(" %s\n", bf);
          bf = strtok(NULL, ">");

        }
        *nxt = NULL; 

        while(sp != NULL){
          io[j] = sp;
          sp = strtok(NULL," ");
          j++;
           // *n++ = sp;
            //printf(" %s\n", sp);
            //sp = strtok(NULL, ">");
        }
        //*n = NULL; 

       /* while(af != NULL){
            *nx++ = af;
            printf(" %s\n", af);
            af = strtok(NULL, ">");
        }
        *nx = NULL;  */

      /*  while(sp!=NULL) {
          io[j] = sp;
          sp = strtok(NULL," ");
          i++;
          } */
        int fd;
        fd = open(af, O_CREAT | O_RDWR, 0644);
        write(fd, bf, sizeof(bf));
        close(fd);

/*
          pid_t pid = fork();

        if(pid == -1) {
          perror("fork");
          completeflag = '1';
         // return;
        }

        else if(pid == 0) {
        fd = open(af, O_CREAT | O_RDWR, 0644);
        if(fd == -1) {
        write(STDOUT_FILENO, "Error: no output file\n", 22);
        completeflag = '1';
        }
        dup2(fd,1);
        close(fd);
        execvp(io[0],io);
      }

      else wait(NULL);
*/

     /*   while(new != NULL){
            *nxt++ = new;
            new = strtok(NULL, ">");
            i++;
        }
        *nxt = NULL; */



   }
        
    return 0;
}