//#include<iostream>
//#include<conio.h> //used because of _getch() code stopper
//#include <cstdlib>   // for srand(), rand()
//#include <ctime>     // for time() because used srand(time(0)) to generate random shuffle each time
//using namespace std;
////automatically expand when full
////Because we have studied arrays in class so we use them as list
//
//class List {
//private:
//	int* values = nullptr;
//	int capacity;
//	int size;
//public:
//	List()  //T=O(1),S=O(1)
//	{
//		values = nullptr;
//		size = 0;
//		capacity = 0;
//	}
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
//		//if size> =capacity than make a new array,double capacity,copy elements and values will point to this one
//		else //T=O(size),S=O(capacity)
//		{
//			if (capacity == 0)
//			{
//				capacity = 1;
//			}
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
//			for (int i = index;i < size;i++)  //T=O(size), S=O(1)
//			{
//				if (i != size - 1)
//				{
//					values[i] = values[i + 1];
//				}
//			}
//
//			//Make new array and keep the capacity same while reducing size 1
//			if ((((size - 1) * 100) / capacity) > 25)
//			{
//				int* newArray = new int[capacity];
//				for (int i = 0;i < size - 1;i++)  //T=O(size),S=O(capacity)
//				{
//					newArray[i] = values[i];
//				}
//				delete[] values;
//				values = newArray;
//			}
//			//Make new array and reduce the capacity to /2  and reducing size 1
//			else if ((((size - 1) * 100) / capacity) <= 25) //T=O(size),S=O(capacity)
//			{
//				capacity /= 2;
//				int* newArray = new int[capacity];
//				for (int i = 0;i < size - 1;i++)
//				{
//					newArray[i] = values[i];
//				}
//				delete[] values;
//				values = newArray;
//			}
//			size--;
//		}
//		else
//		{
//			cout << "\nInvalid Index....\n";
//		}
//
//	}
//	void RotateRight(int val) //T=O(val*size),S=O(1)
//	{
//		for (int i = 0;i < val;i++)
//		{
//			for (int j = size - 1 ;j > 0;j--)
//			{
//				int temp = values[j - 1];
//				values[j - 1] = values[j];
//				values[j] = temp;
//			}
//		}
//	}
//
//	void RotateLeft(int val) //T=O(val*size),S=O(1)
//	{
//		for (int i = 0;i < val;i++)
//		{
//			for (int j =0;j <size-1;j++)
//			{
//				int temp = values[j + 1];
//				values[j + 1] = values[j];
//				values[j] = temp;
//			}
//		}
//	}
//	void Shuffle()   //T=O(size),S=O(1)
//	{
//		if (size <= 1) 
//			return;
//		srand(time(0)); // seed once with current time
//
//		for (int i = size - 1; i > 0; --i) {
//			int j = rand() % (i + 1);
//
//			int temp = values[i];
//			values[i] = values[j];
//			values[j] = temp;
//		}
//	}
//	void sparseList(List& indexes,List& value) //T=O(size^3),S=O(capacity*size^2)
//	{
//		for (int i = 0;i < size;i++)
//		{
//			if (values[i] != 0)
//			{
//				indexes.AddElement(i);
//				value.AddElement(values[i]);
//			}
//		}
//	}
//	void TraverseList()  //T=O(size),S=O(1)
//	{
//		cout << "\nArray: {";
//		for (int i = 0;i < size;i++)
//		{
//			if (i != size - 1)
//				cout << values[i] << ",";
//			else
//				cout << values[i];
//		}
//		cout << "}";
//		cout << "\n\nSize: " << size
//			<< "\nCapacity: " << capacity;
//	}
//	int getSize()
//	{
//		return size;
//	}
//	//Deallocating memory
//	~List()  //T=O(1),S=O(1)
//	{
//		if (values != nullptr)
//		{
//			delete[] values;
//		}
//	}
//};
//int main()
//{
//	int size;
//	do {
//		cout << "Enter the Capacity of List: ";
//		cin >> size;
//		if (size < 0)
//		{
//			cout << "\nCapacity must be positive\n";
//		}
//	} while (size < 0);
//	List list(size);
//	int choice;
//	do {
//
//		cout << "\n-------- Operations you can perform --------\n";
//		cout << "1) Add Element\n";
//		cout << "2) Remove Element\n";
//		cout << "3) View List\n";
//		cout << "4) Rotation\n";
//		cout << "5) Shuffle\n";
//		cout << "6) Sparse\n";
//		cout << "7) Exit\n";
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
//			list.TraverseList();
//			break;
//		}
//		case 4:
//		{
//			int choose;
//			cout << "You Pressed 4(Rotation)...\n";
//			do {
//				cout << "1) Rotate Right\n";
//				cout << "2) Rotate Left\nPress: ";
//				cin >> choose;
//				if (choose < 1 || choose>2)
//				{
//					cout << "\nInvalid Choice!...\n";
//				}
//			} while (choose < 1 || choose>2);
//				switch (choose)
//				{
//				case 1:
//				{
//					int val;
//					do {
//						cout << "Enter rotation values: ";
//						cin >> val;
//						if (val < 0)
//						{
//							cout << "\nInvalid! Value cant be Negative\n";
//						}
//					} while (val < 0);
//					val = val % list.getSize();
//					list.RotateRight(val);
//					break;
//				}
//				case 2:
//				{
//					int val;
//					do {
//						cout << "Enter rotation values: ";
//						cin >> val;
//						if (val < 0)
//						{
//							cout << "\nInvalid! Value cant be Negative\n";
//						}
//					} while (val < 0);
//					val = val % list.getSize();
//					list.RotateLeft(val);
//					break;
//				}
//				}
//				break;
//		}
//		case 5:
//		{
//			list.Shuffle();
//			cout << "\nShuffled Successfully...";
//			break;
//		}
//		case 6:
//		{
//			List index, value;
//			list.sparseList(index,value);
//			cout << "\nSparse Indexes: ";
//			index.TraverseList();
//			cout << "\nSparse Values: ";
//			value.TraverseList();
//			break;
//		}
//		case 7:
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
//		cout << "\n\n\nPress any key to continue...\n";
//		_getch();
//
//		//used for professional and clean look
//		system("cls");
//	} while (choice != 7);
//	return 0;
//}