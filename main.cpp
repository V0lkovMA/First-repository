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

int main() {
    // get user's data
    string name, surname, book;
    cin >> name >> surname >> book;

    // save to data.txt
    ofstream fout("data.txt", ios::app);
    fout << name << " " << surname << " " << book << "\n";
}
