#pragma once

#include <iostream>
#include <limits>

void print_menu();
void print_sort_menu();
void print_filter_menu();

void pause_menu(const char *message);
int get_menu_option(int maxValue);

template<class T>
T get_user_answer(const std::string &question)
{
    T answer {};

    std::cout << question;
    std::cin >> answer;

    return answer;
}

template<class T>
T get_enum_value(const std::string &prompt, const int &maxValue)
{
    std::cout << prompt << std::endl;
    int value = get_menu_option(maxValue);
    std::underlying_type_t<T> a_Type {value};
    T aType {T{a_Type}};

    return aType;
}
