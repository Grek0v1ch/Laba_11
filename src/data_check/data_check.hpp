#ifndef DATA_CHECK_HPP
#define DATA_CHECK_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "../train/train.hpp"

// Функция проверяет корректность записи времени.
bool check_time(const std::string&);
// Функция проверяет корректность введенного времени.
void input_time(std::string&);

// Функция проверяет корректность введенного имени файла для чтения.
void input_file_name(std::string&);

// Функция проверяет корректность введенного положительного числа.
void input_positiv_int(int&);
// Функция проверяет корректность введенного положительного числа из файла.
void file_input_positiv_int(int&, std::ifstream&);

// Функция проверяет корректность введенного поезда.
void input_train(train& object);
// Функция проверяет корректность введенного поезда из файла.
void file_input_train(train&,  std::ifstream&);

#endif // DATA_CHECK_HPP
