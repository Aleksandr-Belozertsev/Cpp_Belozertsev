#include "final.h"

int main() {
	try {
		Database db;
		string command_main;
		while (getline(cin, command_main)) {
			stringstream ss(command_main);
			string command;
			ss >> command;
			if (command == "add") {
				string date1, event;
				ss >> date1 >> event;
				const Date date = ParseDate(date1);
				db.AddEvent(date, event);

			}
			else if (command == "del"){
				string date2;
				ss >> date2;
				string event;
				if (!ss.eof()) {
					ss >> event;
				}
				const Date date = ParseDate(date2);
				if (event.empty()) {
					const int N = db.DeleteDate(date);
					cout << "Deleted " << N << " events" << endl;
				}
				else {
					if (db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
			}
			else if (command == "find") {
				string date3;
				ss >> date3;
				const Date date = ParseDate(date3);
				for (const string& event : db.Find(date)) {
					cout << event << endl;
				}
			}
			else if (command == "print") {
				db.Print();
			}
			else if (!command.empty()) {
				throw logic_error("Unknown command: " + command);
			}
		}
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
