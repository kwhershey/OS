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
		if(fork()!=0){
			waitpid(-1,0);
		}else{
			if(execvp(command,param)){
				printf("Command not found\n");
				break;
			}
		}
	}
	return 0;
}
