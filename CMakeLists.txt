cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(ft_printf ${LIB} main.c ft_printf.c ft_major_parsing.c ft_minor_parsing.c ft_printf.h ft_assembly.c ft_auxiliary.c ft_valid_case.c ft_invalid_case.c ft_type_c.c ft_type_s.c)
link_libraries(libft/libft.a)