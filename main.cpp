#include <iostream>
#include <fstream>

using namespace std;

// print data

void print() {
    // open file
    ifstream fin("data.txt");
    string s;

    // output
    while (getline(fin, s))
        cout << s << "\n";
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
    add();
    //print();
}
