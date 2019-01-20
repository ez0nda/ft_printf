#include "includes/ft_printf.h"

int		main(void)
{
	int ptr;
//	ft_printf("0x7fff%x", &ptr);
//	printf("\nprintf \n%lx", &ptr);
//	printf("\nprintf \n0x%lx", &ptr);
//	printf("\nprintf \n%p", &ptr);
//	ft_printf("%-20.10x", 4222);
//	printf("\nprintf \n%-20.10x", 4222);
	ft_printf("%-1.2s is a test", "this");
	printf("\nprintf \n%-1.2s is a test\n", "this");
	return (0);
}
