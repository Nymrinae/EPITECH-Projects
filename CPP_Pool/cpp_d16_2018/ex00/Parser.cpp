/*
** EPITECH PROJECT, 2018
** ex00.cpp
** File description:
** Exersice 0 - stack
*/

#include "Parser.hpp"

static bool is_num(char c);
static bool is_sign(char c);
static int make_operation(int a, int b, char o);

Parser::Parser()
{
    this->_result = 0;
}

void Parser::feed(std::string const& str) {
    char op;
    int i = 0, tmp, nb1, nb2;

    while (str[i]) {
        if (is_num(str[i])) {
            tmp = 0;
            for (i; str[i] && is_num(str[i]); i++)
                tmp = tmp * 10 + str[i] - '0';
            this->_operands.push(tmp);
        }
        else if (str[i] == ')') {
            nb2 = this->_operands.top();
            this->_operands.pop();
            nb1 = this->_operands.top();
            this->_operands.pop();
            op = this->_operators.top();
            this->_operators.pop();
            this->_operands.push(make_operation(nb1, nb2, op));
            i++;
        }
        else if (is_sign(str[i])){
            this->_operators.push(str[i]);
            i++;
        } else
            i++;
    }
    nb1 = this->_operands.top();
    this->_operands.pop();
    if (!this->_operands.empty()) {
        if (!this->_operators.empty()) {
            op = this->_operators.top();
            this->_operators.pop();
            nb1 = make_operation(nb1, this->_operands.top(), op);
        }
        else {
            nb1 += this->_operands.top();
            this->_operands.pop();
        }
    }
    this->_operands.push(nb1);
}

int Parser::result() const
{
    return (this->_operands.top());
}

void Parser::reset()
{
	while(!this->_operands.empty())
		this->_operands.pop();
    while(!this->_operators.empty())
        this->_operators.pop();
}

static bool is_num(char c)
{
    return (c >= '0' && c <= '9');
}

static bool is_sign(char c)
{
    return (c == '+' ||
            c == '-' ||
            c == '*' ||
            c == '/' ||
            c == '%');
}

static int make_operation(int a, int b, char o)
{
	switch(o) {
		case '+':
			return (a + b);
		break;
		case '-':
			return (a - b);
		break;
		case '*':
			return (a * b);
		break;
		case '/':
			return (b != 0 ? a / b : 0);
		break;
		default:
			return (a % b);
		break;
	}
}



