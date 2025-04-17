#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    if (argc < 3 || argc > (9)) {
        printf(1, "usage: schedtest loops tickets1 [ tickets2 ... ticketsN ]\n");
        printf(1, "loops must be greater than 0\n");
        printf(1, "tickets must be greater than or equal to  10\n");
        printf(1, "up to 7 tickets can be provided\n");
    }
    int loopCount = atoi(argv[1]);
    int pids[7];
    int nProcs = argc -2;
    int i;
    for (i = 0; i < nProcs; i++)
    {
        int pid = fork();
        if (pid == 0) {
           while(1);
        } else {
            pids[i] = pid;
        }
    }
    for (i = 0; i < loopCount; i++)
    {
        ps();
        sleep(3);
    }
    for (i = 0; i < nProcs; i++)
    {
        kill(pids[i]);
    }
    for (i = 0; i < nProcs; i++)
    {
        wait();
    }
    exit();
}
