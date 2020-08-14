#include "../Headers/virtual_header.h"

int		main(int argc, char *argv[])
{
	int	rtn;

	rtn = 1;
	if (argc < 2)
	{
		print_usage();
		return (-1);
	}
	else
	{
		initialize_vm();
		rtn = parsing(argc, argv);
		if (rtn == 1)
			virtual_machine();
		free_all();
	}
	return (rtn);
}
