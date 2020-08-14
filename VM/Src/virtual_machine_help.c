#include "../Headers/virtual_header.h"

void	check_alive_cursors_cycle_body(t_cursors_list **current,
										t_cursors_list **prev)
{
	int	i;

	i = 0;
	if (g_vm->ver == 4 || g_vm->ver == 30)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
										(*current)->cursor.cursror_id,
					CURRENT_CYCLE - (*current)->cursor.last_alive, CTD);
	g_battlefield[(*current)->cursor.cur_pos].cursor = false;
	while (g_players[i].identifier != (*current)->cursor.player_id)
		i++;
	g_players[i].amount_cursors--;
	*current = (*current)->next;
	if ((*prev)->next == *current)
	{
		if (*prev == g_cursors)
			g_cursors = g_cursors->next;
		free(*prev);
		*prev = *current;
	}
	else
	{
		free((*prev)->next);
		(*prev)->next = *current;
	}
}

void	check_alive_cursors(void)
{
	int				alive_cursors;
	t_cursors_list	*current;
	t_cursors_list	*prev;

	current = g_cursors;
	prev = g_cursors;
	alive_cursors = 0;
	while (current)
	{
		if (CURRENT_CYCLE - current->cursor.last_alive < CURRENT_CYCLE -
			LAST_CYCLE_CHECK && CTD > 0)
		{
			prev = current;
			current = current->next;
			alive_cursors++;
		}
		else
			check_alive_cursors_cycle_body(&current, &prev);
	}
	g_cursors_amount = alive_cursors;
}

void	push_winner(t_cycles_to_die repeate)
{
	SDL_Event	event;

	if (g_vm->vis == 1 && !VIS_QUIT)
	{
		VIS_PAUSE = 0;
		VIS_QUIT = 0;
		push_to_render_battlefield();
		push_info(repeate.amount_of_repeate, "**Pause**");
		push_winner_vis();
		SDL_RenderPresent(g_main_render);
		while (!VIS_QUIT && !VIS_PAUSE)
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN
					&& event.key.keysym.sym == SDLK_ESCAPE))
					VIS_QUIT = 1;
				if (event.type == SDL_KEYDOWN
					&& event.key.keysym.sym == SDLK_SPACE)
					VIS_PAUSE = 1;
			}
	}
	else if (g_vm->vis != 1 && !VIS_QUIT)
		ft_printf("Contestant %d, \"%s\", has won !\n", g_vm->last_live_player,
									g_players[g_vm->last_live_player - 1].name);
}

void	inc_current_cycle_and_print(void)
{
	CURRENT_CYCLE++;
	if (g_vm->ver == 2 || g_vm->ver == 30)
		ft_printf("It is now cycle %d\n", CURRENT_CYCLE);
}
