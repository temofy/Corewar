#include "../Headers/virtual_header.h"

int		parse_champion_file_byte(char *champion_file,
								int i, int *amount_bytes)
{
	int		fd;
	uint8_t buffer[4];
	int		string_size;
	int		sum;
	int		temp;

	initialize_one_g_player(i);
	if (check_fd(&fd, champion_file) == -1)
		return (-1);
	g_players[i].file_name = champion_file;
	sum = 0;
	while ((temp = read(fd, buffer, 4)))
	{
		sum += temp;
		*amount_bytes += 4;
		zeroing_string_size(&string_size, *amount_bytes, &sum);
		if (!if_header_bytes(*amount_bytes, buffer) ||
			!make_g_player_size(*amount_bytes, buffer, i))
			return (-1);
		make_g_player_name(*amount_bytes, buffer, i, &string_size);
		make_g_player_comment(*amount_bytes, buffer, i, &string_size);
		make_g_player_code(*amount_bytes, buffer, i, &string_size);
	}
	close(fd);
	return (check_file_sum(sum, i));
}

int		players_parser(char **files_champions)
{
	int			i;
	int			amount_bytes;

	initialize_g_players();
	i = -1;
	while (++i < g_vm->amount_players)
	{
		amount_bytes = 0;
		g_players[i].file_name = files_champions[i];
		if (parse_champion_file_byte(files_champions[i],\
			i, &amount_bytes) == -1)
			return (-1);
	}
	if (check_for_overflow() == -1)
		return (-1);
	return (1);
}
