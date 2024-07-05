#include <iostream>
using namespace std;
/*
It's true that they've failed in the past. Doesn't mean they won't keep trying though. A decade ago, a spokesperson or an MP would only mention it briefly or in passing, there used to be a lot of internal dissent in the party regarding these issues.  But now, private sector reservation and breaching the 50% cap have officially become a part of the Congress manifesto. Possibly an attempt to slowly bring to the mainstream a ludicrous idea.



Now, whether or not, they're just playing to the gallery or do they actually want to go forward with it if they (in a hypothetical scenario) ever win elections remains to be seen.*/
int main(int num, char**argv)
{
    //simple declaration of a character
    char c = 'a';
    //declare a string literal, which will give us the address to wher that literal is stored. In c++ the const is necessary because the address being
    //pointed to cannot be changed.
    //Additional note: when the variable literal is passed to cout,it will print the entire string and not the the address.(unique featue for const char*)
    const char* literal = "abc";
    char str[] = {'a','b','c'};
    char str1[] = "abcde";
    const char* str2[] = {"abc","def","ghi"};

    return 0;
}