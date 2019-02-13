# ft_printf
In this project at UNIT Factory (School 42) I must have recoded main part of libc standart function named printf.

My implementation contains next functionality:
Mandatory part:
1. %c - char conversion;
2. %s - string conversion;
3. %d - integer conversion (also %i, it's the same)
4. %p - address conversion;
5. %o - converts decimal to octal;
6. %u - prints unsigned value;
7. %x, X - converts decimal to hexademical (X means print uppercase);
8. %f - prints value with float point;
Bonuses:
1. %b - binary conversion;
2. %r - prints unprintable ascii symbols;
3. ft_cprintf - same as ft_printf, but with color handling;
4. ft_dprintf - same as ft_printf, but with write by fd functionality;
5. Almost all undifined behavior is supported.
In all these cases you can use formatting flags as:
- width;
- precision;
- cast modificators;
- zero filling and others.
more info about printf usage: https://linux.die.net/man/3/printf

A format specifier follows this prototype:
%[flags][width][precision][modificators][conversion type]

Example #1: ft_printf("This is %d, %s!", 42, baby);

Example #2: ft_printf("This is %+100d, %21.2s!", 42, baby);

Example #3: ft_printf("%s, is it %+.2f?!", "OMG", 3748932.858974928) and so on...


Project is done in accordance with school Norme (you can see them in Norme pdf).

Task requirement you can read in Subject pdf.

Good luck!
