cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
#add_definitions( "-Wall -Wextra -Werror" )
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(ft_printf ${LIB} main.c ft_printf.c ft_major_parsing.c ft_minor_parsing.c ft_printf.h ft_assembly.c ft_auxiliary.c ft_valid_case.c ft_invalid_case.c ft_type_c.c ft_type_s.c ft_type_s_auxiliary.c ft_type_p.c libft/ft_itoa_base_ll_ed.c ft_type_p_auxiliary.c libft/ft_strjoin_free.c ft_type_d.c ft_type_d_auxiliary.c ft_type_o.c ft_type_u.c ft_type_x.c libft/ft_strsub_free.c libft/ft_malloc_sz.c ft_auxiliary_2.c ft_type_o_auxiliary.c ft_type_u_auxiliary.c ft_type_x_auxiliary.c)
link_libraries(libft/libft.a)