/*Author = Abhijit Mahal
student id = 21375106

DCU Academic Integrity Declaration: 

I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.

I have read and understood the DCU Academic Integrity and Plagiarism Policy. 

I accept the  penalties that may be imposed should I engage in practice or practices that breach this policy.
I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. 

Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>



void change_directory(char* arg);
void clear_screen();
void list_directory(char* arg);
void environfunction();
void echo(char* arg);
void display_help();
void pause_execution();
void exit_shell();
