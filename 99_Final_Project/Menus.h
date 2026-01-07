#pragma once

#include <iostream>
#include <limits>
#include <string>

#include "excepts/InvalidOptionException.h"
#include "excepts/EmptyArgumentException.h"

void print_menu();
void print_sort_menu();
void print_filter_menu();

void pause_app(const char *message);

std::string ask_string(const std::string &question);
int ask_int(const std::string &question, int maxValue = -1, bool isLimited = false);
double ask_double(const std::string &question, double maxValue = 0.0, bool isLimited = false);