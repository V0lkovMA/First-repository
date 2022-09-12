#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // get user's data
    string name, surname, film;
    cin >> name >> surname >> film;

    // save to data.txt
    ofstream fout("data.txt", ios::app);
    fout << name << " " << surname << " " << film << "\n";
}
