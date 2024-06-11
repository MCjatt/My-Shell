/*Author = Abhijit Mahal
student id = 21735106

DCU Academic Integrity Declaration: 

I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.

I have read and understood the DCU Academic Integrity and Plagiarism Policy. 

I accept the  penalties that may be imposed should I engage in practice or practices that breach this policy.
I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. 

Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void change_directory(char* arg) {
    if (arg == NULL) {
        char* cwd = getcwd(NULL, 0);
        printf("%s\n", cwd);
        free(cwd);
    } else {
        if (chdir(arg) == -1) {
            printf("Error: Directory '%s' not found\n", arg);
        } else {
            char* cwd = getcwd(NULL, 0);
            setenv("PWD", cwd, 1);
            free(cwd);
        }
    }
}

void clear_screen() {
    system("clear");
}

void list_directory(char* arg) {
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

void print_environment() {
    extern char **environ;
    char **envp = environ;
    while (*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }
}

void print_message(char *message) {
    printf("%s\n", message);
}

void display_help() {
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

void pause_execution() {
    printf("Press Enter to continue..");
    getchar();
}

void exit_shell() {
    exit(0);
}

