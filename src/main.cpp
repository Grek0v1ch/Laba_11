#include "bin_tree/bin_tree.hpp"
#include "menu/menu.hpp"
#include "train/train.hpp"

int main() {
	// Cоздаем дерево с поездами и вызываем первую функцию меню.
	bin_tree<train> my_tree;
	build_menu(my_tree);
	return 0;
}
