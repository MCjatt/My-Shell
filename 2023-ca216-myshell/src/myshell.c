/*Author = Abhijit Mahal
student id = 21375106

DCU Academic Integrity Declaration: 

I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.

I have read and understood the DCU Academic Integrity and Plagiarism Policy. 

I accept the  penalties that may be imposed should I engage in practice or practices that breach this policy.
I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. 

Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.*/


#include "myshell.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

// Changes the current working directory
void cd(char* arg) {
    if (arg == NULL) {
        // If no argument is provided, print the current working directory
        char* cwd = getcwd(NULL, 0);
        printf("%s\n", cwd);
        free(cwd);
    } else {
        // If an argument is provided, change to that directory
        if (chdir(arg) == -1) {
            printf("Error: Directory '%s' not found\n", arg);
        } else {
            // Update the PWD environment variable to reflect the new working directory
            char* cwd = getcwd(NULL, 0);
            setenv("PWD", cwd, 1);
            free(cwd);
        }
    }
}

// Clears the terminal screen
void clearfunction() {
    system("clear");
}

// Lists the contents of a directory
void dir(char* arg) {
    if (arg == NULL) {
        arg = ".";
    }
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(arg)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        printf("Error: Directory '%s' not found\n", arg);
    }
}

// Prints all environment variables
void environfunction() {
    extern char **environ;
    char **envp = environ;
    while (*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }
}

// Prints a message to the console
void echo(char *message) {
    printf("%s\n", message);
}

// Displays help information from the README.md file
void help() {
    char *filename = "README.md";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen() error");
    } else {
        char line[MAX_COMMAND_LENGTH];
        while (fgets(line, MAX_COMMAND_LENGTH, file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    }
}

// Pauses the shell until the user hits enter
void pause_shell() {
    printf("Press Enter to continue..");
    getchar();
}

// Exits the shell
void quit() {
    exit(0);
}
