#include<iostream>
using namespace std;
const int MAX = 100;

void displayMenu()
{
}

char enterOperator()
{
    char opt;
    cout << "Enter A Number: ";
    cin >> opt;
    return opt;
}

void insert(int arr[], int & used)
{
    if(used >= MAX)
    {
        cout << "No ";
    }
    else
    {
        cout << "Enter a Number: ";
        int data;
        cin >> data;
        int index = 0;
        for(int i = 0; i < used; i++)
        {
            if(arr[i] > data)
            {
                index = i;
                break;
            }
            index = used;
        }
        for(int i = used -1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = data;
        used++;
    }
}

void showAll(int arr[], int used)
{
    if(used == 0)
    {
        cout << "List is empty.\n";
        return;
    }
    cout << "Numbers in ascending order: ";
    for(int i = 0; i < used; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getLargest(int arr[], int used)
{
    return arr[used - 1];
}

int getSmallest(int arr[], int used)
{
    return arr[0];
}

double getMedian(int arr[], int used)
{
    if(used % 2 == 1)
        return arr[used / 2];
    else
        return (arr[used / 2 - 1] + arr[used / 2]) / 2.0;
}

double getAverage(int arr[], int used)
{
    int sum = 0;
    for(int i = 0; i < used; i++)
        sum += arr[i];
    return (double)sum / used;
}

int main()
{
    int numbers[MAX], used = 0;
    char opt;
    do
    {
        displayMenu();
        cout << "\n--- Menu ---\n";
        cout << "1. Insert a number\n";
        cout << "2. Show all numbers\n";
        cout << "3. Show largest number\n";
        cout << "4. Show smallest number\n";
        cout << "5. Show median\n";
        cout << "6. Show average\n";
        cout << "7. Quit\n";

        opt = enterOperator();

        switch(opt)
        {
            case '1':
                insert(numbers, used);
                break;
            case '2':
                showAll(numbers, used);
                break;
            case '3':
                if(used == 0) cout << "No data.\n";
                else cout << "Largest: " << getLargest(numbers, used) << endl;
                break;
            case '4':
                if(used == 0) cout << "No data.\n";
                else cout << "Smallest: " << getSmallest(numbers, used) << endl;
                break;
            case '5':
                if(used == 0) cout << "No data.\n";
                else cout << "Median: " << getMedian(numbers, used) << endl;
                break;
            case '6':
                if(used == 0) cout << "No data.\n";
                else cout << "Average: " << getAverage(numbers, used) << endl;
                break;
            case '7':
                cout << "Bye!!! \n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
    while(opt != '7');

    return 0;
}