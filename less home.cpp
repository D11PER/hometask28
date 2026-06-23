#include <iostream>
using namespace std;



class MyString {
    char* str;
    int lenght

public:

    // 
    MyString() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

    // Arbitrary size
    MyString(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

    // From C-string literal
    MyString(const char* s) {
        length = myStrlen(s);
        str = new char[length + 1];
        myStrcpy(str, s);
        objectCount++;
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        myStrcpy(str, other.str);
        objectCount++;
    }

    // Destructor
    ~MyString() {
        delete[] str;
        objectCount--;
    }

    //Methods----------

    void MyStrcpy(MyString& obj) {  /// ?????????? ??????
        delete[] str;
        lenght = obj.lenght;
        str = new char[lenght + 1];
    }

    bool MyStrStr(const char* s) {        /// ????? ???????? ? ?????
        return myStrstr(str, s) != nullptr;
    }

    int MyChr(char c) {       ///????? ??????? ? ????? (?????? ??????????
        ? ? ? ? ? ? ? , ? ? ? -1)

        for (size_t i = 0; i < lenght; i++) {
            if (str[i] == c) return i;
        }
        return -i
    }

    int MyStrLen() {   /// ???????? ??????? ?????
        return this->lenght;
    }

    void MySrtCat(MyString& b) {  /// / ??'??????? ??????
        char* newStr = new char[lenght + b.lenght + 1];
        for (size_t i = 0; i < this->length; i++) {
            newStr[i] = this->str[i];
        }

        for (size_t i = 0; i < b.length; i++)
        {
            newStr[this->length + i] = b.str[i];
        }

        delete[] this->str;
        this->str = newStr;
        this->length += b.length;

    }


    void MyDelChr(char c) { /// ??????? ???????? ??????
        int count = 0;
        for (int i = 0; i < length; i++) if (str[i] == c) count++;

        if (count == 0) return;

        char* newStr = new char[length - count + 1];
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] != c) newStr[j++] = str[i];
        }
        newStr[j] = '\0';
        delete[] this->str;
        this->str = newStr;
        this->length -= count;
    }


    // [] operator
    MyString& operator[](int index) {
        if (index < 0 || index >= length) {
            return str[0];
        }
        return str[index];
    }

    // obj + 10 ? ????? 10 '*'
    MyString operator+(int n) const {
        MyString temp;
        temp.length = length + n;
        temp.str = new char[temp.length + 1];
        for (int i = 0; i < length; i++) temp.str[i] = str[i];
        for (int i = length; i < temp.length; i++) temp.str[i] = '*';
        temp.str[temp.length] = '\0';
        return temp;
    }

    MyString& operator=(const MyString& right) {
        if (this != &right) {       
            delete[] str;            
            length = right.length;
            str = new char[length + 1];
            myStrcpy(str, right.str);
        }
        return *this;
    }



};

int main() {
    // ????????? ??'???? ?? ?????????????
    MyString s1;
    cout << "s1 (default): " << s1.MyStrLen() << " chars" << endl;

    // ????????? ? ????????
    MyString s2(10);
    cout << "s2 (size=10): " << s2.MyStrLen() << " chars" << endl;

    // ????????? ? ????????
    MyString s3("Hello");
    cout << "s3: " << s3.MyStrLen() << " chars" << endl;

    // ??????????
    MyString s4(s3);
    cout << "s4 (copy of s3): " << s4.MyStrLen() << " chars" << endl;

    // ????? ???????
    cout << "Index of 'e' in s3: " << s3.MyChr('e') << endl;

    // ????????????
    s3.MySrtCat(s2);
    cout << "s3 after concat with s2: " << s3.MyStrLen() << " chars" << endl;

    // ????????? ???????
    s4.MyDelChr('l');
    cout << "s4 after deleting 'l': " << s4.MyStrLen() << " chars" << endl;

    // ????????? 10 '*'
    MyString s5 = s4 + 10;
    cout << "s5 (s4 + 10 '*'): " << s5.MyStrLen() << " chars" << endl;

    // ????????? [] ?????????
    cout << "First char of s5: " << s5[0] << endl;


}
