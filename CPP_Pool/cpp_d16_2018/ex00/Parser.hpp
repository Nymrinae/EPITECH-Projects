/*
** EPITECH PROJECT, 2018
** ex00.cpp
** File description:
** Exersice 0 - stack
*/

#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <string>
#include <stack>

class Parser {
    protected:
        std::stack<char> _operators;
        std::stack<int> _operands;
        int _result;
    
    public:
        Parser();
        virtual ~Parser() { };

        void feed(const std::string &str);
        int result() const;
        void reset();
};

#endif