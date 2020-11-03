#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMSIZE 100

int main(int argc, char* argv[]) {
int shmid;
char* shptr;
char buffer[SHMSIZE];
if (argc != 2) { printf("Mi serve l id \n"); exit(1);}
shmid = atoi(argv[1]);
shptr = (char*)shmat(shmid,0,0);
strncpy(buffer,shptr,SHMSIZE);
buffer[100]=0;
printf("Nella memoria condivisa c'e':\n%s\n",buffer);
shmdt(shptr);
exit(0);
}
