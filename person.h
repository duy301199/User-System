#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include <unordered_set>
#include <algorithm>

class Account {
private:
    std::string username;
    std::string password;

public:
    Account() : username(""), password("") {}
    Account(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
};

class Person {
private:
    std::string firstName, lastName, _id, _dob;
    int _age;
    Account account;

public:
    Person();
    Person(const std::string& firstNAME, const std::string& lastNAME, const std::string& id,
           const std::string& dob, const Account& acc);

    std::string getfirstName() const;
    std::string getlastName() const;
    int getAge() const;
    std::string getID() const;
    std::string getDOB() const;
    std::string generateID();
    Account getAccount() const { return account; }
    int calculateAge(const std::string& dob);

    std::unordered_set<std::string> generatedIDs; //store previous set of generateID
};

bool isFileEmpty(std::ifstream& pFile);

std::vector<Person> searchByFirstName(const std::vector<Person>& people, std::string& inputFirst);
std::vector<Person> readUsersFromFile();
//void writeUsersToFile(const std::vector<Person>& users);
void writeUserToFile(const Person& user);
void printUsersFromFile();
void writeAccountToFile(const Person& user);

#endif // PERSON_H
