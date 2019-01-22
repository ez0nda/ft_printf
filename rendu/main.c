#include "includes/ft_printf.h"

int		main(void)
{
	int ptr;
//	ft_printf("0x7fff%x", &ptr);
//	printf("\nprintf \n%lx", &ptr);
//	printf("\nprintf \n0x%lx", &ptr);
//	printf("\nprintf \n%p", &ptr);0000
//	ft_printf("%-20.10x", 4222);
//	printf("\nprintf \n%-20.10x", 4222);
	ft_printf("@moulitest: %-+5.13d", -8);
	printf("\nprintf \n@moulitest: %-+5.13d\n", -8);
return (0);
}
