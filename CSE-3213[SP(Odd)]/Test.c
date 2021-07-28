#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
#include <signal.h>
#include <sys/types.h>

int global_var;

void handler(int signo){
	if(signo == SIGINT) {
          printf("I am in child.\n");
          printf("hell yes");
	  global_var=0;
	}
}

void handler_two(int signo){
 if(signo==SIGINT){
  printf("I am in parent\n");
  return;
 }
}

void function(){
	pid_t pid=fork();
 	global_var = 1;
	if(pid==0) {
        signal(SIGINT,handler);
	while(1){
	 if(global_var == 0) return;	
	}
	}
	else {
        signal(SIGINT,handler_two);
        int status;
	int v = wait(&status);
        return;
	}
}

int main() {
	function();
	return 0;
}
