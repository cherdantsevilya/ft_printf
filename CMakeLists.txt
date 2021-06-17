cmake_minimum_required(VERSION 3.17)
project(pkari)

set(CMAKE_CXX_STANDARD 14)

add_executable(pkari ft_printf.c ft_printf.h ft_parsing.c ft_type_c.c ft_type_s.c ft_type_p.c ft_type_di.c ft_type_u.c ft_type_xX.c ft_type_percent.c)