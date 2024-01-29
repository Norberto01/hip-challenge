#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */


long repeatedString(string s, long n) {
    if (n == 0){
        return 0;
    }
    long strSize = s.size();
    if (strSize == 1){
        return n;
    }
    long rv = 0;
    long occurrences = count(s.begin(), s.end(), 'a');
    double mod = double(n) / double(strSize);
    rv = static_cast<long>(ceil(mod * occurrences));
    return rv;
}

long repeatedStringB(string s, long n){
    long rv = 0;
    long rem = n % s.length();
    long strSize = s.size();
    if (strSize == 1){
        return n;
    }

    for (char c: s){
        if (c == 'a'){
            ++ rv;
        }
    }

    for(long i = 0; i < rem; i++){
        if (s[i] == 'a'){
            ++rv;
        }
    }
    return rv * rem;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
// abaabaabaa
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
