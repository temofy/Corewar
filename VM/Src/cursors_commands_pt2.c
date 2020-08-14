#include "../Headers/virtual_header.h"

void	and(t_cursor *cursor)
{
	unsigned char	codage;
	unsigned short	offset;
	int				first_arg;
	int				second_arg;
	int				third_arg;

	codage = g_battlefield[cursor->cur_pos + 1].code;
	if (!((codage & 0xC0) == 0 || (codage & 0x30) == 0 || (codage & 0xC) != 4))
	{
		offset = 2;
		first_arg = get_first_arg(cursor, codage, 4, &offset);
		second_arg = get_second_arg(cursor, codage, 4, &offset);
		third_arg = get_third_arg(cursor, codage, 4, &offset);
		if (check_reg(third_arg)
			&& check_reg_write_arg(cursor, codage, &first_arg, 1)
			&& check_reg_write_arg(cursor, codage, &second_arg, 2))
		{
			cursor->reg[third_arg - 1] = (first_arg & second_arg);
			if (g_vm->ver == 1 || g_vm->ver == 30)
				ft_printf("P %4d | and %d %d r%d\n", cursor->cursror_id,
										first_arg, second_arg, third_arg);
			cursor->carry = (cursor->reg[third_arg - 1] == 0) ? true : false;
		}
	}
	jump_to_next_op(cursor, codage, 4, 3);
}

void	or(t_cursor *cursor)
{
	unsigned char	codage;
	unsigned short	offset;
	int				first_arg;
	int				second_arg;
	int				third_arg;

	codage = g_battlefield[cursor->cur_pos + 1].code;
	if (!((codage & 0xC0) == 0 || (codage & 0x30) == 0 || (codage & 0xC) != 4))
	{
		offset = 2;
		first_arg = get_first_arg(cursor, codage, 4, &offset);
		second_arg = get_second_arg(cursor, codage, 4, &offset);
		third_arg = get_third_arg(cursor, codage, 4, &offset);
		if (check_reg(third_arg)
			&& check_reg_write_arg(cursor, codage, &first_arg, 1)
			&& check_reg_write_arg(cursor, codage, &second_arg, 2))
		{
			cursor->reg[third_arg - 1] = (first_arg | second_arg);
			if (g_vm->ver == 1 || g_vm->ver == 30)
				ft_printf("P %4d | or %d %d r%d\n", cursor->cursror_id,
										first_arg, second_arg, third_arg);
			cursor->carry = (cursor->reg[third_arg - 1] == 0) ? true : false;
		}
	}
	jump_to_next_op(cursor, codage, 4, 3);
}

void	xor(t_cursor *cursor)
{
	unsigned char	codage;
	unsigned short	offset;
	int				first_arg;
	int				second_arg;
	int				third_arg;

	codage = g_battlefield[cursor->cur_pos + 1].code;
	if (!((codage & 0xC0) == 0 || (codage & 0x30) == 0 || (codage & 0xC) != 4))
	{
		offset = 2;
		first_arg = get_first_arg(cursor, codage, 4, &offset);
		second_arg = get_second_arg(cursor, codage, 4, &offset);
		third_arg = get_third_arg(cursor, codage, 4, &offset);
		if (check_reg(third_arg)
			&& check_reg_write_arg(cursor, codage, &first_arg, 1)
			&& check_reg_write_arg(cursor, codage, &second_arg, 2))
		{
			cursor->reg[third_arg - 1] = (first_arg ^ second_arg);
			if (g_vm->ver == 1 || g_vm->ver == 30)
				ft_printf("P %4d | xor %d %d r%d\n", cursor->cursror_id,
										first_arg, second_arg, third_arg);
			cursor->carry = (cursor->reg[third_arg - 1] == 0) ? true : false;
		}
	}
	jump_to_next_op(cursor, codage, 4, 3);
}

void	zjmp(t_cursor *cursor)
{
	short	address;

	address = get_short_data(cursor->cur_pos + 1);
	if (cursor->carry == false)
	{
		if (g_vm->ver == 1 || g_vm->ver == 30)
			ft_printf("P %4d | zjmp %d %s\n",
				cursor->cursror_id, address, "FAILED");
		print_pc_movement(cursor, 3);
		move_cursor(cursor, 3);
	}
	else
	{
		move_cursor(cursor, address % IDX_MOD);
		if (g_vm->ver == 1 || g_vm->ver == 30)
			ft_printf("P %4d | zjmp %d %s\n",
				cursor->cursror_id, address, "OK");
	}
}

void	ldi(t_cursor *cursor)
{
	unsigned char	codage;
	int				f_arg;
	int				s_arg;
	int				t_arg;
	unsigned short	offset;

	codage = g_battlefield[cursor->cur_pos + 1].code;
	if (!((codage & 0xC0) == 0 || (codage & 0x30) == 0x30 ||
		(codage & 0x30) == 0 || (codage & 0xC) != 4))
	{
		offset = 2;
		f_arg = get_first_arg(cursor, codage, 2, &offset);
		s_arg = get_second_arg(cursor, codage, 2, &offset);
		t_arg = get_third_arg(cursor, codage, 2, &offset);
		if (check_reg(t_arg)
			&& check_reg_write_arg(cursor, codage, &f_arg, 1)
			&& check_reg_write_arg(cursor, codage, &s_arg, 2))
		{
			cursor->reg[t_arg - 1] = get_int_data(cursor->cur_pos +
										(f_arg + s_arg) % IDX_MOD);
			print_ldi(cursor, f_arg, s_arg, t_arg);
		}
	}
	jump_to_next_op(cursor, codage, 2, 3);
}
