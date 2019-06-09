#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		if (new_month > 12 || new_month < 1) {
			throw logic_error("Month value is invalid: " + to_string(new_month));
		}
		month = new_month;
		if (new_day > 31 || new_day < 1) {
			throw logic_error("Day value is invalid: " + to_string(new_day));
		}
		day = new_day;
	}

	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-' << setw(2)
		<< date.GetMonth() << '-' << setw(2) << date.GetDay();
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0 && data[date].count(event) > 0) {
			data[date].erase(event);
			return true;
		}
		return false;
	}

	int DeleteDate(const Date& date) {
		if (data.count(date) == 0) {
			return 0;
		}
		else {
			int N = data[date].size();
			data.erase(date);
			return N;
		}
	}

	set<string> Find(const Date& date) const {
		if (data.count(date) > 0) {
			return data.at(date);
		}
		else {
			return{};
		}
	}
	void Print() const {
		for (const auto& item : data) {
			for (const string& event : item.second) {
				cout << item.first << " " << event << endl;
			}
		}
	}
private:
	map<Date, set<string>> data;
};

Date ParseDate(const string& date) {
	istringstream date_stream(date);
	bool pd = true;

	int year;
	pd = pd && (date_stream >> year);
	pd = pd && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	pd = pd && (date_stream >> month);
	pd = pd && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	pd = pd && (date_stream >> day);
	pd = pd && date_stream.eof();

	if (!pd) {
		throw logic_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}
