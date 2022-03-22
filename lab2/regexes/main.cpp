#include <iostream>
#include <fstream>
#include <regex>

int main() {

#if 1
    /**  One. Find URL address inside the text provided. **/

    std::ifstream inputFileStream("../one.txt");
    std::stringstream bufferStringStream;
    bufferStringStream << inputFileStream.rdbuf();
    std::string fileAsString = bufferStringStream.str();

    std::regex pattern(R"(https:*\W+[\w._/+]{3,})");
    std::sregex_iterator currentMatch(
            fileAsString.begin(),
            fileAsString.end(),
            pattern
            );
    std::sregex_iterator finalMatch;

    std::cout << "Task 1 matches:\n";
    while (currentMatch != finalMatch) {
        std::cout << currentMatch->str() << '\n';
        currentMatch ++;
    }

#endif
#if 0
    /**
     * Two/Three.  Check whether password provided by the user is valid.
     *
     * Valid means:
     *   -at least 8 characters
     *   -at least 1 capital letter
     *   -at least 1 lower letter
     *   -at least 1 number
     *
     *   -at least 1 special char
     **/

    std::string password;
    std::cout << "Your password > ";
    std::cin >> password;

    std::regex validPasswordPattern(
            R"(^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[^ a-zA-Z0-9]).{8,}$)"
    );

    if (!std::regex_match(password, validPasswordPattern)) {
        std::cout << "Weak password" << std::endl;
    } else {
        std::cout << "Strong password\n";
    }


    /** Four/Five. Find spec. chars **/

    std::regex specialCharsPattern("([^ a-zA-Z0-9]+)");
    std::sregex_iterator currentMatch(password.begin(), password.end(), specialCharsPattern);
    std::sregex_iterator finalMatch;

    std::cout << "Task 4/5 matches:\n";
    while (currentMatch != finalMatch) {
        std::cout << currentMatch->str() << " at " << currentMatch->position() << "\n";
        currentMatch ++;
    }

#endif
#if 0
    /**  Six. From list provided output all valid email addresses. **/
    std::ifstream inputFileStream("../five.txt");
    std::stringstream bufferStringStream;
    bufferStringStream << inputFileStream.rdbuf();
    std::string fileAsString = bufferStringStream.str();

    std::regex validEmailPattern ("([a-zA-Z0-9.]+@[a-zA-Z]+\\.[a-zA-Z.]{2,})");;
    std::sregex_iterator currentMatch (fileAsString.begin(), fileAsString.end(), validEmailPattern);
    std::sregex_iterator finalMatch;

    /**  Seven. Write only valid emails into a file. (Saved to cmake-build-debug folder) **/
    std::ofstream outputFilestream("validEmails.txt");
    std::cout << "Task 7 matches:\n";
    while (currentMatch != finalMatch) {
        std::cout << currentMatch->str() << "\n";
        outputFilestream << currentMatch->str() << "\n";
        currentMatch ++;
    }

    /**  Eight. In all email addresses which end with ".ru" replace it by ".pl". **/
    currentMatch = {fileAsString.begin(), fileAsString.end(), validEmailPattern};
    while (currentMatch != finalMatch) {
        std::cout << std::regex_replace(currentMatch->str(), std::regex(".ru"), ".ua") << "\n";
        currentMatch++;
    }

#endif

    return 0;
}
