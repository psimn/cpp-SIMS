#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <cstring>
using namespace std;

string dictionary(int line) {
	switch (line)
	{
	case 11:
		return "No Student Infomation Found";
	case 12:
		return "Starting Import Process";
	case 21:
		return "Welcome to Student's Information Management System(SIMS)";
	case 22:
		return "   1.Import New Student's Information";
	case 23:
		return "   2.Print All Students' Information";
	case 24:
		return "   3.Search ONE Student's Average Point of Lecture(APL)";
	case 25:
		return "   4.Find and Output APL Top 5";
	case 26:
		return "   5.Calculate The Average Point of This Session";
	case 27:
		return "   0.Exit";
	case 28:
		return "Type an Integer: ";
	case 31:
		return "Success!";
	case 41:
		return "Plz select its sex: ";
	case 42:
		return "Female";
	case 43:
		return "Male";
	case 44:
		return "Neither";
	case 51:
		return "Press Enter to Continue...";
	case 52:
		return "Input Y(Case insensitive) and Press Enter to Continue...";
	case 61:
		return "a student name: ";
	case 62:
		return "sex";
	case 63:
		return "age";
	case 64:
		return "credit";
	case 65:
		return "grade";
	case 66:
		return "Calculating Course Points";
	case 67:
		return "Not even possible!!!";
	case 0:
		return ": ";
	}
}

void clear(void) {
	system("pause");
	system("cls");
}

void dot(void) {
	for (int i = 0; i < 3; ++i) {
		Sleep(250);
		cout << '.';
	}
	cout << endl;
}

void _default(void) {
	cout << dictionary(11) << endl;
	cout << dictionary(12);
	dot();
	cout << "Press Enter to Start" << endl;
}

void welcome(void) {
	for (int i = 21; i < 29; ++i) {
		cout << dictionary(i) << endl;
	}
}

void success(void) {
	cout << dictionary(31) << endl;
}

bool determine(void) {
	char ch;
	cin >> ch;
	if (ch == 'Y' || ch == 'y') {
		cin.clear();
		cin.ignore(1024, '\n');
		return true;
	}
	else {
		cin.clear();
		cin.ignore(1024, '\n');
		return false;
	}
}

class information
{
private:
	string name, sex;
	int age;
	double *credit, *grade, *point, avePoint;
	const int default_num = 3;
	unsigned short selection;
public:
	information();
	information(const information &obj);
	~information();
	int DNOL(void) const {
		return default_num;
	}
	string sexSelector(void);
	friend class process;
};

information::information()
{
	credit = new double[DNOL()];
	grade = new double[DNOL()];
	point = new double[DNOL()];
}

information::information(const information &obj) {
	name = obj.name;
	sex = obj.sex;
	age = obj.age;
	credit = new double[DNOL()];
	grade = new double[DNOL()];
	point = new double[DNOL()];
	for (int i = 0; i < DNOL(); ++i) {
		credit[i] = obj.credit[i];
		grade[i] = obj.grade[i];
		point[i] = obj.point[i];
	}
	avePoint = obj.avePoint;
}

information::~information()
{
	if (credit != NULL) {
		delete credit;
	}
	if (grade != NULL) {
		delete grade;
	}
	if (point != NULL) {
		delete point;
	}
}

string information::sexSelector(void) {
	cout << dictionary(41) << endl;
	cout << "1. " << dictionary(42) << endl;
	cout << "2. " << dictionary(43) << endl;
	cout << "0. " << dictionary(44) << endl;
	cin >> selection;
	if (selection == 1) {
		return dictionary(42);
	}
	else if (selection == 2)
	{
		return dictionary(43);
	}
	else {
		return dictionary(44);
	}
}

class storage
{
private:
	vector<information> students;
public:
	~storage();
	friend class process;
	void writeVector(information);
};

storage::~storage()
{
	if (students.empty() == false) {
		students.clear();
	}
}

void storage::writeVector(information temporary) {
	students.push_back(temporary);
}

class process
{
private:
	information temp;
	storage box;
	double sumCredits = 0, sumPoints = 0, sumPoint_Session = 0;
public:
	process();
	void tip_inputf(unsigned short, unsigned short);
	void tiny_inputf(unsigned short);
	void getInfo(unsigned short);
	void getCredit(void);
	void getGrade(void);
	void loopee_inputf(void);
	void calculatePoint(void);
	void averaglizePoint(void);
	void looper(void);
	bool selector(void);
	void readVector(int section);
	void readLists(double*, int);
	void looper_readVec(void);
	bool avePoint_Search(void);
	void pointSection(void);
	void PointPrint(void);
};

process::process()
{
	_default();
	looper();
}

void process::looper(void) {
	unsigned short count = 0;
	cout << dictionary(52) << endl;
	while (determine()) {
		loopee_inputf();
		++count;
		cout << dictionary(52) << endl;
	}
	if (count != NULL) {
		cout << "You add " << count << " students' information SUCCESSFULLY!" << endl;
	}
	else {
		cout << "No Student information Added!" << endl;
	}
	clear();
}

