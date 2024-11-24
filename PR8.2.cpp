#include <iostream>
#include <string>
#include <algorithm> // For std::remove

using namespace std;

string TransformString(const string& input) {
    string result = input;

    //  Видалити групи пробілів, якими починається 
    size_t start = result.find_first_not_of(' ');
    if (start != string::npos) {
        result = result.substr(start);
    }
    else {
        return ""; // String only contains spaces
    }

    //  і якими закінчується рядок
    size_t end = result.find_last_not_of(' ');
    result = result.substr(0, end + 1);

    //  замінити кожну внутрішню групу пробілів одним пробілом
    string transformed;
    bool inSpace = false;

    for (char ch : result) {
        if (ch == ' ') {
            if (!inSpace) {
                transformed += ' ';
                inSpace = true;
            }
        }
        else {
            transformed += ch;
            inSpace = false;
        }
    }

    return transformed;
}

int main() {
    string str;
    cout << "Enter a string:" << endl;
    getline(cin, str);

    string transformed = TransformString(str);
    cout << "Transformed string: \"" << transformed << "\"" << endl;

    return 0;
}
