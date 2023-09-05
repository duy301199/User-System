//Terminal cd Desktop ->
// cd Coding -> clang++ -std=c++17 -o hello hello.cpp person.cpp
// ./hello
//control + C to quit

#include<iostream>
#include<string>
#include<vector>
#include"person.h"

int main() {
  Person p;
  std::vector<Person> people = readUsersFromFile();

  std::cout<< "-------------------------------------\n";
  std::cout<< " Welcome to the program\n";
  std::cout<< "-------------------------------------\n";
  std::cout<< " Please choose your role: \n";
  std::cout<< " 1. User\n";
  std::cout<< " 2. Administrator\n";
  std::cout<< " q. To exit\n";
  std::cout<< "-------------------------------------\n";

  char roleChoice;
  std::cin >> roleChoice;

  if (roleChoice == '1') { // User role
    while (true) {
      std::cout<< " Please choose an option to proceed: \n";
      std::cout<< " 1. Create New Account\n";
      std::cout<< " q. To exit\n";
      std::cout<< "-------------------------------------\n";

      char userChoice;
      std::cin >> userChoice;

      if (userChoice == '1') {
        std::string firstName, lastName, dob, username, password;

        std::cout<< "Enter your first name: ";
        std::cin>>firstName;

        std::cout<< "Enter your last name: ";
        std::cin>>lastName;

        // Validate DOB
        bool validMonth = false;
        bool validDay = false;
        while (!validMonth || !validDay) {
            std::cout << "Enter your DoB in mm-dd-yyyy: ";
            std::cin >> dob;

            std::string monthStr = dob.substr(0, 2);
            std::string dayStr = dob.substr(3, 2);
            int month = std::stoi(monthStr);
            int day = std::stoi(dayStr);

            if (month > 12 || month < 1) {
                std::cout << "Month is not valid. Please enter a number between 1 and 12.\n";
            } else {
                validMonth = true;
            }

            if (day > 31 || day < 1) {
                std::cout << "Day is not valid. Please enter a number between 1 and 31.\n";
            } else {
                validDay = true;
            }
        }

        std::cout<< "Create your username: ";
        std::cin >> username;

        std::cout<< "Create your password: ";
        std::cin >> password;

        Account account(username, password);

        std::string iD = p.generateID();
        std::cout<< "-------------------------------------\n";
        std::cout<< " Your assigned ID is " << iD <<"\n";

        Person newUser(firstName, lastName, iD, dob, account);
        people.push_back(newUser);

        writeUserToFile(newUser);
        writeAccountToFile(newUser);

        std::cout << " Your information has been recorded\n";
        std::cout<< "-------------------------------------\n";
      } else if ( userChoice == 'q' || userChoice == 'Q') {
        std::cout<< "-------------------\n";
        std::cout << "Exiting program...\n";
        std::cout<< "-------------------\n";
        break; // This will break the while loop and end the program
      } else {
        std::cout<< "-------------------------------------\n";
        std::cout << " Invalid choice. Please try again.\n";
        std::cout<< "-------------------------------------\n";
      }
    }
  } else if (roleChoice == '2') { // Administrator role
    while (true) {
      std::cout<< " Please choose an option to proceed: \n";
      std::cout<< " 1. Search For Existing User\n";
      std::cout<< " 2. View All Users\n";
      std::cout<< " 3. Delete Existing User - COMING SOON\n";
      std::cout<< " q. To exit\n";
      std::cout<< "-------------------------------------\n";

      char adminChoice;
      std::cin >> adminChoice;

      if (adminChoice == '1') {
        std::string inputFirst;

        std::cout<<" Enter user's first name to search for user's information: ";
        std::cin >> inputFirst;

        std::vector<Person> result = searchByFirstName(people, inputFirst);
      } else if (adminChoice == '2') {
        printUsersFromFile();
      /* } else if (adminChoice == '3') {
        // code to delete a user
      */
      } else if ( adminChoice == 'q' || adminChoice == 'Q') {
        std::cout<< "-------------------\n";
        std::cout << "Exiting program...\n";
        std::cout<< "-------------------\n";
        break; // This will break the while loop and end the program
      } else {
        std::cout<< "-------------------------------------\n";
        std::cout << " Invalid choice. Please try again.\n";
        std::cout<< "-------------------------------------\n";
      }
    }
  } else if ( roleChoice == 'q' || roleChoice == 'Q') {
    std::cout<< "-------------------\n";
    std::cout << "Exiting program...\n";
    std::cout<< "-------------------\n";
    return 0;
  } else {
    std::cout<< "-------------------------------------\n";
    std::cout << " Invalid role choice. Please try again.\n";
    std::cout<< "-------------------------------------\n";
  }

  return 0;
}

