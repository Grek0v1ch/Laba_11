#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include <iostream>

using str = std::string;

class train {
private:
	// Пункт назначения.
	str _destination_name;
	// Номер поезда.
	int _number;
	// Время отправки.
	str _departure_time;
public:
	train() : _destination_name(""), _number(0), _departure_time("00:00:00") {}
	train(const str&, const int, const str&);
	train(const train&);
	~train() {}

	str destination_name() const { return _destination_name; }
	str departure_time() const { return _departure_time; }

	friend std::ostream& operator<<(std::ostream&, const train&);

	train& operator=(const train&);

	// Если совпадают пункты назначения и время отправки, то сравниваем номера.
	// Если сопадают пункты назначения, то сравниваем время отправки.
	// Иначе сравниваем пункты назначения.
	int operator<(const train&) const;
	int operator>(const train&) const;
	int operator==(const train&) const;
};

#endif // TRAIN_HPP
