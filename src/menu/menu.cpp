#include "menu.hpp"

#include <iostream>
#include <fstream>

// Функция считываем нажатие клавиши enter пользователем.
void read_enter() {
	// Так как нельзя запретить пользователю нажимать друге клавиши, как метод защиты счтываем
	// все что введет пользователь.
	std::string buff;
	getline(std::cin, buff);
}

// Функция считывает один элемент (поезд) и добавляет его в древо.
void input_one_item(bin_tree<train>& my_tree) {
	train item;
	std::cout << "Enter as {train number} {destination name}  {departure time{hh:mm:ss}}\n"
			  << "Enter item: ";
	input_train(item);
	// Убираем мусор из потока.
	std::cin.get();
	my_tree.insert(item);
}

// Функция ввода всего дерева поездов с клавиатуры.
void input_tree(bin_tree<train>& my_tree) {
	int num;
	std::cout << "Enter item number: ";
	input_positiv_int(num);
	// Убираем мусор из потока.
	std::cin.get();
	std::cout << "Enter as {train number} {destination name}  {departure time{hh:mm:ss}}\n";
	for (int i = 0; i < num; i++) {
		train item;
		std::cout << "Enter item: ";
		input_train(item);
		// Убираем мусор из потока.
		std::cin.get();
		my_tree.insert(item);
	}
}

// Функция ввода всего дерева поездов из файла.
// Неккоректно считаные элементы пропускаются.
void file_input_tree(bin_tree<train>& my_tree) {
	std::string file_name;
	std::cout << "Enter file name: ";
	input_file_name(file_name);
	// Убираем мусор из потока.
	std::cin.get();
	std::ifstream fin(file_name);
	int num;
	file_input_positiv_int(num, fin);
	for (int i = 0; i < num; i++) {
		train item;
		file_input_train(item, fin);
		my_tree.insert(item);
	}
	fin.close();
}

// Функция удаляет введенный элемент из дерева.
void delete_item(bin_tree<train>& my_tree) {
	train item;
	std::cout << "Enter as {train number} {destination name}  {departure time{hh:mm:ss}}\n"
			  << "Enter item: ";
	input_train(item);
	// Убираем мусор из потока.
	std::cin.get();
	my_tree.remove(item);
}

// Функция определяет, есть ли введенный элемент в дереве.
void find_item(bin_tree<train>& my_tree) {
	train item;
	std::cout << "Enter as {train number} {destination name}  {departure time{hh:mm:ss}}\n"
			  << "Enter item: ";
	input_train(item);
	pnode<train> pos = my_tree.find(item);
	if (pos) {
		std::cout << "Item found\n";
		// Убираем мусор из потока.
		std::cin.get();
		return;
	}
	std::cout << "Item not found\n";
	// Убираем мусор из потока.
	std::cin.get();
}

// Функция редактирования запрошенного пользователем элемента.
void edit_item(bin_tree<train>& my_tree) {
	train item;
	std::cout << "Enter as {train number} {destination name}  {departure time{hh:mm:ss}}\n"
			  << "Enter item: ";
	input_train(item);
	pnode<train> pos = my_tree.find(item);
	if (! pos) {
		std::cout << "Item not found\n";
		// Убираем мусор из потока.
		std::cin.get();
		return;
	}
	my_tree.remove(item);
	std::cout << "Enter new item: ";
	input_train(item);
	// Убираем мусор из потока.
	std::cin.get();
	my_tree.insert(item);
}

// Функция сравнивает пункты назначения двух поездов.
bool cmp_destination_name(const train& first, const train& second) {
	return first.destination_name() == second.destination_name();
}

// Функция выводит все поезда с введенным пунктом назначения.
void print_with_same_name(bin_tree<train>& my_tree) {
	std::string name;
	std::cout << "Enter destination name: ";
	std::cin >> name;
	// Убираем мусор из потока.
	std::cin.get();
	int count_item = my_tree.print_lnr(cmp_destination_name, train(name, 0, "00:00:00"));
	if (! count_item) std::cout << "No items\n";
}

// Функция сравнивает время отправки поездов.
bool cmp_departure_time(const train& first, const train& second) {
	return first.departure_time() > second.departure_time();
}

// Функция выводит все поезда, которые отправляются после введенного времени.
void print_after_set_time(bin_tree<train>& my_tree) {
	std::string departure_time;
	std::cout << "Enter departure time{hh:mm:ss}: ";
	input_time(departure_time);
	// Убираем мусор из потока.
	std::cin.get();
	int count_item = my_tree.print_lnr(cmp_departure_time, train("", 0, departure_time));
	if (! count_item) std::cout << "No items\n";
}

// Вывод пунктов первого меню и выбор пункта.
int choise_build_menu() {
	int choice;
	system("clear");
	std::cout << "Build Tree Menu\n"
			  << "1 - Keyboard input\n"
			  << "2 - File input\n"
			  << "3 - Quit\n"
			  << "Please choose: ";
	input_positiv_int(choice);
	// Убираем мусор из потока.
	std::cin.get();
	return choice;
}

// Вывод пунктов второго меню и выбор пункта.
int choise_main_menu() {
	int choice;
	system("clear");
	std::cout << "Main Menu\n"
			  << "1 - Add item\n"
			  << "2 - Delete item\n"
			  << "3 - Find item\n"
			  << "4 - Edit item\n"
			  << "5 - Print tree\n"
			  << "6 - Print with the same name\n"
			  << "7 - Print after a set time\n"
			  << "8 - Quit\n"
			  << "Please choose: ";
	input_positiv_int(choice);
	// Убираем мусор из потока.
	std::cin.get();
	return choice;
}

// Цикл второго меню.
void main_menu(bin_tree<train>& my_tree) {
	int choice;
	while (true) {
		choice = choise_main_menu();
		switch(choice) {
			case 1:
				input_one_item(my_tree);
				break;
			case 2:
				delete_item(my_tree);
				break;
			case 3:
				find_item(my_tree);
				std::cout << "Press enter...";
				read_enter();
				break;
			case 4:
				edit_item(my_tree);
				std::cout << "Press enter...";
				read_enter();
				break;
			case 5:
				my_tree.print();
				std::cout << "Press enter...";
				read_enter();
				break;
			case 6:
				print_with_same_name(my_tree);
				std::cout << "Press enter...";
				read_enter();
				break;
			case 7:
				print_after_set_time(my_tree);
				std::cout << "Press enter...";
				read_enter();
				break;
			case 8:
				system("clear");
				return;
			default:
				std::cout << "No such item\nPress enter...";
				read_enter();
				continue;
		}
	}
}

// Цикл первого меню.
void build_menu(bin_tree<train>& my_tree) {
	int choice;
	while (true) {
		choice = choise_build_menu();
		switch (choice) {
			case 1:
				input_tree(my_tree);
				break;
			case 2:
				file_input_tree(my_tree);
				std::cout << "Press enter...";
				read_enter();
				break;
			case 3:
				system("clear");
				return;
			default:
				std::cout << "No such item\nPress enter...";
				read_enter();
				continue;
		}
		break;
	}
	main_menu(my_tree);
}
