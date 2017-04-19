+#Information 

lly followed the given strategy and tried implementing the program in sequential
 phases. This project was definitely hard for us because none of us had any expe-
 rience with C language. For implementation, we started by running each test 
 from the different phases in an actual Unix shell. Our design was to include 
 all the code in the main function and once we have a working code then break 
 it into functions to use them again. In order to use user input as a string we
 had tried using string concatenation with the path /usr/bin to change it to 
 /usr/bin/date and pass it in as a argument in execl function. Later on, we fig-
 ured out this is causing Segmentation Fault. So, we used tokens and execvp for
 our phase 1 and 2. We created a variable of data type pid_t and assigned it to
 the fork process. We made a block of if statements that determined what to do
 if the fork succeeds or fails. If succeeded, the fork creates the child process
and we are able to output the date using the exec command we are able to printf
the date. In order to read user input we used a while loop with the fgets comm-
and to break up the commands into tokens. We then created the fork and were able
to create an array to store the commands and then execute them using the execvp
function. We made sure to fprintf the output using stderr. In order to handle
arguments we had to take in consideration the spaces between the commands and
their arguments which we broke up into tokens using the white space. We made
sure to use waitpid() always to wait for the given process to finish. We were
able to identify commands that needed to be handled such as "cd" by using the
strncmp function within the handling of the fork. The two commands 'q' and 'cd'
are handled in the parent as these commands are handled outside the usr/bin. We
used chdir for the 'cd' command in order to navigate to the given directory that
the user inputs and handled the command 'q' using break in order to break out of
the shell. We once again used tokens to break up the command line. We used 
strntok to break up the parts aside the ">" character. 	

+#Resources we found online:

http://www.cplusplus.com/reference/cstring/strchr/ 
http://stackoverflow.com/questions/15798450/open-with-o-creat-was-it-opened-or-created
http://stackoverflow.com/questions/4785126/getlogin-c-function-returns-null-and-error-no-such-file-or-directory

https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm
(To know the syntax of strchr C function)

http://stackoverflow.com/questions/8819800/how-to-read-file-from-local-directory-path

http://stackoverflow.com/questions/18927793/how-to-use-strtok
(To know what strtok function does)
http://stackoverflow.com/questions/17504122/taking-a-string-as-input-and-storing-them-in-a-character-array-in-c

http://stackoverflow.com/questions/34008206/how-to-create-a-new-text-file-in-c

http://stackoverflow.com/questions/16841365/why-is-chdir-not-successful

http://stackoverflow.com/questions/1293660/is-there-any-way-to-change-directory-using-c-language

http://stackoverflow.com/questions/16094814/implementing-cd-system-call-using-c-if-condition

http://man7.org/linux/man-pages/man2/open.2.html
