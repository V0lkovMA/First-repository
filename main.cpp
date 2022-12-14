#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

const char SEP = '#';

// print data

void rewrite_questions() {
    cout << "Enter the amount of questions you want in your questionnaire\n";
    int amount;
    cin >> amount;
    ofstream output("questions.txt"), answer("data.txt");
    answer << "";
    string question;
    getline(cin, question);
    for (int i = 0; i < amount; i++) {
        getline(cin, question);
        output << question << "\n";
    }
    output.close();
    answer.close();
}

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
            int next = s.find(SEP, it);
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
    for (auto& cur : books) {
        string book = cur.first;
        int votes_ = cur.second;
        if (votes < votes_) {
            votes = votes_;
            best_book = book;
        }
    }
    cout << "The most popular book: " << best_book << "\n";
}

// add new user

void add() {
    string musorka;
    getline(cin, musorka);
    // open files
    ifstream fin("questions.txt");
    ofstream fout("data.txt", ios::app);
    string q, s;

    // ask and add answers
    while (getline(fin, q)) {
        cout << q << "\n";
        getline(cin, s);
        fout << s << SEP;
    }
    fout << "\n";
}

int main() {
    cout << "Enter 'add' to add user, 'print' to get data, 'questions' to rewrite the list of questions\n";
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
    else if (s == "questions") {
        rewrite_questions();
    }
}
