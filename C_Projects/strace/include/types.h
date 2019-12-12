/*
** EPITECH PROJECT, 2019
** types.h
** File description:
** Types array
*/

#ifndef TYPES_H_
#define TYPES_H_

#include <stdlib.h>

void print_int(unsigned long long int register_value);
void print_long(unsigned long long int register_value);
void print_uint(unsigned long long int register_value);
void print_ulong(unsigned long long int register_value);
void print_pointer(unsigned long long int register_value);
void print_string(unsigned long long int register_value);
void print_string_tab(unsigned long long int register_value);
void print_unimplemented(unsigned long long int register_value);

typedef struct s_types
{
    char *name;
    void (*print_fct)(unsigned long long int register_value);
} t_types;

static t_types g_types[] =
{
    {"void", NULL},
    {"char *", &print_string},
    {"char **", &print_string_tab},
    {"int", &print_int},
    {"int[2]", &print_pointer},
    {"uint32_t", &print_uint},
    {"unsigned int", &print_uint},
    {"long", &print_long},
    {"unsigned long", &print_ulong},
    {"u64", &print_ulong},
    {"size_t", &print_ulong},
    {"ssize_t", &print_long},
    {"caddr_t", &print_string},
    {"ndfs_t", &print_int},
    {"off_t", &print_ulong},
    {"key_t", &print_ulong},
    {"pid_t", &print_int},
    {"socklen_t", &print_ulong},
    {"uid_t", &print_int},
    {"gid_t", &print_int},
    {"gid_t[]", &print_pointer},
    {"clock_t", &print_ulong},
    {"cap_user_header_t", &print_pointer},
    {"cap_huser_data_t", &print_pointer},
    {"dev_t", &print_ulong},
    {"off64_t", &print_ulong},
    {"cpu_set_t", &print_ulong},
    {"aio_context_t", &print_ulong},
    {"mqd_t", &print_int},
    {"idtype_t", &print_ulong},
    {"key_serial_t", &print_ulong},
    {"unimplemented", &print_unimplemented},
    {"default", &print_pointer},
    {NULL, NULL}
};

#endif