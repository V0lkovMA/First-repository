#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// print data

void print(int width) {
    width = max(width, 8);
    // open file
    ifstream fin("data.txt");
    string s;

    // output
    cout << "Name:";
    for (int i = 5; i < width; ++i)
        cout << " ";
    cout << "Surname:";
    for (int i = 8; i < width; ++i)
        cout << " ";
    cout << "Book:";
    for (int i = 5; i < width; ++i)
        cout << " ";
    cout << "\n";

    while (getline(fin, s)) {
        int it = 0;
        vector<string> v;
        while (it < s.size()) {
            int next = s.find(' ', it);
            v.push_back(s.substr(it, next - it));
            it = next + 1;
        }
        for (auto& t : v) {
            while (t.size() < width)
                t += ' ';
            cout << t;
        }
        cout << "\n";
    }
}

// add new user

void add() {
    // open files
    ifstream fin("questions.txt");
    ofstream fout("data.txt", ios::app);
    string q, s;

    // ask and add answers
    while (getline(fin, q)) {
        cout << q << "\n";
        cin >> s;
        fout << s << " ";
    }
    fout << "\n";
}

int main() {
    cout << "Enter 'add' to add user, 'print' to get data\n";
    string s;
    cin >> s;
    if (s == "add")
        add();
    else if (s == "print") {
        cout << "Enter table width\n";
        int width;
        cin >> width;
        print(width);
    }
}
