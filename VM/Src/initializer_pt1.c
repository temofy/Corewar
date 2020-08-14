#include "../Headers/virtual_header.h"

int		*init_int_array(int size, int nbr)
{
	int *array;
	int i;

	i = -1;
	array = (int*)malloc(sizeof(int) * size);
	while (++i < size)
		array[i] = nbr;
	return (array);
}

void	initialize_vm(void)
{
	int i;

	i = -1;
	g_vm = (t_vm *)malloc(sizeof(t_vm));
	g_vm->dump = -1;
	g_vm->vis = -1;
	g_vm->ver = -1;
	g_vm->color_print = 0;
	g_vm->last_live_player = 0;
	g_vm->order_idtfrs = init_int_array(MAX_PLAYERS, 0);
	g_vm->plr_nbr = (t_plr_nbr *)malloc(sizeof(t_plr_nbr) * MAX_PLAYERS);
	g_vm->amount_players = 0;
	g_vm->cursors_id_iter = 1;
	while (++i < MAX_PLAYERS)
	{
		g_vm->plr_nbr[i].index_file = 0;
		g_vm->plr_nbr[i].identifier = 0;
	}
}

void	initialize_g_players(void)
{
	int	i;

	g_players = (t_player *)malloc(sizeof(t_player) * g_vm->amount_players);
	i = -1;
	while (++i < g_vm->amount_players)
	{
		g_players[i].file_name = NULL;
		g_players[i].start_position = 0;
		g_players[i].code = NULL;
		g_players[i].code_size = 0;
		g_players[i].comment = NULL;
		g_players[i].identifier = 0;
		g_players[i].name = NULL;
		g_players[i].last_alive = 0;
		g_players[i].nbr_live = 0;
		g_players[i].amount_cursors = 1;
		g_players[i].aff_out = NULL;
	}
}

void	initialize_battlefield(void)
{
	int	i;

	i = -1;
	g_battlefield = (t_battlefield *)malloc(sizeof(t_battlefield) * MEM_SIZE);
	while (++i < MEM_SIZE)
	{
		g_battlefield[i].code = 0x0;
		g_battlefield[i].color = '\0';
		g_battlefield[i].color_b = 0;
		g_battlefield[i].color_g = 0;
		g_battlefield[i].color_r = 0;
		g_battlefield[i].write_cycles = 0;
		g_battlefield[i].cursor = false;
	}
	fill_battlefield();
}

void	initialize_cursors(void)
{
	int				i;
	int				plr_id;
	t_cursors_list	*current;

	i = -1;
	g_cursors = make_new_cursors_list();
	current = g_cursors;
	plr_id = g_vm->amount_players;
	while (++i < g_vm->amount_players)
	{
		zeroing_cursors_args(&plr_id);
		if (i != g_vm->amount_players - 1)
		{
			g_cursors->next = make_new_cursors_list();
			g_cursors = g_cursors->next;
		}
	}
	g_cursors = current;
	g_cursors_amount = g_vm->amount_players;
	g_amount_live_operations = 0;
}
