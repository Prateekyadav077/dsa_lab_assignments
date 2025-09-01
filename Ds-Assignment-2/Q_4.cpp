#include <iostream>
using namespace std;

void concatenate(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

void reversestring(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

bool isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void deletevowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    cout << "String without vowels: " << str << endl;
}

void sortstring(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str << endl;
}

  
void Lower(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
        i++;
    }
    cout << "Lowercase string: " << str << endl;
}


int main() {
    char str1[100] = "Hello";
    char str2[50] = "World";
    concatenate(str1, str2);

    
    reversestring(str1);

    
    deletevowels(str2);

    
    sortstring(str2);

    
    Lower(str2);

    return 0;
}
