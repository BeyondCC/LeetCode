#include<iostream>
#include<string>

using namespace std;

void printArr(int *arr, int len);

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(string &s, int st, int e) {
    int start = st, end = e;

    while(start <= end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
}

void reverseWords(string &s){
    int len = s.length();
    int interval[len];
    int count = 0;
    int index = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' '){
            interval[index] = count;
            count = 0;
            index++;
        }else
            count++;
    }

    interval[index] = count;
    cout<<"index: "<<index<<endl;
    printArr(interval, index);
    
    reverse(s, 0, s.length() - 1);
    cout<<s<<endl;
    int start = 0;
    for(; index >= 0; index--){
        reverse(s, start, start + interval[index] - 1);
        start += interval[index];
        start++;
    }

    cout<<s<<endl;
}

void printArr(int *arr, int len) {
    for(int i = 0; i <= len; i++)
        cout<<arr[i]<<" "<<endl;
}

int main(int argc, char *argv[]) {
    //string s = "  i am a student";
    string s = " ";
    reverseWords(s);
    return 0;
}
