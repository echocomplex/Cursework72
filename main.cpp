#include <iostream>
#include "List.h"
#include "University.h"
#include "Student.h"


void addStudent (University& unit) {
    std::string studentInfo;
    std::cout << std::endl << "Enter student info splitted by space. Rows: 1) number" << std::endl << 
        "2) first_name" << std::endl << "3) middle_name" << std::endl << "4) last_name" << std::endl << 
        "5) year" << std::endl << "6) birthday" << std::endl << "7) faculty" << std::endl << 
        "8) department" << std::endl << "9) group" << std::endl << "10) gender" << std::endl << 
        "11) subject" << std::endl << "12) date" << std::endl << "13) mark" << std::endl << ">>> ";
    std::cin >> studentInfo;
    std::istringstream iss(studentInfo);
    std::string token;
    unsigned int count = 0;
    Student student;
    grade g;
    while (std::getline(iss, token, ' ')) {
        if (count == 0) { student.setNumber(token); }
            else if (count == 1) { student.setFirstName(token); }
            else if (count == 2) { student.setMiddleName(token); }
            else if (count == 3) { student.setLastName(token); }
            else if (count == 4) { student.setYear(std::stoi(token)); }
            else if (count == 5) { student.setBirthday(token); }
            else if (count == 6) { student.setFaculty(token); }
            else if (count == 7) { student.setDepartment(token); }
            else if (count == 8) { student.setGroup(token); }
            else if (count == 9) { student.setGender(token); }
            else if (count == 11) { g.subject = token; }
            else if (count == 12) { g.date = token; }
            else if (count == 13) { g.mark = std::stoi(token); }
            ++count;
    }
    student.createSession();
    student.appendGradeToSession(1, g);
    unit.append(student);
    std::cout << "Success!" << std::endl;
}

void deleteStudent (University& unit) {
    std::string number;
    std::cout << "Enter student's number >>> ";
    std::cin >> number;
    Student student;
    student.setNumber(number);
    if (unit.isExists(student)) {
        unit.remove(unit.find(student));
        std::cout << "Success!" << std::endl;
    }
    else {
        std::cerr << "Student does not exists!" << std::endl;
    }
}

void sortGroup (University& unit) {
    std::string group;
    std::cout << "Enter group number >>> ";
    std::cin >> group;
    unsigned short session;
    std::cout << "Enter session number >>> ";
    std::cin >> session;
    if (std::cin.fail()) {
        std::cerr << "You entered not num! Try again." << std::endl;
        return;
    }
    Triple <List <std::pair <Student, float>>, List <std::pair <Student, float>>, List <std::pair <Student, float>>> result = unit.split(group, session);
    if ((result.first.length() == 0) && (result.second.length() == 0) && (result.third.length() == 0)) {
        throw std::logic_error("Group doesn't exist!");
    }
    std::cout << std::endl << "Grade 5:" << std::endl;
    for (int i = 0; i < result.first.length(); ++i) {
        std::cout << result.first[i].first.getNumber() << " >>> " << result.first[i].second << std::endl;
    }
    std::cout << std::endl << "Grade 4:" << std::endl;
    for (int i = 0; i < result.second.length(); ++i) {
        std::cout << result.second[i].first.getNumber() << " >>> " << result.second[i].second << std::endl;
    }
    std::cout << std::endl << "Grade 3:" << std::endl;
    for (int i = 0; i < result.third.length(); ++i) {
        std::cout << result.third[i].first.getNumber() << " >>> " << result.third[i].second << std::endl;
    }
}


int main () {
    // University::decrypt("data.enc", "data.txt");
    University unit("data.txt");

    int choice;
    std::cout << 
        "1. Add student" << std::endl << 
        "2. Delete student" << std::endl << 
        "3. Split group" << std::endl << 
        "4. Show table" << std::endl << std::endl << 
        ">>> ";
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cerr << "You entered not num! Try again." << std::endl;
        return 1;
    }

    switch (choice) {
        case 1:
            addStudent(unit);
            break;
        case 2:
            deleteStudent(unit);
            break;
        case 3:
            sortGroup(unit);
            break;
        case 4:
            std::cout << unit << std::endl;
            break;
        default:
            std::cerr << "You entered wrong num! Try again." << std::endl;
            return 1;
    }
    
    unit.toFile("data.txt");

    University::encrypt("data.txt", "data.enc");

    return 0;
}