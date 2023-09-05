#include<iostream>
#include<string>
#include "person.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <random>
#include <algorithm>
#include <chrono>
Person::Person(const std::string& firstNAME, const std::string& lastNAME,
  const std::string& id, const std::string& dob, const Account& acc)
{
  firstName = firstNAME;
  lastName = lastNAME;

  _id = id;
  _dob = dob;
  account = acc;
    _age = calculateAge(dob);
}

std::string Person::getDOB() const
{
  return _dob;
}
std::string Person::getfirstName() const
{
  return firstName;
}

std::string Person::getlastName() const
{
  return lastName;
}

int Person::getAge() const
{
  return _age;
}

std::string Person::getID() const
{
  return _id;
}


int Person::calculateAge(const std::string& dob) {
    // Check if dob string is not in the correct format (mm-dd-yyyy) then return -1
//    if(dob.size() > 10) {
//        std::cout << "Error: Invalid date format. Please use mm-dd-yyyy format.\n";
//        return -1;
//    }

    std::string yearStr = dob.substr(6, 4);
    std::string monthStr = dob.substr(0, 2);
    std::string dayStr = dob.substr(3, 2);

    int birthYear = std::stoi(yearStr);
    int birthMonth = std::stoi(monthStr);
    int birthDay = std::stoi(dayStr);


    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int age = currentYear - birthYear;

    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    return age;
}


std::string Person::generateID() {
    std::string id = "";
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "0123456789";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(0, chars.size() - 1);
    std::uniform_int_distribution<> dis2(0, numbers.size() - 1);

    do {

    // Add two random characters to the ID
    for (int i = 0; i < 2; i++) {
        id += chars[dis1(gen)];
    }

    // Add five random numbers to the ID
    for (int i = 0; i < 5; i++) {
        id += numbers[dis2(gen)];
    }

  } while (generatedIDs.find(id) != generatedIDs.end());

// Add the new ID to the set of generated IDs
    generatedIDs.insert(id);
    return id;
  }



std::vector<Person> searchByFirstName(const std::vector<Person>& people, std::string& inputFirst)
{
  std::vector<Person> result;

  for (const auto& person : people ) {
    if (person.getfirstName() == inputFirst) {
      result.push_back(person);
    }
  }

  if (result.empty())
  {
    std::cout<< "-------------------------------------------------------\n";
    std::cout << " No users with the searched name: "<<inputFirst<<"\n";
    std::cout<< "-------------------------------------------------------\n";
  }
  else
  {
    std::cout<<std::left << std::setw(9) <<"ID"
             <<std::left << std::setw(15)<<"First Name"
             <<std::left << std::setw(15)<<"Last Name"
             <<std::left << std::setw(4) <<"Age"
             <<std::left                 <<"D.O.B\n";
    for (const auto& infor : result)
    {
      std::cout<< "-----------------------------------------------------\n";
      std::cout<<std::left << std::setw(9)<<infor.getID()
               <<std::left << std::setw(15)<<infor.getfirstName()
               <<std::left << std::setw(15)<<infor.getlastName()
               <<std::left << std::setw(4)<< infor.getAge()
               <<std::left                <<infor.getDOB()<<"\n";
      std::cout<< "-----------------------------------------------------\n";
    }
  }
  return result;
}

std::vector<Person> readUsersFromFile() {
    std::vector<Person> people;
    std::ifstream inputFile("users_in4.txt");
    std::string line;

    // Skip the header line
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string id, firstName, lastName, dob;
        int age;

        if (!(iss >> id >> firstName >> lastName >> age >> dob)) {
            std::cerr << "Error reading line: " << line << "\n";
            continue;  // skip this line and continue with the next line
        }

        // Check if dob string is not in the correct format (mm-dd-yyyy) then skip this line
        if(dob.size() != 10) {
            std::cerr << "Error: Invalid date format. Please use mm-dd-yyyy format. Line: " << line << "\n";
            continue;  // skip this line and continue with the next line
        }

        people.emplace_back(firstName, lastName, id, dob);
    }

    inputFile.close();
    return people;
}

/*std::vector<Person> readUsersFromFile() {
  std::vector<Person> people;
  std::ifstream inputFile("users_in4.txt");
  std::string line;

  while (getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string firstName, lastName, id;

    std::string dob;

    if (iss >> firstName >> lastName >> id >> dob) {
      people.emplace_back(firstName, lastName, id, dob);
    }
  }

  inputFile.close();
  return people;
} */

/*void writeUsersToFile(const std::vector<Person>& users) {
  std::ofstream outputFile("users_in4.txt");

   // Make a copy of users and sort it by firstName
  std::vector<Person> sortedUsers = users;
    std::sort(sortedUsers.begin(), sortedUsers.end(), [](const Person& a, const Person& b)
        {
        return a.getfirstName() < b.getfirstName(); });
  outputFile <<std::left << std::setw(9) <<"ID"
             <<std::left << std::setw(15)<<"First Name"
             <<std::left << std::setw(15)<<"Last Name"
             <<std::left << std::setw(4) <<"Age"
             <<std::left                 <<"D.O.B\n";

  for (const auto& person : sortedUsers) {
    outputFile << std::left << std::setw(9) << person.getID()
               << std::left << std::setw(15)<< person.getfirstName()
               << std::left << std::setw(15)<< person.getlastName()
               << std::left << std::setw(4) << person.getAge()
               << std::left                 << person.getDOB()<<"\n";

  }

  outputFile.close();
} */
bool isFileEmpty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}


void writeUserToFile(const Person& user) {
    std::ifstream inFile("users_in4.txt");
    std::ofstream outputFile("users_in4.txt", std::ios::app);

    // If file is empty, add the column names
    if (isFileEmpty(inFile)) {
        outputFile << std::left << std::setw(9) << "ID"
                   << std::left << std::setw(15) << "First Name"
                   << std::left << std::setw(15) << "Last Name"
                   << std::left << std::setw(4) << "Age"
                   << std::left << "D.O.B\n";
    }
    inFile.close();

    // Write user to the file
    outputFile << std::left << std::setw(9) << user.getID()
               << std::left << std::setw(15) << user.getfirstName()
               << std::left << std::setw(15) << user.getlastName()
               << std::left << std::setw(4) << user.getAge()
               << std::left << user.getDOB() << "\n";

    outputFile.close();
}


void printUsersFromFile() {
  std::ifstream inputFile("users_in4.txt");
  std::string line;

  /*std::cout << "-------------------------------------\n";
  std::cout << "ID       First Name          Last Name           Age\n";
  std::cout << "-------------------------------------\n";*/

  while (std::getline(inputFile, line)) {
    std::cout << line << '\n';
  }

  inputFile.close();
}

std::vector<Person> people = readUsersFromFile();
std::vector<Account> accounts = readAccountFromFile();

// Assuming people and accounts are in the same order
for (size_t i = 0; i < people.size(); ++i) {
    people[i].setAccount(accounts[i]);
}

void writeAccountToFile(const Person& user) {
    std::ofstream outputFile("useraccount.txt", std::ios::app);

    // Write account to the file
    outputFile << std::left << std::setw(9) << user.getID()
               << std::left << std::setw(15) << user.getAccount().getUsername()
               << std::left << user.getAccount().getPassword() << "\n";

    outputFile.close();
}
