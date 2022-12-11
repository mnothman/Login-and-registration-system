#include <iostream>
#include <string>
#include <fstream>

// function to check if a user with the specified username already exists in our system
bool username_exists(const std::string& username) {
    // open the user file for the specified username in read-only mode
    std::ifstream user_file(username + ".txt");

    // check if the file was successfully opened
    if (user_file.is_open()) {
        // if the file was successfully opened, it means that a user with the specified username already exists
        return true;
    }

    // if the file could not be opened, it means that the user does not exist
    return false;
}

// function to create a new user file with the specified username and password
void create_user_file(const std::string& username, const std::string& password) {
    // open the user file for the specified username in write mode
    std::ofstream user_file(username + ".txt");

    // write the username and password to the user file
    user_file << username << std::endl << password;

    // close the user file
    user_file.close();
}

// function to register a new user
void register_user() {
    // ask the user for their desired username and password
    std::cout << "Enter your desired username: ";
    std::string username;
    std::cin >> username;

    std::cout << "Enter your desired password: ";
    std::string password;
    std::cin >> password;

    // check if a user with the entered username already exists
    if (username_exists(username)) {
        std::cout << "Sorry, that username is already taken. Please try a different one." << std::endl;
        return;
    }

    // if the username does not already exist, create a new user file with the entered credentials
    create_user_file(username, password);
    std::cout << "Registration successful! You can now log in with your new credentials." << std::endl;
}

// function to verify the entered password for the specified user
bool verify_password(const std::string& username, const std::string& password) {
    // open the user file for the specified username in read-only mode
    std::ifstream user_file(username + ".txt");

    // check if the file was successfully opened
    if (user_file.is_open()) {
        // if the file was successfully opened, read the stored username and password from the file
        std::string stored_username;
        std::string stored_password;
        user_file >> stored_username >> stored_password;

        // compare the entered password with the stored password
        if (password == stored_password) {
            // if the entered password matches the stored password, return true
            return true;
        }
    }

    // if the entered password does not match the stored password, or if the user file could not be opened, return false
    return false;
}

// function to log in an existing user
void login() {
    // ask the user for their username and password
    std::cout << "Enter your username: ";
    std::string username;
    std::cin >> username;

    std::cout << "Enter your password: ";
    std::string password;
    std::cin >> password;

    // check if a user with the entered username exists in our system
    if (!username_exists(username)) {
        std::cout << "Sorry, that username does not exist. Please try again or register a new account." << std::endl;
        return;
    }

    // if the username exists, verify that the entered password matches the stored password for that user
    if (!verify_password(username, password)) {
        std::cout << "Sorry, that password is incorrect. Please try again." << std::endl;
        return;
    }

    std::cout << "Login successful! Welcome back, " << username << "." << std::endl;
}

int main() {
    // register a new user
    register_user();

    // log in an existing user
    login();

    return 0; // indicate successful program execution
}

//saves the login on the computer as a txt file named as the inputted username