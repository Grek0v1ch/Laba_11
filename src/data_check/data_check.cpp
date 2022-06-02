#include "data_check.hpp"

// Функция проверяет корректность записи времени.
bool check_time(const std::string& data) {
	for (int i = 2; i < 8; i += 3)
		if (data[i] != ':') return false;
	int temp = (data[0] - '0') * 10 + data[1] - '0';
	if (temp >= 24 or temp < 0) return false;
	temp = (data[3] - '0') * 10 + data[4] - '0';
	if (temp >= 60 or temp < 0) return false;
	temp = (data[6] - '0') * 10 + data[7] - '0';
	if (temp >= 60 or temp < 0) return false;
	return true;
}

// Функция проверяет корректность введенного времени.
void input_time(std::string& time) {
	std::cin >> time;
	while (! check_time(time)) {
		std::cout << "Try again: ";
		std::cin >> time;
	}
}

// Функция проверяет корректность введенного имени файла для чтения.
void input_file_name(std::string& file_name) {
	std::cin >> file_name;
	std::ifstream fin(file_name);
	while (! fin.is_open()) {
		std::cout << "Error, try again: ";
		std::cin >> file_name;
		fin = std::ifstream(file_name);
	}
	fin.close();
}

// Функция проверяет корректность введенного положительного числа.
void input_positiv_int(int& value) {
	std::string number;
	while (true) {
		std::cin >> number;
		try {
			value = stoi(number);
		} catch (...) {
			std::cout << "Try again: ";
			continue;
		}
		if (value <= 0) continue;
		break;
	}
}

// Функция проверяет корректность введенного положительного числа из файла.
void file_input_positiv_int(int& value, std::ifstream& fin) {
	std::string number;
	fin >> number;
	try {
		value = stoi(number);
	} catch (...) {
		std::cout << "Error: not int\n";
	}
	if (value <= 0) {
		std::cout << "Error: not positiv int\n";
		value = 0;
	}
}

// Функция проверяет корректность введенного поезда.
void input_train(train& object) {
	std::string destination_name, number, departure_time;
	int value;
	while (true) {
		std::cin >> number >> destination_name >> departure_time;
		try {
			value = stoi(number);
		} catch (...) {
			std::cout << "Try again: ";
			continue;
		}
		if (! check_time(departure_time) || value <= 0) {
			std::cout << "Try again: ";
			continue;
		}
		break;
	}
	object = train(destination_name, value, departure_time);
}

// Функция проверяет корректность введенного поезда из файла.
void file_input_train(train& object,  std::ifstream& fin) {
	std::string destination_name, number, departure_time;
	int value;
	fin >> number >> destination_name >> departure_time;
	try {
		value = stoi(number);
	} catch (...) {
		std::cout << "Error: not number\n";
		return;
	}
	if (! check_time(departure_time)) {
		std::cout << "Error: not time\n";
		return;
	}
	object = train(destination_name, value, departure_time);
}