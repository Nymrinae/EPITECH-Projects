/*
** EPITECH PROJET, 2018
** filename
** File description:
** description?
*/

#include "IPC.hpp"
#include "Plazza.hpp"
#include "SCommand.hpp"
#include "Kitchen.hpp"
#include "Reception.hpp"

Reception::Reception(float m, int c, int s):
_cooks(c),
_multiplier(m),
_refreshTime(s),
_open(false)
{

}

void Reception::open()
{
    _open = true;
    _acceptOrders();
    /* std::thread t1(&Reception::_acceptOrders, this);
    t1.join(); */
}

void Reception::_acceptOrders()
{
    IPC ipc(this->_multiplier, this->_cooks, this->_refreshTime);
    Busy busy(nullptr);

    ipc.link(busy);
    while (true) {
        std::string command;
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "exit")
            break;
        if (!_parser.isValidCommand(command)) {
            std::cerr << "Invalid command, retry. Example : \"regina XXL x2; fantasia M x3; margarita S x1\""
                    << std::endl;
            continue;
        }
        _currentCommand = _parser.splitCommand(command);
        ArrayOfCommands Command = getCommand();
        for (auto i : Command)
            for (int j = 0; j < i[2][1] - '0'; j++) {
                SCommand c(i[0], i[1]);
                ipc.setSmemory(c.getCommandProperties().first,
                c.getCommandProperties().second);
                _createKitchen(c, busy, ipc.getSmemory());
            }
    }
    ipc.unlink();
}

void Reception::_createKitchen(SCommand cmd, Busy &busy, int *sMem)
{
    pid_t pid = fork();

    (void)sMem;

    // Kitchen k(cmd, this->_multiplier, this->_cooks, this->_refreshTime);
    // busy.doNotDisturb();
    // cmd.unserialize();
    // k.giveCmd(cmd.getPizzaProperties().first);
    // busy.avaible();
    if (pid == 0) {
        Kitchen k(cmd, this->_multiplier, this->_cooks, this->_refreshTime);
        busy.doNotDisturb();
        cmd.unserialize();
        k.giveCmd(cmd.getPizzaProperties().first);
        busy.avaible();
        exit(0);
    } else {
        //int status;
        //waitpid(pid, &status, 0);
        //busy.doNotDisturb();
        // std::cout << cmd.getCommandProperties().first
        //           << " "
        //           << cmd.getCommandProperties().second
        //           << "finished !"
        //           << std::endl;
        //busy.avaible();
        // Mutex part
    }
    //std::cout << "Sent " << c.getPizzaProperties().first << " " << c.getPizzaProperties().second << " to the kitchen !" << std::endl;
}

template <class Container>
void myStrTok(const std::string &str, Container &cont,
              const std::string &delims = " ")
{
    if (str.empty())
        return;
    auto itBeginToken = str.begin();
    auto itEndToken = str.begin();
    cont.clear();

    while (itEndToken != str.end()) {
        std::size_t indexBeginToken =
            str.find_first_not_of(delims, itEndToken - str.begin());
        itBeginToken = str.begin() + indexBeginToken;
        if (itBeginToken == str.end() || indexBeginToken == std::string::npos)
            break;
        itEndToken = std::find_first_of(itBeginToken, str.end(),
                                        delims.begin(), delims.end());
        cont.push_back(std::string(itBeginToken, itEndToken));
    }
}

using ArrayOfCommands = std::vector<std::vector<std::string>>;
ArrayOfCommands Reception::Parser::splitCommand(std::string const &commands) const
{
    std::vector<std::vector<std::string>> parts;
    std::vector<std::string> splitCommands;

    myStrTok(commands, splitCommands, ";");
    for (auto &command : splitCommands) {
        std::vector<std::string> words;
        myStrTok(command, words, " ");
        parts.push_back(words);
    }
    return parts;
}

bool Reception::Parser::isValidCommand(const std::string &command) const
{
    if (command.empty())
        return false;
    if (command == "status")
        return true;
    std::vector<std::string> orders;
    myStrTok(command, orders, ";");
    if (orders.empty())
        return false;
    for (auto &order : orders) {
        std::vector <std::string> parts;
        myStrTok(order, parts, " ");
        if (parts.size() % 3 != 0 || parts.empty())
        {
            return false;
        }
        if (! _isPizzaTypeValid(parts.at(0)) ||
            !_isPizzaSizeValid(parts.at(1)) ||
            !_isPizzaNumberValid(parts.at(2)))
        {
            return false;
        }
    }
    return true;
}

bool Reception::Parser::_isPizzaTypeValid(const std::string &pizzaType) const
{
    std::array<std::string, 5> types = {"regina", "margarita", "fantasia", "americana"};
    for (auto &elem : types)
        if (elem == pizzaType)
            return true;
    return false;
}

bool Reception::Parser::_isPizzaSizeValid(const std::string &pizzaSize) const
{
    std::array<std::string, 5> grammar = {"S", "M", "L", "XL", "XXL"};
    for (auto &elem : grammar)
        if (elem == pizzaSize)
            return true;
    return false;
}

bool Reception::Parser::_isPizzaNumberValid(std::string const &pizzaNumber) const
{
    if (pizzaNumber.size() < 2)
        return false;
    if (pizzaNumber.at(0) != 'x')
        return false;
    else if (pizzaNumber.find('.') != std::string::npos)
        return false;
    else if (pizzaNumber.at(1) < '1' || pizzaNumber.at(1) > '9')
        return false;
    auto it = std::find_if(pizzaNumber.begin() + 2, pizzaNumber.end(),
    [&](char c)
    {
        return (c < '0' || c > '9');
    });
    return *it == '\0';
}
