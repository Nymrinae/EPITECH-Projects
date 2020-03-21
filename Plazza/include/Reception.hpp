/*
** EPITECH PROJET, 2018
** reception.hpp
** File description:
** class Reception
*/

#pragma once

#include "Busy.hpp"
#include "Plazza.hpp"
#include "SCommand.hpp"

using ArrayOfCommands = std::vector<std::vector<std::string>>;

class Reception {
    public:
        Reception(float, int, int);

        class Parser {
        public:
            bool isValidCommand(std::string const &command) const;
            ArrayOfCommands splitCommand(std::string const &command) const;
        private:
            bool _isPizzaTypeValid(std::string const &pizzaType) const;
            bool _isPizzaSizeValid(std::string const &pizzaSize) const;
            bool _isPizzaNumberValid(std::string const &pizzaSize) const;
        };
        void open();
        ArrayOfCommands getCommand() { return(this->_currentCommand); };
    private:
        int _cooks;
        float _multiplier;
        int _refreshTime;
        void            _acceptOrders();
        void            _createKitchen(SCommand, Busy &, int *);
        bool            _open;
        Parser          _parser;
        ArrayOfCommands _currentCommand;
};
