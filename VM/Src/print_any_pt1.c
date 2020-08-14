#include "../Headers/virtual_header.h"

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -v -n N] <filename.cor> ...\n");
	ft_printf("\t-a \t: Print output from \"aff\"\n");
	ft_printf("\t-dump N\t: Dumps memory after N cycles then exits\n");
	ft_printf("\t-n N\t: set the champion number\n");
	ft_printf("\t-vi\t: visual mode\n");
	ft_printf("\t-v N\t: verbose\n");
	ft_printf("\t\t - 1 : Opearions\n");
	ft_printf("\t\t - 2 : Cycles\n");
	ft_printf("\t\t - 3 : Lives\n");
	ft_printf("\t\t - 4 : Deaths\n");
	ft_printf("\t\t - 5 : PC movement\n");
	ft_printf("\t\t - 30 : Print all exlcude \"lives\"\n");
}

void	show_bin_int(unsigned int i)
{
	int j;

	j = 0;
	while (++j <= 32)
	{
		if (i & 0x80000000)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i << 1;
		if (j % 8 == 0 && j != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	show_bin_char(unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x80)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		c = c << 1;
	}
	write(1, "\n", 1);
}

void	print_players(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_vm->amount_players)
	{
		j = 0;
		ft_printf("Player number = %d\n", g_players[i].identifier);
		ft_printf("Name = %s\n", g_players[i].name);
		ft_printf("Comment = %s\n", g_players[i].comment);
		ft_printf("Code size = %d\n", g_players[i].code_size);
		printf("Code:\n");
		while (j < g_players[i].code_size)
		{
			if (j % 8 == 0 && j != 0)
				printf("\n");
			printf("%02hhx ", g_players[i].code[j]);
			j += 1;
		}
		ft_printf("\n\n");
	}
}

void	print_hex_data(char *file)
{
	int		fd;
	int		i;
	uint8_t	buffer[4];
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return ;
	ft_printf("Filename = %s\n", file);
	while (read(fd, &buffer, 4))
	{
		i = -1;
		while (++i < 4)
		{
			print_hex_data_help(count, buffer, i);
			count++;
		}
		ft_printf("%d\n", count);
	}
	close(fd);
}
