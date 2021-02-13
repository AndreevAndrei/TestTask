#include <stdio.h>

bool isPalindrome(int len, char* str)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int intReverse(int num)
{
    int res = 0, tmp;
    while (num != 0)
    {
        tmp = num % 10;
        num /= 10;
        //if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > 7)) return 0; // std::numeric_limits<int>::max()
        //if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tmp < -8)) return 0; // std::numeric_limits<int>::min()
        res = res * 10 + tmp;
    }
    return res;
}

bool isContains1(int num)
{
    while (num != 0)
    {
        if (num % 10 == 1) return true;
        num /= 10;
    }
    return false;
}

//// doesn't support negative numbers for simplicity. Otherwise F(n)=F(n+2)-F(n+1)
//int fib(int n)
//{
//    if (n > 46) return 0; // the result is more data type
//    else if (n > 1) return fib(n - 1) + fib(n - 2);
//    else if (n > 0) return 1; // base case
//    else return 0;
//}
//
//int classicFibWithFilter(int arr[], int num)
//{
//    if (num > 46) return 0; // the result is more data type
//    int shift = 0;
//    for (int i = 0; i <= num; i++)
//    {
//        int p = fib(i);
//        if (isContains1(p)) { shift++; continue; }
//        arr[i-shift] = p;
//    }
//    return num - shift + 1;
//}

//int progressiveFib(int k)
//{
//    unsigned int res[2] = { (k-1) % 2, k % 2 };
//    for (;k > 0;k--)
//    {
//        res[k % 2] = res[0] + res[1];
//    }
//    return res[1];
//}

int progressiveFibWhitFilter(int arr[], int k)
{
    if (k > 46) return 0; // the result is more data type
    int shift = 0;
    int res = 0, last = 1, cur = 0;
    arr[shift++] = 0;
    for (;k > 0;k--)
    {
        res = last + cur;
        last = cur;
        cur = res;
        if(!isContains1(res)) { arr[shift++] = res; }
    }
    return shift;
}

int main(int argc, char** argv)
{
    char str[] = "ab c ba"; //"abbabba"; //"abbaabba"; //""; //" "; //" a"; //"ab ba ba ab"; //"aa b  aa";
    bool res1 = isPalindrome(sizeof(str) - 1, str);
    printf("'%s' %s palindrome\r\n\r\n", str, (res1?"is":"isn't"));

    int k = 30;
    int* res2 = new int[k];
    int len = progressiveFibWhitFilter(res2, k);
    printf("fibonacci(%d) whitout numbers containing '1' [%d]:\r\n", k, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", res2[i]);
    }
    printf("\r\n\r\n");

    int num = 25863; //0; //-524; //987654321; //101; //53; //100
    int res3 = intReverse(num);
    printf("revetred number of '%d' is '%d'\r\n", num, res3);

	return 0;
}