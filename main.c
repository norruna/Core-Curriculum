#include "minishell.h"

/*this where we open a minishell, using readline
dont forget freeing line inside the loop
dont forget adding to history
dont forget clearing the history afterwards*/
void running_minishell(void)
{
     char *line;
	signal(SIGINT, handle_sigint); //if ctrlC is pressed
	signal(SIGQUIT, SIG_IGN); //if CTRL/ is pressed : ignore it (SIG_IGN)
    while (1)
    {
        line = readline("minishell$ ");
		if (!line) //handles ctrl+D since CTRLD is just EOF and not a signal
            break;

        if (*line)
            add_history(line);
        if (*line)
	    run_command(line);
        free(line);
    }

    rl_clear_history();
}

int main(void)
{
   running_minishell();
    return (0);
}
