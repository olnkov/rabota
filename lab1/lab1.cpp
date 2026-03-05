#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> k1 = { 4, 1, 3, 2 };
    vector<int> k2 = { 3, 1, 4, 2 };

    string text;
    getline(cin, text);

    int R = (int)k1.size();
    int C = (int)k2.size();
    int block = R * C;

    while ((int)text.size() % block != 0) text += ' ';

    string cipher = "";

    for (int start = 0; start < (int)text.size(); start += block) {
        vector<vector<char>> a(R, vector<char>(C, ' '));

        int p = start;
        for (int i = 0; i < R; i++) {
            int row = k1[i] - 1;
            for (int j = 0; j < C; j++) {
                a[row][j] = text[p++];
            }
        }

        for (int j = 0; j < C; j++) {
            int col = k2[j] - 1;
            for (int i = 0; i < R; i++) {
                cipher += a[i][col];
            }
        }
    }

    cout << cipher << "\n";

    string plain = "";

    for (int start = 0; start < (int)cipher.size(); start += block) {
        vector<vector<char>> a(R, vector<char>(C, ' '));

        int p = start;
        for (int j = 0; j < C; j++) {
            int col = k2[j] - 1;
            for (int i = 0; i < R; i++) {
                a[i][col] = cipher[p++];
            }
        }

        for (int i = 0; i < R; i++) {
            int row = k1[i] - 1;
            for (int j = 0; j < C; j++) {
                plain += a[row][j];
            }
        }
    }

    cout << plain << "\n";
    return 0;
}
