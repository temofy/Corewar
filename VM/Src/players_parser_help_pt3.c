#include "../Headers/virtual_header.h"

void	zeroing_string_size(int *string_size, int amount_bytes, int *sum)
{
	if ((amount_bytes > BYTES_AFTER_NAME &&
		amount_bytes <= BYTES_AFTER_NAME + NULL_BYTES) ||
		(amount_bytes > BYTES_AFTER_CODE_SIZE &&
		amount_bytes <= BYTES_AFTER_CODE_SIZE + NULL_BYTES) ||
		(amount_bytes > BYTES_AFTER_COMMENT &&
		amount_bytes <= BYTES_AFTER_COMMENT + NULL_BYTES) ||
		amount_bytes == BYTES_AFTER_HEADER)
	{
		*string_size = 0;
		*sum = 0;
	}
}

int		check_for_overflow(void)
{
	int	i;
	int	amount_memory;

	i = -1;
	amount_memory = 0;
	while (++i < g_vm->amount_players)
		amount_memory += g_players[i].code_size;
	if (amount_memory > MEM_SIZE)
	{
		ft_fprintf(2, \
		"Virual machine error: players mem size \
bigger than permitted (%d > %d)\n", amount_memory, MEM_SIZE);
		return (-1);
	}
	return (1);
}

int		check_fd(int *fd, char *champion_file)
{
	*fd = open(champion_file, O_RDONLY);
	if (*fd == -1)
	{
		ft_fprintf(2, "Failed to open file: %s\n", champion_file);
		return (-1);
	}
	return (1);
}

int		check_file_sum(int sum, int i)
{
	if (sum != g_players[i].code_size)
	{
		ft_fprintf(2, "Error: File %s has a code size \
that differ from what its header says\n", g_players[i].file_name);
		return (-1);
	}
	return (1);
}
