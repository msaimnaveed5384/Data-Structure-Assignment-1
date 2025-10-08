//#include<iostream>
//#include<conio.h> //used because of _getch() code stopper
//using namespace std;
////automatically expand when full
////Because we have studied arrays in class so we use them as list
//
//class List
//{
//private:
//	int* values = nullptr;
//	int capacity;
//	int size;
//public:
//	List(int capacity) //T=O(1), S=O(capacity)
//	{
//		values = new int[capacity];
//		size = 0;
//		this->capacity = capacity;
//	}
//
//	void AddElement(int value) //T=O(size),S=O(capacity)
//	{
//		if (size < capacity) //T=O(1),S=O(1)
//		{
//			values[size++] = value;
//		}
//
//		//if size>capacity than make a new array,double capacity,copy elements and values will point to this one
//		else //T = O(size),S=O(capacity)
//		{
//			capacity *= 2;
//			int* newValues = new int[capacity];
//			for (int i = 0;i < size;i++)
//			{
//				newValues[i] = values[i];
//			}
//			newValues[size++] = value;
//			delete values;
//			values = newValues;
//		}
//	}
//
//	void RemoveElement(int index) //T=O(size),S=O(capacity)
//	{
//		//Checkng if index lies in array
//		if (index >= 0 && index < size)
//		{
//		
//			
//				for (int i = index;i < size;i++)  //T=O(size), S=O(1)
//				{
//					if (i != size - 1)
//					{
//						values[i] = values[i + 1];
//					}
//				}
//
//				//Make new array and keep the capacity same while reducing size 1
//				if ((((size - 1) * 100) / capacity) > 25)  
//				{
//					int* newArray = new int[capacity];
//					for (int i = 0;i < size-1;i++)  //T=O(size),S=O(capacity)
//					{
//						newArray[i] = values[i];
//					}
//					delete[] values;
//					values = newArray;
//				}
//				//Make new array and reduce the capacity to /2  and reducing size 1
//				else if ((((size - 1) * 100) / capacity) <= 25) //T=O(size),S=O(capacity)
//				{
//					capacity /= 2;
//					int* newArray = new int[capacity];
//					for (int i = 0;i < size-1;i++)
//					{
//						newArray[i] = values[i];
//					}
//					delete[] values;
//					values = newArray;
//				}
//				size--;
//		}
//		else
//		{
//			cout << "\nInvalid Index....\n";
//		}
//		
//	}
//
//	void Print()  //T=O(size),S=O(1)
//	{
//		cout << "\nArray: {";
//		for (int i = 0;i < size;i++)
//		{
//			if(i!=size-1)
//			cout << values[i]<<",";
//			else
//				cout << values[i];
//		}
//		cout << "}";
//		cout << "\n\nSize: " << size
//			<< "\nCapacity: "<<capacity;
//	}
//
//	//Deallocating memory
//	~List()  //T=O(1),S=O(1)
//	{
//		if (values != nullptr)
//		{
//			delete[] values;
//		}
//}
//};
//int main()
//{
//	cout << "Enter the size of List: ";
//	int size; cin >> size;
//
//	List list(size);
//	int choice;
//	do {
//		
//		cout << "\n-------- Operations you can perform --------\n";
//		cout << "1) Add Element\n";
//		cout << "2) Remove Element\n";
//		cout << "3) View List\n";
//		cout << "4) Exit\n";
//		cout << "Choice: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//		{
//			cout << "\nEnter the Value You want to Add: ";
//			int value;cin >> value;
//			list.AddElement(value);
//			break;
//		}
//
//		case 2:
//		{
//			cout << "\nEnter the Index you want to Remove: ";
//			int index;cin >> index;
//			list.RemoveElement(index);
//			break;
//		}
//
//		case 3:
//		{
//			list.Print();
//			break;
//		}
//		case 4:
//		{
//			cout << "\nExiting Program....";
//			break;
//		}
//		default:
//		{
//			cout << "\nInvalid Choice...";
//			break;
//		}
//		}
//		//used for stopping the code before clear screen library include<conio.h>
//		cout<<"\n\n\nPress any key to continue...\n";
//		_getch();
//
//		//used for professional and clean look
//		system("cls");
//	} while (choice != 4);
//	return 0;
//}