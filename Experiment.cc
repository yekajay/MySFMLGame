#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool palin_perm(string s)
{
    int odd_count = 0;
    vector<int>v(26, 0);
    for (auto item : s) {
        int val = item-'a';
        v[val]++;
        if (v[val]%2==1) {
            odd_count++;
        }
        else {
            --odd_count;
        }
    }
    return (odd_count <= 1);
}

int main()
{
    string s = "haahnntg";

    cout << palin_perm(s) << endl;
    char c = 'z';
    cout << (int)c << endl;

    return 0;
}
