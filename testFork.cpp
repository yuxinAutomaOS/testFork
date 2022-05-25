#include <cstdio>
#include <thread>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("Testing Fork working. <2022.0524.0915>\n");

    __pid_t pid = fork();
    if( pid < 0 ) {
        printf("Fork new process failed.\n");
        return -100;
    }
    else if( pid == 0 ) {
        printf("Fork new process OK (pid=%d)\n", getpid());
        sleep(5);
        printf("Child-process Over.\n");    
    }
    else {
        printf("ParentID(%d) ==> ChildID(%d).\n", getpid(), pid);

		while(true) {
			sleep(2);

			int status = 0;
			if( waitpid(pid, &status, WNOHANG) > 0 )	
				break;		//sub-process overed.
		}

        printf("Parent-process Over.\n");        
    }

    return 0;
}

