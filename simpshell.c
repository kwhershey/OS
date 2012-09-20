#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <string.h>

int main(){
	while(1){
		char* command;
		char* word;
		char *param[128];
		printf("%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));
		command=readline(NULL);
		word = strtok(command," ");
		int index=0;
		while(word != NULL){
			param[index]=word;
			word=strtok(NULL," ");
			index++;	
		}
		param[index]=NULL;
		if(fork()!=0){
			waitpid(-1,0);
		}else{
			execvp(command,param);
		}
	}
	return 0;
}
