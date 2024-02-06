#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    double gpa;

    bool operator<(const Student& other) const {
        if (gpa != other.gpa) {
            return gpa < other.gpa;
        } else if (lastName != other.lastName) {
            return lastName < other.lastName;
        } else {
            return firstName < other.firstName;
        }
    }
};

double getGPA(const string& grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    return 0.00; // F
}

int main() {
    int n;
    cin >> n;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        string lastName, firstName;
        int m;
        cin >> lastName >> firstName >> m;
        double totalGrade = 0.0;
        int totalCredits = 0;

        for (int j = 0; j < m; ++j) {
            string grade;
            int credits;
            cin >> grade >> credits;
            totalGrade += getGPA(grade) * credits;
            totalCredits += credits;
        }

        Student student;
        student.lastName = lastName;
        student.firstName = firstName;
        student.gpa = totalGrade / totalCredits;
        students.push_back(student);
    }

    sort(students.begin(), students.end());

    for (const Student& student : students) {
        cout << student.lastName << " " << student.firstName << " " << fixed << setprecision(3) << student.gpa << endl;
    }

    return 0;
}