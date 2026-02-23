#include <string>
#include <stdexcept>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#pragma region DO NOT MODIFY
class person {
private:
	std::string name;
	int age;
	int id;
public:
	person() {
		name = "Unknown";
		age = 18;
		id = 1000000;
	}
	person(const std::string& name, int age, int id) {
		if (name.length() == 0) {
			throw std::invalid_argument("Name cannot be empty");
		}
		if (age < 0 || age > 120) {
			throw std::invalid_argument("Age must be between 0 and 120");
		}
		if (id < 0 || id > 9999999) {
			throw std::invalid_argument("Invalid ID");
		}
		this->name = name;
		this->age = age;
		this->id = id;
	}
	std::string get_name() const {
		return name;
	}
	int get_age() const {
		return age;
	}
	int get_id() const {
		return id;
	}
	friend std::ostream& operator<<(std::ostream& os, const person& p) {
		os << p.name << '(' << p.age << ") [" << p.id << ']';
		return os;
	}
};
void task_1(person[], int);
void task_2(person[], int);
void task_3(person[], int);
int main() {
	const int size = 20;
	person people[size] = {
	person("Thomas", 29, 4424053),
	person("Doug", 28, 3566351),
	person("Emily", 21, 1414265),
	person("Brandon", 33, 3327914),
	person("Sydney", 25, 4662533),
	person("Katie", 34, 7597009),
	person("Sean", 18, 9768190),
	person("Allison", 45, 1904318),
	person("Patrick", 39, 4257062),
	person("Thomas", 65, 9676529),
	person("Dan", 47, 5796922),
	person("Cheryl", 68, 3602379),
	person("Diane", 59, 7879547),
	person("Sean", 29, 3126082),
	person("Emily", 21, 8625939),
	person("Steve", 72, 9896929),
	person("Roger", 80, 6166000),
	person("Thomas", 19, 5166720),
	person("Jack", 34, 8831654),
	person("Veronica", 27, 1169289)
	};
	std::cout << "Names of Users in their 20s:" << std::endl;
	task_1(people, size);
	std::cout << std::endl << "Unique Names:" << std::endl;
	task_2(people, size);
	std::cout << std::endl << "Lookup Table:" << std::endl;
	task_3(people, size);
	return 0;
}
#pragma endregion
void task_1(person people[], int size) {
	// 1.1: Remove this exception
	std::vector<std::string> names_20;

	for (int i = 0; i < size; i++) {
		int age = people[i].get_age();
		if (age >= 20 && age < 30) {
			names_20.push_back(people[i].get_name());
		}
	}
	for (const std::string& name : names_20) {
		std::cout << name << std::endl;
	}
}
void task_2(person people[], int size) {
	std::set<std::string> unique_names;
	for (int i = 0; i < size; i++) {
		unique_names.insert(people[i].get_name());
	}
	std::cout << unique_names.size() << std::endl;
	for (const std::string& name : unique_names) {
		std::cout << name << std::endl;
	}

}
void task_3(person people[], int size) {
	std::map<int, person> ID;
	for (int i = 0; i < size; i++) {
		ID[people[i].get_id()] = people[i];
	}
	std::cout << ID.size() << std::endl;

	int ID1 = 9676529;
	int ID2 = 7879447;

	if (ID.count(ID1)) {
		std::cout << ID[ID1] << std::endl;
	}
	else {
		std::cout << "Person not found" << std::endl;
	}

	if (ID.count(ID2)) {
		std::cout << ID[ID2] << std::endl;
	}
	else {
		std::cout << "Person not found" << std::endl;
	}

	person name("Kylie McCray", 20, 7832954);
	ID[name.get_id()] = name;

	for (std::pair<const int, person> me : ID) {
		std::cout << me.first << " : " << me.second.get_name() << std::endl;
	}
}