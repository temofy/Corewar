#include "../Headers/virtual_header.h"

void	print_lld(t_cursor *cursor, int f_arg, int s_arg)
{
	if (g_vm->ver == 1 || g_vm->ver == 30)
		ft_printf("P %4d | lld %d r%d\n", cursor->cursror_id,
												f_arg, s_arg);
}
