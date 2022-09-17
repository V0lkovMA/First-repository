#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

// print data

void print() {
    // open file
    ifstream fin("data.txt");
    string s;

    // output
    int cnt = 0;
    unordered_map<string, int> books;

    cout << "Name:  Surname:  Book:\n";
    while (getline(fin, s)) {
        ++cnt;

        int it = s.rfind(' ', s.size() - 2);
        string book = s.substr(it + 1, s.size() - it - 1);
        if (!books.count(book))
            books[book] = 0;
        ++books[book];

        cout << s << "\n";
    }
    cout << "\nUser's count: " << cnt << "\n";
    string best_book;
    int votes = 0;
    for (auto& [book, votes_] : books)
        if (votes < votes_) {
            votes = votes_;
            best_book = book;
        }
    cout << "The most popular book: " << best_book << "\n";
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
    else if (s == "print")
        print();
}
