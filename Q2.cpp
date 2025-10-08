//#include<iostream>
//#include<conio.h>   //for _getch()
//using namespace std;
//
//class List
//{
//private:
//    int* values;
//    int size;
//    int capacity;
//public:
//    List()  //T=O(1),S=O(1)
//    {
//        values = nullptr;
//        size = 0;
//        capacity = 0;
//    }
//    List(int s) //T=O(1),S=O(s)
//    {
//        values = new int[s];
//        size = 0;
//        capacity = s;
//    }
//
//    void AddElement(int value) //T=O(size),S=O(capacity)
//    {
//        if (size < capacity) //T=O(1),S=O(1)
//        {
//            values[size++] = value;
//        }
//        //if size>capacity then make a new array,double capacity,copy elements and values will point to this one
//        else //T=O(size),S=O(capacity)
//        {
//            if (capacity == 0)  // handle empty list case
//            {
//                capacity = 1;
//                values = new int[capacity];
//                values[size++] = value;
//            }
//            else
//            {
//                capacity *= 2;
//                int* newValues = new int[capacity];
//                for (int i = 0; i < size; i++)
//                {
//                    newValues[i] = values[i];
//                }
//                newValues[size++] = value;
//                delete[] values;
//                values = newValues;
//            }
//        }
//    }
//
//
//    int getSize()   //T=O(1),S=O(1)
//    {
//        return size;
//    }
//
//    //GET THE SPECIFIC INDEX VALUE
//    int getValue(int index)    //T=O(1),S=O(1)
//    {
//        return values[index];
//    }
//
//    void RemoveElement(int index) //T=O(size),S=O(capacity)
//    {
//        if (index >= 0 && index < size)
//        {
//            for (int i = index; i < size; i++)  //T=O(size), S=O(1)
//            {
//                if (i != size - 1)
//                {
//                    values[i] = values[i + 1];
//                }
//            }
//
//            if ((((size - 1) * 100) / capacity) > 25)
//            {
//                int* newArray = new int[capacity];
//                for (int i = 0; i < size - 1; i++)  //T=O(size),S=O(capacity)
//                {
//                    newArray[i] = values[i];
//                }
//                delete[] values;
//                values = newArray;
//            }
//            else if ((((size - 1) * 100) / capacity) <= 25)
//            {
//                if (capacity > 1)
//                {
//                    capacity /= 2;
//                }
//                int* newArray = new int[capacity];
//                for (int i = 0; i < size - 1; i++)
//                {
//                    newArray[i] = values[i];
//                }
//                delete[] values;
//                values = newArray;
//            }
//            size--;
//        }
//        else
//        {
//            cout << "Invalid Index...." << endl;
//        }
//    }
//
//    void Print()  //T=O(size),S=O(1)
//    {
//        cout << "\n{";
//        for (int i = 0;i < size;i++)
//        {
//            if (i != size - 1)
//                cout << values[i] << ",";
//            else
//                cout << values[i];
//        }
//        cout << "}";
//        cout << "\nSize: " << size
//            << "\nCapacity: " << capacity;
//    }
//    ~List()
//    {
//      if (values != nullptr)
//		{
//			delete[] values;
//		}
//    }
//};
//
//void Split(List& Array, List& listA, List& listB)   //T=O(size),S=O(size)
//{
//    int stind, endind;
//    cout << "----- Enter the Range for List A -----" << endl;
//    do {
//        cout << "Starting Index: ";
//        cin >> stind;
//        if (stind < 0 || stind > Array.getSize() - 1)
//        {
//            cout << "Index Out Of Bound" << endl;
//        }
//    } while (stind < 0 || stind > Array.getSize() - 1);
//    do {
//        cout << "Ending Index: ";
//        cin >> endind;
//        if (endind < stind)
//        {
//            cout << "Ending Index Cant Be Less Than Starting Index" << endl;
//        }
//        else if (endind > Array.getSize() - 1)
//        {
//            cout << "Index Out Of Bound" << endl;
//        }
//    } while (endind < stind || endind > Array.getSize() - 1);
//
//    cout << "----- Enter the Range for List B -----" << endl;
//    int stdint2, endind2;
//    do {
//        cout << "Starting Index: ";
//        cin >> stdint2;
//        if (stdint2 < 0 || stdint2 > Array.getSize() - 1)
//        {
//            cout << "Index Out Of Bound" << endl;
//        }
//        else if (stdint2 >= stind && stdint2 <= endind)
//        {
//            cout << "Index of both lists cant overlap!" << endl;
//        }
//    } while (stdint2 < 0 || stdint2 > Array.getSize() - 1 || (stdint2 >= stind && stdint2 <= endind));
//    do {
//        cout << "Ending Index: ";
//        cin >> endind2;
//        if (endind2 < stdint2)
//        {
//            cout << "Ending Index Cant Be Less Than Starting Index" << endl;
//        }
//        else if (endind2 > Array.getSize() - 1)
//        {
//            cout << "Index Out Of Bound" << endl;
//        }
//        else if (endind2 >= stind && endind2 <= endind)
//        {
//            cout << "Index of both lists cant overlap!" << endl;
//        }
//    } while (endind2 < stdint2 || endind2 > Array.getSize() - 1 || (endind2 >= stind && endind2 <= endind));
//
//    for (int i = stind; i <= endind; i++)
//    {
//        listA.AddElement(Array.getValue(i));
//    }
//    for (int i = stdint2; i <= endind2; i++)
//    {
//        listB.AddElement(Array.getValue(i));
//    }
//}
//
//int main()
//{
//    cout << "Enter the size of array: ";
//    int size; cin >> size;
//
//    cout << "Enter the elements of array: ";
//    List array(size);
//    int num;
//    for (int i = 0;i < size;i++) //T=O(size), S=O(size)
//    {
//        cin >> num;
//        array.AddElement(num);
//    }
//
//
//    List LA, LB;
//    Split(array, LA, LB);
//
//    cout << "\nArray: ";
//    array.Print();
//
//    cout << "\nlistA: ";
//    LA.Print();
//
//    cout << "\nlistB: ";
//    LB.Print();
//
//
//    do {
//        cout << "\nPress any key to see the menu";
//        _getch();
//        system("cls");
//        cout << "======== Lists Menu ========\n";
//        cout << "1) Remove Element";
//        cout << "\n2) Add Element";
//        cout << "\n3) Show All Arrays";
//        cout << "\n4) Exit";
//        int choice;cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//        {
//            int ind;
//            char ch;
//            do {
//                cout << "\nEnter List (A or B): ";
//
//                cin >> ch;
//                if (ch == 'A' || ch == 'a')
//                {
//                    cout << "ListA ";
//                    LA.Print();
//                    do {
//                        cout << "\nEnter Index: ";
//                        cin >> ind;
//                        if (ind < 0 || ind >= LA.getSize())
//                        {
//                            cout << "\nInvalid Index...";
//                        }
//                    } while (ind < 0 || ind >= LA.getSize());
//                    LA.RemoveElement(ind);
//                }
//                else  if (ch == 'B' || ch == 'b')
//                {
//                    cout << "ListB ";
//                    LB.Print();
//                    do {
//                        cout << "\nEnter Index: ";
//                        cin >> ind;
//                        if (ind < 0 || ind >= LB.getSize())
//                        {
//                            cout << "\nInvalid Index...";
//                        }
//                    } while (ind < 0 || ind >= LB.getSize());
//                    LB.RemoveElement(ind);
//                }
//                else
//                {
//                    cout << "\nInvalid List";
//                }
//            } while (ch != 'A' && ch != 'B');
//            cout << "\nSuccessfully Removed Index...";
//            break;
//        }
//
//        case 2:
//        {
//            int ele;
//            char ch;
//            cout << "\nEnter List (A or B): ";
//            do {
//                cin >> ch;
//                if (ch == 'A' || ch == 'a')
//                {
//                    cout << "ListA ";
//                    LA.Print();
//                    cout << "\nEnter Element: ";
//                    cin >> ele;
//                    LA.AddElement(ele);
//                }
//                else if (ch == 'B' || ch == 'b')
//                {
//                    cout << "ListB ";
//                    LB.Print();
//                    cout << "\nEnter Element: ";
//                    cin >> ele;
//                    LB.AddElement(ele);
//                }
//                else
//                {
//                    cout << "\nInvalid List";
//                }
//            } while (ch != 'A' && ch != 'B');
//            cout << "\nSuccessfully Added Element...";
//            break;
//        }
//        case 3:
//        {
//            cout << "\nNormal Array: ";
//            array.Print();
//
//            cout << "\nlistA: ";
//            LA.Print();
//
//            cout << "\nlistB: ";
//            LB.Print();
//            break;
//        }
//        case 4:
//        {
//            return 0;
//        }
//        }
//    } while (true);
//}
