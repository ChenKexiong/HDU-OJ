#include <iostream>

using namespace std;

void Encoding(char* in) {
    char* temp_in = in;
    int count = 1;
    while(*temp_in) {
        if(*(temp_in + 1) == *temp_in) {
            count++;
            temp_in++;
        }
        else {
            if(count == 1) {
                cout << *temp_in;
            }
            else {
                cout << count << *temp_in;
                count = 1;
            }
            temp_in++;
        }
    }
}

int main()
{
    int i=0, lines=0;
    char buf[10001];

    cin >> lines;
    while(i++ < lines) {
        cin >> buf;
        Encoding(buf);
        cout << endl;
    }

    return 0;
}