/*
#include<iostream>
#include<string>
#include<vector>
#include"person.h"
x
int main() {
  Person p;
  std::vector<Person> people = readUsersFromFile();

  while (true) {
    std::cout<< "-------------------------------------\n";
    std::cout<< " Welcome to the program\n";
    std::cout<< "-------------------------------------\n";
    std::cout<< " Please choose an option to proceed: \n";
    std::cout<< " 1. Create New User\n";
    std::cout<< " 2. Search For Existing User\n";
    std::cout<< " 3. All users information\n";
    std::cout<< " 4. Delete Existing User - COMING SOON\n";
    std::cout<< " q. To exit\n";
    std::cout<< "-------------------------------------\n";

    char choice;
    std::cin >> choice; */

    /*if (choice == '1')
    {
      std::string firstName, lastName, dob;
      int age;

      std::cout<< "Enter your first name: ";
      std::cin>>firstName;

      std::cout<< "Enter your last name: ";
      std::cin>>lastName;

      //std::cout<< "Enter your age: ";
      //std::cin>> age;

      std::cout<< "Enter your DoB in mm-dd-yyyy: ";
      std::cin>> dob;

      std::string iD = p.generateID();
      std::cout<< "-------------------------------------\n";
      std::cout<< " Your assigned ID is " << iD <<"\n";

      people.push_back(Person(firstName, lastName, iD, dob));

      std::cout << " Your information has been recorded\n";
      std::cout<< "-------------------------------------\n";

      writeUsersToFile(people);*/
/*      if (choice == '1')
      {
        std::string firstName, lastName, dob, username, password;

        std::cout<< "Enter your first name: ";
        std::cin>>firstName;

        std::cout<< "Enter your last name: ";
        std::cin>>lastName;

/*
        // Flags to check date and month
        bool validMonth = false;
        bool validDay = false;
        while (!validMonth || !validDay) {
            std::cout << "Enter your DoB in mm-dd-yyyy: ";
            std::cin >> dob;

            std::string monthStr = dob.substr(0, 2);
            std::string dayStr = dob.substr(3, 2);
            int month = std::stoi(monthStr);
            int day = std::stoi(dayStr);

            if (month > 12 || month < 1) {
                std::cout << "Month is not valid. Please enter a number between 1 and 12.\n";
            } else {
                validMonth = true;
            }

            if (day > 31 || day < 1) {
                std::cout << "Day is not valid. Please enter a number between 1 and 31.\n";
            } else {
                validDay = true;
            }
          }

        /*std::cout << "Enter your DoB in mm-dd-yyyy: ";
        std::cin >> dob;
        std::cout<< "Enter your DoB in mm-dd-yyyy: ";
        std::cin>> dob; */
/*        std::cout<< "Create your username: ";
        std::cin >> username;

        std::cout<< "Create your password: ";
        std::cin >> password;

        std::string iD = p.generateID();
        std::cout<< "-------------------------------------\n";
        std::cout<< " Your assigned ID is " << iD <<"\n";

        Person newUser(firstName, lastName, iD, dob, username, password);
          auto insertPos = std::lower_bound(people.begin(), people.end(), newUser,
            [](const Person& a, const Person& b) { return a.getfirstName() < b.getfirstName(); });
            people.insert(insertPos, newUser);

        writeUserToFile(newUser);

        std::cout << " Your information has been recorded\n";
        std::cout<< "-------------------------------------\n";

    }
    else if ( choice == '2')
    {
      std::string inputFirst;

      std::cout<<" Enter user's first name to search for user's information: ";
      std::cin >> inputFirst;

      std::vector<Person> result = searchByFirstName(people, inputFirst);


      }
    else if ( choice == '3')
    {
      printUsersFromFile();
    }

  /*  else if (choice == '4') {
      std::string id;
      std::cout << "Enter user's ID to delete user's information: ";
      std::cin >> id;

      auto it = std::find_if(people.begin(), people.end(), [&](const Person& person) {
          return person.getID() == id;
      });

      if (it != people.end()) {
          people.erase(it);
          std::cout << "User deleted successfully.\n";
          writeUsersToFile(people);
        }
      else {
          std::cout << "User not found.\n";
        } */


/*    else if ( choice == 'q' || choice == 'Q') {
      std::cout<< "-------------------\n";
      std::cout << "Exiting program...\n";
      std::cout<< "-------------------\n";
      break; // This will break the while loop and end the program
    }
    else {
      std::cout<< "-------------------------------------\n";
      std::cout << " Invalid choice. Please try again.\n";
      std::cout<< "-------------------------------------\n";
    }
  }
  return 0;
}
*/
