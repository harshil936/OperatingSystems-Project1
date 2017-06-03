# UNIX Shell implementation 

As a group project, we met on regular basis to work on this project. We basica- </br>
lly followed the given strategy and tried implementing the program in sequential </br>
 phases. This project was definitely hard for us because none of us had any expe- </br>
 rience with C language. For implementation, we started by running each test </br>
 from the different phases in an actual Unix shell. Our design was to include </br>
 all the code in the main function and once we have a working code then break </br>
 it into functions to use them again. In order to use user input as a string we</br>
 had tried using string concatenation with the path /usr/bin to change it to </br>
 /usr/bin/date and pass it in as a argument in execl function. Later on, we fig-</br>
 ured out this is causing Segmentation Fault. So, we used tokens and execvp for</br>
 our phase 1 and 2. We created a variable of data type pid_t and assigned it to</br>
 the fork process. We made a block of if statements that determined what to do</br>
 if the fork succeeds or fails. If succeeded, the fork creates the child process</br>
and we are able to output the date using the exec command we are able to printf</br>
the date. In order to read user input we used a while loop with the fgets comm-</br>
and to break up the commands into tokens. We then created the fork and were able</br>
to create an array to store the commands and then execute them using the execvp</br>
function. We made sure to fprintf the output using stderr. In order to handle</br>
arguments we had to take in consideration the spaces between the commands and</br>
their arguments which we broke up into tokens using the white space. We made</br>
sure to use waitpid() always to wait for the given process to finish. We were</br>
able to identify commands that needed to be handled such as "cd" by using the</br>
strncmp function within the handling of the fork. The two commands 'q' and 'cd'</br>
are handled in the parent as these commands are handled outside the usr/bin. We</br>
used chdir for the 'cd' command in order to navigate to the given directory that</br>
the user inputs and handled the command 'q' using break in order to break out of</br>
the shell. We once again used tokens to break up the command line. We used </br>
strntok to break up the parts aside the ">" character. 	</br>

## Resources we found online:</br>

http://www.cplusplus.com/reference/cstring/strchr/ 
http://stackoverflow.com/questions/15798450/open-with-o-creat-was-it-opened-or-created
http://stackoverflow.com/questions/4785126/getlogin-c-function-returns-null-and-error-no-such-file-or-directory 
https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm
(To know the syntax of strchr C function)


