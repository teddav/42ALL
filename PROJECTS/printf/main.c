#include "FILES/includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main(void)
{
	int ret;
	ret = ft_printf("{yellow}%p{eoc}\n", &ret);
	printf("%p\n", &ret);
	ft_putnbr(ret);

	ft_printf("Test couleur {cyan}%s{eoc} fin\n", "en couleur");

	ft_printf("J'imprime un %%x pour voir");

	// int		ret;
	// int		ret2;
	// void	*test = "4";
	// printf("%lu\n", sizeof(wchar_t));
	// printf("%10D\n", 42);
	// printf("%-10O\n", 42);
	// printf("%.10U\n", 42);
	// ft_printf("%10D\n", 42);
	// ft_printf("%-10O\n", 42);
	// ft_printf("%.10U\n", 42);
	// printf("%p\n", test);
	// ft_printf("%p\n", test);
	// printf("%s\n", "PRINTF :");
	// printf("%o\n", 42);
	// printf("%0o\n", 42);
	// printf("%10o\n", 42);
	// printf("%.10o\n", 42);
	// printf("%#o\n", 42);
	// printf("%#.10o\n", 42);
	// printf("%#10o\n", 42);
	// printf("%#-10o\n", 42);
	// ft_printf("\n{red}%s{eoc}\n", "FT_PRINTF :");
	// ft_printf("%o\n", 42);
	// ft_printf("%0o\n", 42);
	// ft_printf("%10o\n", 42);
	// ft_printf("%.10o\n", 42);
	// ft_printf("%#o\n", 42);
	// ft_printf("%#.10o\n", 42);
	// ft_printf("%#10o\n", 42);
	// ft_printf("%#-10o\n", 42);
	// printf("%s\n", "PRINTF :");
	// printf("%0#x\n", 42);
	// printf("%0#X\n", 42);
	// printf("%0#0x\n", 42);
	// printf("%0#0X\n", 42);
	// printf("%0-#.10x\n", 42);
	// printf("%0#10X\n", 42);
	// printf("%#10x\n", 42);
	// printf("%#.10X\n", 42);
	// ft_printf("\n{red}%s{eoc}\n", "FT_PRINTF :");
	// ft_printf("%0#x\n", 42);
	// ft_printf("%0#X\n", 42);
	// ft_printf("%0#0x\n", 42);
	// ft_printf("%0#0X\n", 42);
	// ft_printf("%0-#.10x\n", 42);
	// ft_printf("%0#10X\n", 42);
	// ft_printf("%#10x\n", 42);
	// ft_printf("%#.10X\n", 42);
	// printf("%s\n", "PRINTF :");
	// printf("%10u\n", 42);
	// printf("%.10u\n", 42);
	// printf("%010u\n", 42);
	// printf("%5.10u\n", 42);
	// printf("%10.5i\n", 42);
	// printf("%-5.10u\n", 42);
	// printf("%-10.5i\n", 42);
	// ft_printf("\n{red}%s{eoc}\n", "FT_PRINTF :");
	// ft_printf("%10u\n", 42);
	// ft_printf("%.10u\n", 42);
	// ft_printf("%010u\n", 42);
	// ft_printf("%5.10u\n", 42);
	// ft_printf("%10.5i\n", 42);
	// ft_printf("%-5.10u\n", 42);
	// ft_printf("%-10.5i\n", 42);
	
	// printf("%s\n", "");
	// printf("%s\n", nom);
	// printf("%10s\n", nom);
	// printf("%-10s\n", nom);
	// printf("%010s\n", nom);
	// printf("%i\n", ret);
	// ft_printf("%s\n", "");
	// ft_printf("%s\n", nom);
	// ft_printf("%10s\n", nom);
	// ft_printf("%-10s\n", nom);
	// ft_printf("%010s\n", nom);
	// ft_printf("%i\n", ret2);
	// printf("%s\n", "PRINTF :");
	// printf("%+010i\n", age);
	// printf("% 0i\n", age);
	// printf("%+i\n", age);
	// printf("% i\n", age);
	// printf("%010i\n", age);
	// printf("%+10i\n", age);
	// printf("%+10i\n", -age);
	// printf("% 10i\n", age);
	// printf("%0.10i\n", age);
	// printf("%-.10i\n", age);
	// printf("%+.10i\n", age);
	// printf("% .10i\n", age);
	// printf("%0+10i\n", age);
	// printf("%-+10i\n", age);
	// printf("% +i\n", age);
	// printf("% -i\n", age);
	// printf("%.2i\n", 0);
	// printf("%10.5i\n", 42);
	// printf("%-10.5i\n", 42);
	// ft_printf("\n{red}%s{eoc}\n", "FT_PRINTF :");
	// ft_printf("%+010i\n", age);
	// ft_printf("% 0i\n", age);
	// ft_printf("%+i\n", age);
	// ft_printf("% i\n", age);
	// ft_printf("%010i\n", age);
	// ft_printf("%+10i\n", age);
	// ft_printf("%+10i\n", -age);
	// ft_printf("% 10i\n", age);
	// ft_printf("%0.10i\n", age);
	// ft_printf("%-.10i\n", age);
	// ft_printf("%+.10i\n", age);
	// ft_printf("% .10i\n", age);
	// ft_printf("%0+10i\n", age);
	// ft_printf("%-+10i\n", age);
	// ft_printf("% +i\n", age);
	// ft_printf("% -i\n", age);
	// ft_printf("%.2i\n", 0);
	// ft_printf("%10.5i\n", 42);
	// ft_printf("%-10.5i\n", 42);
	// printf("%s\n", "PRINTF :");
	// printf("%-10%-+#fhhs\n");
	// printf ("Characters: %010c %c %C \n", 'a', 65, 'a');
 //   	printf ("Decimals: %d, %i, %D \n", 1977, 1977, 1977);
 //   	printf ("Preceding with blanks:%10d \n", 1977);
 //   	printf ("Preceding with zeros:%010d \n", 1977);
 //   	printf ("Some different radices: %d %x %X %o %#x %#X %#o \n", 100, 100, 100, 100, 100, 100, 100);
 //   	printf ("Width trick: %*d \n", 10, 10);
 //   	printf ("%s \n", "A string");
   	// printf ("No conversion: %% \n");
 //   	printf ("Unisgned Decimal: %u \n", -1);
 //   	printf ("Left justify:%-10d \n", 1977);
 //   	printf ("Multiple spaces:%       d \n", 1977);
 //   	printf("%s\n", "TESTS POUSSES");
 //   	printf("4567 |%-10]5d| plip\n", 12);
 //    printf("4567 |%10]5d| plip\n", 12);
 //    printf("|%10.5d|\n", -12);
 //    printf("|%10d|\n", -12);
 //    printf("|%010d|\n", -12); 
 //    printf("|%-10.5d|\n", -12);
 //    printf("|%-010.5d|\n", -12);
 //   	ft_printf("\n{red}%s{eoc}\n", "FT_PRINTF :");
   	// ft_printf("%-10%-+#fhhs\n");
	// ft_printf ("Characters: %010c %c %C \n", 'a', 65, 'a');
 //   	ft_printf ("Decimals: %d, %i, %D \n", 1977, 1977, 1977);
 //   	ft_printf ("Preceding with blanks:%10d \n", 1977);
 //   	ft_printf ("Preceding with zeros:%010d \n", 1977);
 //   	ft_printf ("Some different radices: %d %x %X %o %#x %#X %#o \n", 100, 100, 100, 100, 100, 100, 100);
 //   	ft_printf ("Width trick: %*d \n", 10, 10);
 //   	ft_printf ("%s \n", "A string");
   	// ft_printf ("No conversion: %% \n");
 //   	ft_printf ("Unisgned Decimal: %u \n", -1);
 //   	ft_printf ("Left justify:%-10d \n", 1977);
 //   	ft_printf ("Multiple spaces:%       d \n", 1977);
 //   	ft_printf("%s\n", "TESTS POUSSES");
 //   	ft_printf("4567 |%-10]5d| plip\n", 12);
 //    ft_printf("4567 |%10]5d| plip\n", 12);
 //    ft_printf("|%10.5d|\n", -12);
 //    ft_printf("|%10d|\n", -12);
 //    ft_printf("|%010d|\n", -12); 
 //    ft_printf("|%-10.5d|\n", -12);
 //    ft_printf("|%-010.5d|\n", -12);
	//ft_putnbr(ret);
	return (0);
}