//#include<iostream>
//#include<cstdlib>   //for system("cls")
//#include<conio.h>   //for _getch()
//using namespace std;
//
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
//    List(int s) //T=O(s),S=O(s)
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
//    void TraverseList()  //T=O(size),S=O(1)
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
//    void insertIndex(int val, int ind)
//    {
//        values[ind] = val;
//    }
//
//    //Deallocating the values array
//    ~List()
//    {
//      if (values != nullptr)
//		{
//			delete[] values;
//		}
//    }
//};
//void mergearray(List& Array, List& listA, List& listB)
//{
//    //Adding list A elements to Array
//    for (int i = 0;i < listA.getSize();i++)
//    {
//        Array.AddElement(listA.getValue(i));
//    }
//    //Adding list B elements to Array
//    for (int j = 0;j < listB.getSize();j++)
//    {
//        Array.AddElement(listB.getValue(j));
//    }
//
//    //Sorting Array
//    for (int i = 0;i <Array.getSize()-1;i++)
//    {
//        for (int j = i+1;j < Array.getSize();j++)
//        {
//            if (Array.getValue(i) > Array.getValue(j))
//            {
//                int temp = Array.getValue(i);
//                Array.insertIndex(Array.getValue(j),i);
//                Array.insertIndex(temp, j);
//
//            }
//        }
//    }
//
//}
//void Split(List& Array, List& listA, List& listB)   //T=O(k),S=O(1)
//{
//    int k;
//    do {
//        cout << "Enter the Value of K: ";
//       cin >> k;
//        if (k < 0 || k > Array.getSize() - 1)
//        {
//            cout << "Index Out Of Bound" << endl;
//        }
//    } while (k < 0 || k> Array.getSize() - 1);
//
//    for (int i = 0; i < k; i++)
//    {
//        listA.AddElement(Array.getValue(i));
//    }
//    for (int i = k; i <Array.getSize(); i++)
//    {
//        listB.AddElement(Array.getValue(i));
//    }
//}
//
//int main()
//{
//    List array;
//    do {
//        system("cls");
//        cout << "=== WELCOME TO SAIMS MERGE, SPLIT ARRAY SYSTEM ===\n";
//        cout << "1) Merge Array\n";
//        cout << "2) Split Array \n";
//        cout << "3) Exit\n";
//        cout << "-----------------";
//        cout << "\nChoice: ";
//        int choice;cin >> choice;
//        switch (choice)
//        {
//            int size;int num;
//        case 1:
//        {
//            List LA, LB;
//            List array;
//            do {
//                cout << "\nEnter the size of List A: ";
//                cin >> size;
//                if (size < 0)
//                {
//                    cout << "\nInvalid Size";
//                }
//            } while (size < 0);
//
//            cout << "\nEnter the Elements of List A: ";
//
//            for (int i = 0;i < size;i++)
//            {
//                cin >> num;
//                LA.AddElement(num);
//                /*     LA.TraverseList();*/
//            }
//
//            do {
//                cout << "\nEnter the size of List B: ";
//                cin >> size;
//                if (size < 0)
//                {
//                    cout << "\nInvalid Size";
//                }
//            } while (size < 0);
//
//            cout << "\nEnter the Elements of List B: ";
//
//            for (int i = 0;i < size;i++)
//            {
//                cin >> num;
//                LB.AddElement(num);
//                /*     LB.TraverseList();*/
//            }
//            mergearray(array, LA, LB);
//            cout << "\nMerged Array: ";
//            array.TraverseList();
//            cout << "\nPress any key to continue...";
//            _getch();
//            break;
//        }
//        case 2:
//        {
//            List LA, LB;
//            List array;
//            do {
//                cout << "\nEnter the size of Array: ";
//                cin >> size;
//                if (size < 0)
//                {
//                    cout << "\nInvalid Size";
//                }
//            } while (size < 0);
//            cout << "\nEnter Elements: ";
//            for (int i = 0;i < size;i++)
//            {
//                cin >> num;
//                array.AddElement(num);
//            }
//            Split(array, LA, LB);
//            cout << "\n\nList A: ";
//            LA.TraverseList();
//            cout << "\n\nList B: ";
//            LB.TraverseList();
//            cout << "\nPress any key to continue...";
//            _getch();
//            break;
//        }
//        case 3:
//        {
//            cout << "\nExiting Program...";
//            return 0;
//        }
//        default:
//        {
//            cout << "\nInvalid Input";
//            cout << "\nPress any key to continue...";
//            _getch();
//        }
//        }
//    } while (true);
//}
