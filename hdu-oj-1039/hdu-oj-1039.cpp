#include <iostream>
#include <cstring>

using namespace std;

bool isEnd(char* s) {
    char endFlag[] = "end";
    int len_end = strlen(endFlag);
    int len_s = strlen(s);
    if(len_s != len_end)
        return false;

    int i=0;
    while(i++ < len_end) {
        if(s[i] != endFlag[i])
            return false;
    }
    return true;
}

bool Identify(char* s) {
    int table[26];
    memset(table, 0, 26 * sizeof(int));

    int countVowel=0, countConsonant=0;
    int len_s = strlen(s);
    for(int i=0; i<len_s; ++i) {
        table[s[i] - 'a']++;
        if(i < len_s-1) {
            if(s[i] == s[i+1]) {    // if not 'ee' '00', false
                if(s[i] != 'e' && s[i] != 'o')
                    return false;
            }
        }
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            countVowel++;
            countConsonant = 0;
        }
        else {
            countConsonant++;
            countVowel=0;
        }
        if(countVowel==3 || countConsonant==3)
            return false;
    }
    if(     table['a'-'a'] == 0     // at least one vowel
       &&   table['e'-'a'] == 0
       &&   table['i'-'a'] == 0
       &&   table['o'-'a'] == 0
       &&   table['u'-'a'] == 0
       )
       return false;

    return true;
}

int main()
{
    char s_in[21];
    while(cin >> s_in) {
        if(isEnd(s_in))
            break;

        if(Identify(s_in))
            cout << '<' << s_in << '>' << " is acceptable." << endl;
        else
            cout << '<' << s_in << '>' << " is not acceptable." << endl;
    }

    return 0;
}
