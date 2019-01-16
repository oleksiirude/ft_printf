cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(ft_printf ${LIB} main.c ft_printf.c ft_parsing.c ft_printf.h ft_assembly.c auxiliary.c)
link_libraries(libft/libft.a)