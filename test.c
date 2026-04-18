#include <unistd.h>
#include <stdio.h>

/* void fork_this_shit(void)
{
    int p;
    p = fork();
    if (p == -1)
    {
        perror("fork fail");
    }    
    else if (p == 0)
        printf("Child here\n");
    else
        printf("parent of the year speaking\n");

} */


int main(void)
{
    0 && printf("0 && printf()\n") || printf("0 && printf() || printf()\n");;
    1 && printf("1 && printf()\n") || printf("1 && printf() || printf()\n");;

    0 || printf("0 || printf()\n");
    1 || printf("1 || printf()\n");
    return (0);
}