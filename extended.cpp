#include <iostream>
#include <vector>

using namespace std;

bool isClassicPalindrome(string sentence)
{
    int i = 0, j = sentence.length() - 1;
    while (i < j)
    {
        while (i < j && !isalnum(sentence[i])) i++; // inner while a little bit faster on tests
        while (i < j && !isalnum(sentence[j])) j--;
        if (tolower(sentence[i]) == tolower(sentence[j])) { i++; j--; }
        else { return false; }
    }
    return true;
}

bool isContainsOne(int num)
{
    while (num != 0)
    {
        if (num % 10 == 1) return true;
        num /= 10;
    }
    return false;
}
bool filteredFibonacci(vector<int> &result, int number)
{
    if (number > 46) return false; // the result is more data type
    int res = 0, last = 1, cur = 0;
    result.push_back(0);
    for (;number > 0;number--)
    {
        res = last + cur;
        last = cur;
        cur = res;
        if (!isContainsOne(res)) { result.push_back(res); }
    }
    return true;
}

int reverseInt(int num)
{
    long res = 0;
    while (num != 0)
    {
        res = res * 10 + num % 10;
        num = num / 10;
    }

    if (res < INT_MIN || res > INT_MAX) { return 0; }
    else { return (int)res; }
}

void main2()
{
    string sentence = "A man, a plan, a canal: Panama";
    bool res1 = isClassicPalindrome(sentence);
    cout << "'" << sentence << (res1 ? "' is " : "' isn't ") << "palindrome" << endl << endl;

    int number = 30;
    vector<int> res2;
    bool success = filteredFibonacci(res2, number);
    cout << "fibonacci(" << number << ") whitout numbers containing '1' [" << res2.size() << "]:" << endl;
    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl << endl;

    int num = 25863;
    int res3 = reverseInt(num);
    cout << "revetred number of '" << num << "' is '" << res3 << "'" << endl;
}
