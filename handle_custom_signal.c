#include "shell.h"

/**
 * handle_custom_signal - Responds to custom signals
 * @signal_num: The identifier of the received signal
 *
 * This function handles custom signals like SIGINT.
 * It prints a new prompt when a SIGINT signal is received.
 *
 * Return:
 */

void handle_custom_signal(int signal_num)
{
	if (signal_num == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}

