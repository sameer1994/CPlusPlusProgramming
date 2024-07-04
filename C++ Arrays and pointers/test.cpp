#include <iostream>
using namespace std;
/*


Here's what the standard says (C99 6.3.2.1/3 - Other operands - Lvalues, arrays, and function designators):

Except when it is the operand of the sizeof operator or the unary & operator, or is a string literal used to initialize an array, an expression that has type ‘‘array of type’’ is converted to an expression with type ‘‘pointer to type’’ that points to the initial element of the array object and is not an lvalue.

This means that pretty much anytime the array name is used in an expression, it is automatically converted to a pointer to the 1st item in the array.

*/
//arr in the main function is not the same as arr passed in as a parameter
//array always decays to a int pointer, hence the size must always be passed in
//Technique 1: There is no type safety here, the user can even passin an array of 1000 ints
void Print1DArray(int* arr, int size)
{
    for(int i=0;i<size;++i)
    {
        cout<<arr[i]<<endl;
    }
}
//Technique 2 : We can also pass in a pointer to an array of int. This ensueres type safety
//THis will only allow pointer to a specific array size to be passed in.
//Additionally, the size of the array can also be extracted without passing an additional parameter
void Print1DArrayTypeSafe(int (*arr)[10],int size)
{
    int* temp= (*arr);
    cout<<"Arr: "<<arr<<" *Arr: "<<*arr<<" &arr: "<<&arr<<endl;
    cout<<"SIZE: "<<sizeof(arr)<<endl;
    //The pointer arr is the same as the address of the first element in the array.
    cout <<"ADDRESS COMPARISION"<<"\n"<<"FIRST LEVEL:"<<arr<<"\n"<<"SECOND LEVEL:"<<*arr<<endl;
    for(int i=0;i<size;++i)
    {
        cout<<temp[i]<<endl;
    }
}
//==========================2D ARRAYS============================
/*
When a 2D array is passed to the function below, it decays as follows
int (*) arr[3], essentially the first dimension decays into a pointer.
So basically arr is a pointer to a 1d array of 3 ints
In this approach the dimensionality is lost and the array for all purposes is flattened.
*/
void Print2DArray(int arr[][3]/*equivalent to int (*) arr[3] */,int rows,int cols)
{
    //technique 1
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            int* addr = (*arr + (i*cols)+ (j));
            cout<<"ADDRESS: "<<addr<<" VALUE: "<<(*addr)<<endl;
        }
    }
    //technique2
    for(int i=0;i<rows;++i)
        for(int j=0;j<cols;++j)
        {
            cout<<arr[i][j];
        }
}
int main(int c, char**argv)
{
    const char* d = "a";//only works with string literals(i.e " "), not single characters & the pointer has to be const (in C++)
    const char* a[] = {"abc","def","fassd"};//an array of pointers of type (const char*) must be const as mentioned above.
    char b[5]="adsf";
    const char f[5]="afds";
    const char** e = a;
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    ///cout<<sizeof(arr)<<endl;
    //technique 1
    //Print1DArray(arr,sizeof(arr)/sizeof(int));   //Commented out for brevity
    //technique 2
    Print1DArrayTypeSafe(&arr,sizeof(arr)/sizeof(int)); //Commented out for brevity
    int arr1[5] = {1,2,3,4,5};
    //Print1DArrayTypeSafe(&arr1,sizeof(arr1)/sizeof(int)); NOTE: This call won't work due to they type safety of pointer to the array
    int arr2[2][3] = {{1,2,3},{4,5,6}};
    cout<<"Address of 2d Array"<<arr2<<endl;
    Print2DArray(arr2,2,3);
    return 0;
}