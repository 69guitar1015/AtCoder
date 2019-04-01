#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Memo {
public:
    int start, end;
    Memo(string entry);
    Memo(int start, int end);
    void round();
    void print();
};

Memo::Memo(string entry) {
    this->start = std::stoi(entry.substr(0, 4));
    this->end = std::stoi(entry.substr(5, 4));
    this->round();
}

Memo::Memo(int start, int end) {
    this->start = start;
    this->end = end;
    this->round();
}

void Memo::round() {
    this->start -= this->start % 5;
    this->end += 4 - (this->end + 4) % 5;

    if(this->end % 100 == 60) {
        this->end += 100 - 60;
    }
}

void Memo::print() {
    printf("%04d-%04d\n", this->start, this->end);
}

bool operator<(const Memo& left, const Memo& right)
{
  return left.start < right.start;
}

bool operator>(const Memo& left, const Memo& right)
{
  return left.start < right.start;
}


int main() {
    int N;
    cin >> N;

    string entry;
    vector<Memo> memos{};
    for(int i=0; i<N; i++) {
        cin >> entry;
        Memo m(entry);
        memos.push_back(m);
    }
    sort(memos.begin(), memos.end(), greater<Memo>());
    
    int idx = 0;
    while(idx < memos.size()-1) {
        auto a = memos[idx];
        auto b = memos[idx+1];
        if(a.end >= b.start) {
            memos[idx] = Memo(min(a.start, b.start), max(a.end, b.end));
            memos.erase(memos.begin()+idx+1);
        } else {
            idx += 1;
        }
    }

    for(auto m : memos) {
        m.print();
    }
}