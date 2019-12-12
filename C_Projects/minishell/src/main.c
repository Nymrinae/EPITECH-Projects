/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function for mysh
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    int shell = mysh(ac, av, env);
    return (shell);
}
