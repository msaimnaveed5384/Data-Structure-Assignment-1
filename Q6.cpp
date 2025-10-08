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
//    void insertIndex(int val, int ind) //T=O(1),S=O(1)
//    {
//        values[ind] = val;
//    }
//
//    int BinarySearch(int val)  //T=O(logn),S=O(1)
//    {
//        int st = 0,en = size - 1;
//        for (int i = 0; i < size; i++)
//        {
//            int j = (st + en) / 2;
//           if (val == values[j])
//                   {
//                 cout << "Value " << val << " is at index " << j << endl;
//              return j;
//                    }
//            else if (val > values[j])
//            {
//                st = j + 1;   // move index to right
//            }
//            else
//            {
//                en = j - 1;  // move index to left
//            }
//            if (st > en)   // stop if start is greater than end
//                break;
//        }
//        cout << "Value " << val << " not found" << endl;
//    }
//
//    void SelfAdjustingSearch(int val)     //T=O(size),S=O(1)
//    {
//        int i = 0;
//        for (;i < size;i++)
//        {
//            if (values[i] == val)
//            {
//                break;
//          }
//      }
//        if (i == size)
//         {
//           cout << "Value " << val << " not found" << endl;
//              return;
//     }
//        int temp = values[i];
//        for (int j=i;j >0;j--)
//        {
//            values[j] = values[j-1];
//        }
//        values[0] = temp;
//        cout << "Value " << val << " moved to front successfully" << endl;
//       
//    }
//    //Deallocating the values array
//    ~List()
//    {
//      if (values != nullptr)
//		{
//			delete[] values;
//		}
//    }
//    void InterploationSearch(int val)    //T=O(log logn),S=O(1)
//    {
//        int st = 0;
//        int end = size - 1;
//
//        for (int i = 0; i < size; i++)
//        {
//            // If value is outside current range
//            if (st > end || val < values[st] || val > values[end])
//                break;
//            // Estimate position
//            int pos = st + ((val - values[st]) * (end - st)) / (values[end] - values[st]);
//            if (values[pos] == val)
//            {
//                cout << "Value " << val << " is at index " << pos << endl;
//                return;
//            }
//            else if (values[pos] < val)
//            {
//                st = pos + 1; // search right side
//            }
//            else
//            {
//                end = pos - 1; // search left side
//            }
//        }
//        cout << "Value " << val << " not found" << endl;
//    }
//};
//
//int main()
//{
//    cout << "Enter the size of Array: ";
//    int size;cin >> size;
//    List list(size);
//
//    cout << "\nEnter the Elements of the Array: ";
//    int num;
//    for (int i = 0;i < size;i++) //T=O(size), S=O(size)
//    {
//        cin >> num;
//        list.AddElement(num);
//    }
//    int choice;
//    do {
//        _getch();
//        system("cls");
//        cout << "======== Search Operations in an Array ========\n";
//        cout << "1) Binary Search\n";
//        cout << "2) Interpolation Search\n";
//        cout << "3) Self-Adjusting Search\n";
//        cin >> choice;
//        switch (choice)
//        {
//        case 1:
//        {
//
//            int val;
//
//            cout << "\nEnter the Value to search: ";
//            cin >> val;
//
//            list.BinarySearch(val);
//            break;
//        }
//        case 2:
//        {
//            int val;
//
//            cout << "\nEnter the Value to search: ";
//            cin >> val;
//
//            list.InterploationSearch(val);
//            break;
//        }
//        case 3:
//        {
//            int val;
//
//            cout << "\nEnter the Value to search: ";
//            cin >> val;
//            list.SelfAdjustingSearch(val);
//            list.Print();
//            break;
//        }
//        case 4:
//        {
//            cout << "\nExiting Program....";
//            return 0;
//        }
//        }
//    } while (true);
//}