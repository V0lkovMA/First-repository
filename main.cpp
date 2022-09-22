#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

// print data

void print(int width) {
    width = max(width, 8);
    // open file
    ifstream fin("data.txt");
    string s;

    // output

    int cnt = 0;
    unordered_map<string, int> books;

    while (getline(fin, s)) {
        ++cnt;

        int it = 0;
        vector<string> v;
        while (it < s.size()) {
            int next = s.find(' ', it);
            v.push_back(s.substr(it, next - it));
            it = next + 1;
        }

        string book = v.back();
        if (!books.count(book))
            books[book] = 0;
        ++books[book];

        for (auto& t : v) {
            while (t.size() < width)
                t += ' ';
            cout << t;
        }
        cout << "\n";
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
        getline(cin, s);
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
