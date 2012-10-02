#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <string.h>

int main(){
	//to quit my shell
	//My while loop condition.  Allows me to test for "exit"
	int exit=1;
	while(exit ){
		char* command;
		char* word;
		char *param[128];
		//prints the username: working dir $ line
		printf("%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));
		//readline returns NULL if it encounders EOF,
		//so the if tests for ctrl-d
		if((command=readline(NULL))==NULL){
			exit=0;
			printf("\n");
			break;
		}
		//tests for the exit string to exit the shell
		if(strcmp(command,"exit")==0 ){
			exit=0;
			break;
		}
		//this while loop uses strtok to parse in the parameters
		//to the param array.
		word = strtok(command," ");
		int index=0;
		while(word != NULL){
			param[index]=word;
			word=strtok(NULL," ");
			index++;	
		}
		//NULL terminates the parameter array as required by execvp
		param[index]=NULL;
		//the main action.  This forks the processes, the parent waits
		//for the child to finish before continuing
		//if the function is cd, we want to change directories of the parent,
		//so do that instead of forking a child.
		if(strcmp(param[0],"cd")==0){
			chdir(param[1]);
		}else{
			if(fork()!=0){
				waitpid(-1,0);
			}else{
				if(execvp(command,param)){
					printf("Command not found\n");
					break;
				}
			}
		}
	}
	return 0;
}
