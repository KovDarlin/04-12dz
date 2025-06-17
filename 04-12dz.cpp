#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
	string name;
	string position;
	int salary;
	Employee(const string& n, const string& p, int s): name(n), position(p), salary(s){}
};

int main() {
	vector<Employee> employees = {
		Employee("Marina", "HR", 25000),
		Employee("Kolia", "Designer", 15000),
		Employee("Daryna", "WEB-developer", 87000)
	};
	vector<string> information;
	information.reserve(employees.size());

	transform(employees.begin(), employees.end(), back_inserter(information),
		[](const Employee& emp) {
			return emp.name + " - " + emp.position;
		});
	cout << "List our employee: \n";
	for (const auto& info : information) {
		cout << info << endl;
	}
}