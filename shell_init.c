#include "shell.h"

/**
 * main - function that runs our shell
 * @ac: The number of inputed arguments
 * @av: The pointer to array of inputed arguments
 * @env: The pointer to array of environmental
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cicles = 0;
	(void)ac;

	while (1)
	{
		cicles++;
		prompt();
		signal(SIGINT, handle);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, "\0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_child(command, av[0], env, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * prompt - function that prints the prompt
 * Return: nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Hell_Shell>> ", 13);
}
/**
 * handle - function to handle Ctr + C signal
 * @signals: This signal to handle
 * Return: Nothing
 */

void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nHell_Shell>> ", 14);
}
/**
 * _EOF - function that checks if the bufer is EOF
 * @buffer: the pointer to the input string
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * shell_exit - function that exits the shell
 * @command: The pointer to tokenized command
 * Return: Nothing
 */
void shell_exit(char **command)
{
	int sta_tus = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}
	sta_tus = _atoi(command[1]);
	free_dp(command);
	exit(sta_tus);
}