void process::tip_inputf(unsigned short select, unsigned short sex_define) {
	string pronoun;
	const string repeat = "Please type ";
	if (sex_define == NULL)
	{
		pronoun = "its ";
	}
	else if (sex_define == 1)
	{
		pronoun = "her ";
	}
	else
	{
		pronoun = "his ";
	}
	switch (select)
	{
	case 0:
		cout << repeat << dictionary(61);
		break;
	case 1:
		cout << repeat << pronoun << dictionary(62) << endl;
		break;
	case 2:
		cout << repeat << pronoun << dictionary(63) << dictionary(0);
		break;
	case 3:
		cout << repeat << pronoun << dictionary(64) << endl;
		break;
	case 4:
		cout << repeat << pronoun << dictionary(65) << endl;
		break;
	case 5:
		cout << dictionary(66);
		break;
	default:
		cout << dictionary(67) << endl;
		break;
	}
}

void process::tiny_inputf(unsigned short select) {
	tip_inputf(select, temp.selection);
	getInfo(select);
}

void process::getInfo(unsigned short select) {
	switch (select)
	{
	case 0:
		cin >> temp.name;
		break;
	case 1:
		temp.sex = temp.sexSelector();
		break;
	case 2:
		cin >> temp.age;
		break;
	case 3:
		getCredit();
		break;
	case 4:
		getGrade();
		break;
	case 5:
		dot();
		calculatePoint();
		break;
	default:
		cout << dictionary(67) << endl;
		break;
	}
}

void process::getCredit(void) {
	for (unsigned short i = 0; i < temp.default_num; ++i) {
		cout << dictionary(64) << " No." << i + 1 << dictionary(0);
		cin >> temp.credit[i];
		sumCredits += temp.credit[i];
	}
}

void process::getGrade(void) {
	for (unsigned short i = 0; i < temp.default_num; ++i) {
		cout << dictionary(65) << " No." << i + 1 << dictionary(0);
		cin >> temp.grade[i];
	}
}

void process::loopee_inputf(void) {
	for (int i = 0; i < 6; ++i) {
		tiny_inputf(i);
	}
	averaglizePoint();
	box.writeVector(temp);
}

void process::calculatePoint(void) {
	for (unsigned short i = 0; i < temp.default_num; ++i) {
		if (temp.grade[i] >= 60) {
			temp.point[i] = 4 - 3 * (100 - temp.grade[i]) / 40;
			sumPoints += temp.point[i];
		}
		else
		{
			temp.point[i] = 0;
		}
	}
}

void process::averaglizePoint(void) {
	temp.avePoint = sumPoints / sumCredits;
}

bool process::selector(void) {
	unsigned short num;
	cin >> num;
	switch (num)
	{
	case 1:
		looper();
		break;
	case 2:
		looper_readVec();
		break;
	case 3:
		avePoint_Search();
		break;
	case 4:
		PointPrint();
		break;
	case 5:
		pointSection();
		break;
	case 0:
		return true;
	default:
		cout << "Invalid Number!!!" << endl;
		clear();
		break;
	}
	return false;
}

void process::looper_readVec(void) {
	for (int i = 0; i < box.students.size(); ++i) {
		readVector(i);
	}
	success();
	clear();
}

bool process::avePoint_Search(void) {
	string NAME;
	cout << "Plz type name supposed to be searched: ";
	cin >> NAME;
	for (int i = 0; i < box.students.size(); ++i) {
		if (NAME == box.students[i].name) {
			cout << "Information was Found!" << endl;
			cout << "Average Point is " << box.students[i].avePoint << endl;
			clear();
			return true;
		}
	}
	cout << "Unknown Name!!!" << endl;
	clear();
}

void process::readVector(int section) {
	cout << "\n";
	cout << "ID: " << section + 1 << endl;
	cout << "Name: " << box.students[section].name << endl;
	cout << "Sex: " << box.students[section].sex << endl;
	cout << "Age: " << box.students[section].age << endl;
	cout << "Credits: ";
	readLists(box.students[section].credit, section);
	cout << "Grades: ";
	readLists(box.students[section].grade, section);
	cout << "Average Point: " << box.students[section].avePoint << endl;
	cout << "\n";
}

void process::readLists(double *list, int section) {
	for (int i = 0; i < box.students[section].DNOL(); ++i) {
		cout << list[i] << "  ";
	}
	cout << endl;
}

void process::pointSection(void) {
	for (int i = 0; i < box.students.size(); ++i) {
		sumPoint_Session += box.students[i].avePoint;
	}
	cout << "Average Point of this Section is " << sumPoint_Session / box.students.size() << endl;
	clear();
}

void process::PointPrint(void) {
	vector<information> sorted;
	vector<double> temp;
	for (int i = 0; i < box.students.size(); ++i) {
		temp.push_back(box.students[i].avePoint);
	}
	while (temp.size() != NULL) {
		double n = temp.at(0);
		int m = 0; 
		for (int i = 1; i < temp.size(); ++i) { 
			if (temp.at(i) < n) { 
				n = temp.at(i); 
				m = i; 
			}
		}
		sorted.push_back(box.students.at(m));
		temp.erase(temp.begin() + m);
	}
	temp.clear();
	cout << "Top 5 List" << endl;
	for (int i = 0; i < 5; ++i) {
		if (sorted.size() == i) {
			break;
		}
		cout << "No." << i + 1 << "--" << sorted.at(i).name << "--" << sorted.at(i).avePoint << endl;
	}
	sorted.clear();
	clear();
}