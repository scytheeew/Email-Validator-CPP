
#include <iostream>
#include <string>
using namespace std;

// Function to check if email contains '@'
bool containsAtSymbol(const string& email) {
    return email.find('@') != string::npos;
}

// Function to validate the local part (before '@')
bool validateLocalPart(const string& localPart) {
    for (char ch : localPart) {
        if (!(isalnum(ch) || ch == '.' || ch == '_' || ch == '%' || ch == '+' || ch == '-')) {
            return false;
        }
    }
    return !localPart.empty();
}

// Function to validate the domain part (after '@')
bool validateDomain(const string& domain) {
    size_t dotPosition = domain.find('.');
    if (dotPosition == string::npos || dotPosition == 0 || dotPosition == domain.length() - 1) {
        return false;
    }
    for (char ch : domain) {
        if (!(isalnum(ch) || ch == '.' || ch == '-')) {
            return false;
        }
    }
    return true;
}

// Function to validate the email structure
bool validateEmail(const string& email) {
    size_t atPosition = email.find('@');
    if (atPosition == string::npos || atPosition == 0 || atPosition == email.length() - 1) {
        return false; // Missing '@' or misplaced
    }

    string localPart = email.substr(0, atPosition);
    string domain = email.substr(atPosition + 1);

    return validateLocalPart(localPart) && validateDomain(domain);
}

int main() {
    string email;

    // Input email from the user
    cout << "Enter an email address to validate: ";
    getline(cin, email);

    // Process validation steps
    if (!containsAtSymbol(email)) {
        cout << "Invalid email: Missing '@' symbol." << endl;
    }
    else if (!validateEmail(email)) {
        cout << "Invalid email: Incorrect structure or invalid characters." << endl;
    }
    else {
        cout << "The email address is valid." << endl;
    }

    return 0;
}

