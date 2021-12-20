#include <iostream>
#include <cstdlib>
using namespace std;

int mean(int *array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum/n;
}

int main()
{
    
    int number = 0;
    cout<<"Enter the size of an array: "<<endl;
    cin>>number;
    int *array = new int[number];
    
    for (int i = 0; i < number; i++)
    {
        array[i] = rand() % 100;
        cout<<array[i]<<" ";
    }
    
    int avg = mean(array,number);
    
    cout<<endl<<"The mean: "<<avg;
    delete[] array;
    return 0;

}   