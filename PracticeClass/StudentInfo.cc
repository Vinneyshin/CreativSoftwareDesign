#include <string>
#include <vector>

#include <iostream>

using namespace std;

struct StudentInfo
{
public:
	StudentInfo(int _id, string _name, int _score) {
		cout << "StudentInfo" << endl;
		id = _id;
		name = _name;
		score = _score;
	}

	~StudentInfo() {
		cout << "~StudentInfo" << endl;
	}


	int ShowInfo() const {
		cout << id << "|" << name << "|" << score << endl;

		return 0;
	}

	int id;
	string name;

private:
	int score;
};

class StudentInfoEx : protected StudentInfo
{
public:
	StudentInfoEx(int _id, string _name, int _score) : StudentInfo(_id, _name, _score) {
		cout << "StudentInfoEx" << endl;
	}

	~StudentInfoEx() {
		cout << "~StudentInfoEx" << endl;
	}

	string GetName();
};

string StudentInfoEx::GetName() {
	return name;
}



class StudentVector {
public:
	StudentVector() {}
	~StudentVector (){}
	int AddStudent(const string& _name, const int _id, const int _score);
	bool CheckDuplicateId(int _id) const;
	int RemoveStudent(const string& str);
	int ShowStudents() const;
	int GetStudentByIndex(int num) const;
private:
	vector<StudentInfo*> student_vec;
};

bool StudentVector::CheckDuplicateId(int _id) const {
	vector<StudentInfo*>::const_iterator pos;

	for (pos = student_vec.begin(); pos != student_vec.end(); ++pos) {
		if ((*pos) -> id == _id) {
			return false;
		}
	}
	return true;
}

int StudentVector::AddStudent(const string& _name, const int _id, const int _score) {
	
	StudentInfo *psi = new StudentInfo(_id, _name, _score);
	
	if (CheckDuplicateId(_id) == false) {
		cout << "[Error] Duplicated ID : " << _id << ", Name: " << _name << endl;
		return -1;
	}

	student_vec.push_back(psi);

	psi->name = "shelock";
	return 0;
}

int StudentVector::ShowStudents() const {
	vector<StudentInfo*>::const_iterator pos;
	cout << "\nStudent List: " << endl;

	for (pos = student_vec.begin(); pos != student_vec.end(); ++pos) {
		(*pos)->ShowInfo();
	}
	return 0;
}

int main() {
	StudentVector sv;

	sv.AddStudent("Yuna Kim", 1, 100);
	sv.AddStudent("JS Han", 2, 99);
	sv.AddStudent("LW RO", 2, 77);

	sv.ShowStudents();

	cout << "---------------------" << endl;

	StudentInfoEx * psie = new StudentInfoEx(3, "IW RO", 95);
	delete psie;

	return 0;
}


