#include <iostream>
using namespace std;

class String {
private:
    int len;
    char* string = new char;
public:
    String() {
        len = 0;
        string = new char[1];
        string[0] = '\0';
    }
    String(const char* str) {
        len = strlen(str);
        string = new char[len + 1];
        strcpy(string, str);
    }

    String(const String& str) {
        len = str.len;
        string = new char[len + 1];
        strcpy(string, str.string);

    }

    String operator=(const String& str) {
        delete[] string;
        len = str.len;
        string = new char[len + 1];
        strcpy(string, str.string);
        return *this;
    }

    ~String() {
        delete[] string;
    }

    String operator+(const String& str) {
        String newString;
        newString.len = len + str.len;
        newString.string = new char[newString.len + 1];
        strcpy(newString.string, string);
        strcat(newString.string, str.string);
        return newString;
    }

    String operator+=(const String& str) {
        char* tmp = new char[len + str.len + 1];
        strcpy(tmp, string);
        strcat(tmp, str.string);
        delete string;
        string = tmp;
        len = len + str.len;
        return *this;
    }

    char operator[](int i) {
        return string[i];
    }
    bool operator<(const String& str) {
        return strcmp(string, str.string) < 0;
    }

    bool operator>(const String& str) {
        return strcmp(string, str.string) > 0;
    }

    bool operator==(const String& str) {
        return strcmp(string, str.string) == 0;
    }
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.string;
        return os;

    }

    friend istream& operator>>(istream& is, String& str) {
        const int max_size = 256;
        char input[max_size];
        if (is.getline(input, max_size)) {
            str.len = strlen(input);
            str.string = new char[str.len + 1];
            strcpy(str.string, input);
        }
        return is;

    }

    int find(char a) {
        for (int i = 0; i < len; i++) {
            if (string[i] == a){
                return i;
            }
        }
    }

    int lenght() {
        return len;
    }

    char* c_str() const {
        return string;
    }
    char& at(int i) {
        if (i >= 0 && i < len) return string[i];
    }
};

int main()
{
    String s1;
    String s2;
    String s3;

    cin >> s1;

    cin >> s2;

    cout << s1 << endl;
    cout << s2 << endl;
    s3 = s1 + s2;
    cout << s3 << endl;

    s1 += s2;
    cout << s1[0] << endl;
    s1.at(0) = 'G';
    cout << s1 << endl;
}

