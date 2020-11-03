#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#define SHMSIZE 1000
int main() {
int tmp, shmid;
char* shptr;
char buffer[SHMSIZE];//x' 1 char è grosso  1 byte

shmid=shmget(IPC_PRIVATE,SHMSIZE,IPC_CREAT|0600);//shmem definita così

printf("\n L id del segmento di shm creato e: %d\n", shmid);
shptr = (char*)shmat(shmid,0,0);
printf("Immetti una stringa: \n");
fgets(buffer,SHMSIZE,stdin);
strncpy((char*) shptr,buffer,SHMSIZE);
printf("Fatto.\n");
shmdt(shptr);
exit(0);

}
