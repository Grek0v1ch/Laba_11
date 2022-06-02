#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include "../bin_tree/bin_tree.hpp"
#include "../data_check/data_check.hpp"
#include "../train/train.hpp"

// Цикл первого меню (после завершения работы вызывает второе).
void build_menu(bin_tree<train>&);

#endif // MENU_HPP
