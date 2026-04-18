#include "minishell.h"


//checking if cd has a valid str attached to it. bit hardcoded cuz doenst handle multiple spaces 
void cd_path(char *line)
{
      
         char **result = ft_split(line, 32);
         /*quick printf debugging
         //start
         int i = 0;
         while (result[i])
         {
              printf("Result[%d] is : %s\n",i,result[i]);
              i++;
          }
         //end*/
         
        int res = chdir(result[1]);
         //path testing start
          /*char *cwd = getcwd(NULL,0);
            printf("whatevz : %s\n",cwd);
            free(cwd);
         //path testing end*/
         if (res == -1)
         {
              perror ("couldnt load the pathorino\n");
          
          }
     
}

void execute_cd(char *path)
{

      
      	if (strcmp(path,"cd .") == 0)
      	{
        	chdir(".");
                if (chdir(".") == -1)
                {
                perror("couldnt change\n");
                 }
      	}
      	if (strcmp(path,"cd ..") == 0)
      	{
      	       chdir("..");
                if (chdir("..") == -1)
                {
                    perror("couldnt change\n");
                }
      	}
      	if (strcmp(path,"cd") == 0 || strcmp(path, "cd ~") == 0)
      	{
      	       chdir(getenv("HOME"));
                if (chdir(getenv("HOME")) == -1)
                {
                    perror("couldnt change\n");
                }
      	}
}
