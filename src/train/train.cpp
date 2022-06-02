#include "train.hpp"
#include "../data_check/data_check.hpp"

train::train(const str& destination_name, const int number, const str& departure_time) :
	_destination_name(destination_name), _number(number), _departure_time(departure_time) {
		if (! check_time(departure_time)) throw str("train_error:bad_time");
	}

std::ostream& operator<<(std::ostream &output, const train& object) {
	output << "Номер поезда: " << object._number
		   << " Пункт назначения: " << object._destination_name
		   << " Время отправления: " << object._departure_time
		   << ' ';
	return output;
}

train::train(const train& object) :
	_destination_name(object._destination_name),
	_number(object._number),
	_departure_time(object._departure_time) {}

train& train::operator=(const train& object) {
	if (&object == this) return *this;
	_destination_name = object._destination_name;
	_number = object._number;
	_departure_time = object._departure_time;
	return *this;
}

int train::operator<(const train& object) const {
	// Если совпадают пункты назначения и время отправки, то сравниваем номера.
	// Если сопадают пункты назначения, то сравниваем время отправки.
	// Иначе сравниваем пункты назначения.
	if (_destination_name == object._destination_name && _departure_time == object._departure_time)
		return _number < object._number;
	if (_destination_name == object._destination_name)
		return _departure_time < object._departure_time;
	int min_idx = std::min(_destination_name.size(), object._destination_name.size());
	for (int i = 0; i < min_idx; i++)
		if (_destination_name[i] == object._destination_name[i])
			continue;
		else
			return _destination_name[i] < object._destination_name[i];
	return _destination_name.size() < object._destination_name.size();
}

int train::operator>(const train& object) const {
	// Если совпадают пункты назначения и время отправки, то сравниваем номера.
	// Если сопадают пункты назначения, то сравниваем время отправки.
	// Иначе сравниваем пункты назначения.
	if (_destination_name == object._destination_name && _departure_time == object._departure_time)
		return _number > object._number;
	if (_destination_name == object._destination_name)
		return _departure_time > object._departure_time;
	int min_idx = std::min(_destination_name.size(), object._destination_name.size());
	for (int i = 0; i < min_idx; i++)
		if (_destination_name[i] == object._destination_name[i])
			continue;
		else
			return _destination_name[i] > object._destination_name[i];
	return _destination_name.size() > object._destination_name.size();
}

int train::operator==(const train& object) const {
	return _destination_name == object._destination_name
		&& _number == object._number
		&& _departure_time == object._departure_time;
}