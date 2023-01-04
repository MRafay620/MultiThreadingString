#include <iostream>
#include <pthread.h>
#include <string>
using namespace std;
string str; // define string
// input thread function
void* inputThread(void*)
{
    try
    {
        cout<<"Enter a string: ";
        cin>>str;
    }
    catch (const exception& ex)
    {
        cout<<"Exception in input thread: "<<ex.what()<<endl;
    }
    cout<<endl;
    return NULL;
}
// reverse thread function
void* reverseThread(void*)
{
        cout<<"Reversed string: ";
        for (int n = 0; n < str.length(); n++)
            cout<<str[str.length() - n - 1];
        cout<<endl;
        return NULL;
}
// capital thread function
void* capitalThread(void*)
{
        cout<<"Capitalized string: ";
        for (int n = 0; n < str.length(); n++)
            cout<<(char)toupper(str[n]);
        cout<<endl;   
        return NULL;
}
// shift thread function
void* shiftThread(void*)
{
        cout<<"Shifted string: ";
        for (int n = 0; n < str.length(); n++)
            cout<<(char)(str[i] + 2);
        cout << endl;
        return NULL;
}
//Driven Code
int main()
{
    // create the input thread,shift,captial
    pthread_t t1,t2, t3, t4;
    pthread_create(&t1, NULL, inputThread, NULL);
    // wait for input thread to finish
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, reverseThread, NULL);
    pthread_create(&t3, NULL, capitalThread, NULL);
    pthread_create(&t4, NULL, shiftThread, NULL);
    cout<<endl;
// wait for all threads to finish
    pthread_join(t2, NULL);
    cout<<endl;
    pthread_join(t3, NULL);
    cout<<endl;
    pthread_join(t4, NULL);
}
