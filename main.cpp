#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // get user's data
    string name, surname, book;
    cin >> name >> surname >> book;

    // save to data.txt
    ofstream fout("data.txt", ios::app);
    fout << name << " " << surname << " " << book << "\n";
}
