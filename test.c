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


int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    int i = 0;
    int j = 0;
    while (envp[i])
    {
        j = 0;
        while (envp[i][j])
        {
            printf("%c",envp[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    return (0);
}