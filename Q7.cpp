//#include<iostream>
//#include<cstdlib>   //for system("cls")
//#include<conio.h>   //for _getch()
//using namespace std;
//class List
//{
//	int* ID;
//	string* name;
//	int size;
//	int capacity;
//public:
//	List()  //T=O(1),S=O(1)
//	{
//		ID = nullptr;
//		name = nullptr;
//		size = 0;
//		capacity = 0;
//	}
//	List(int size)  //T=O(size),S=O(size)
//	{
//		ID = new int[size];
//		name = new string[size];
//	}
//	void Insert(int id,string n) //T=O(size),S=O(capacity)
//		    {
//		        if (size < capacity) //T=O(1),S=O(1)
//		        {
//		            ID[size] =id;
//					name[size++] = n;
//		        }
//		        //if size>capacity then make a new array,double capacity,copy elements and values will point to this one
//		        else //T=O(size),S=O(capacity)
//		        {
//		            if (capacity == 0)  // handle empty list case
//		            {
//		                capacity = 1;
//		                ID = new int[capacity];
//						name = new string[capacity];
//		                ID[size] = id;
//						name[size++] = n;
//		            }
//		            else
//		            {
//		                capacity *= 2;
//		                int* newID = new int[capacity];
//						string* newName = new string[capacity];
//		                for (int i = 0; i < size; i++)
//		                {
//		                    newID[i] = ID[i];
//							newName[i] = name[i];
//		                }
//		                newID[size] = id;
//						newName[size++] = n;
//		                delete[] ID;
//						delete[] name;
//		                ID = newID;
//						name = newName;
//		            }
//		        }
//		    }
//
//	void Delete(int id) //T=O(size),S=O(capacity)
//	{
//		int index = -1;
//		// Findind ID
//		for (int i = 0; i < size; i++)  //T=O(size), S=O(1)
//		{
//			if (ID[i] == id)
//			{
//				index = i;
//				break;
//			}
//		}
//		if (index >= 0 && index < size)
//		{
//			// Shift elements
//			for (int i = index; i < size - 1; i++)
//			{
//				ID[i] = ID[i + 1];
//				name[i] = name[i + 1];
//			}
//
//			// Resize
//			if ((((size - 1) * 100) / capacity) <= 25)
//			{
//				if (capacity > 1)
//				{
//					capacity /= 2;
//				}
//				int* newID = new int[capacity];
//				string* newName = new string[capacity];
//				for (int i = 0; i < size - 1; i++)
//				{
//					newID[i] = ID[i];
//					newName[i] = name[i];
//				}
//				delete[] ID;
//				delete[] name;
//				ID = newID;
//				name = newName;
//			}
//			size--;
//		}
//		else
//		{
//			cout << "ID not found...." << endl;
//		}
//	}
//
//	void BinarySearch(int id) //T=O(log size),S=O(1)
//	{
//		int st = 0, en = size - 1;
//		while (st <= en)  //T=O(log size)
//		{
//			int mid = (st + en) / 2;
//			if (ID[mid] == id)
//			{
//				cout << "(Index: " << mid << " ), ID: " << ID[mid] << ", Name : " << name[mid] << endl;
//				return;
//			}
//			else if (ID[mid] < id)
//			{
//				st = mid + 1;   // search right side
//			}
//			else
//			{
//				en = mid - 1;  // search left side
//			}
//		}
//		cout << "ID not found...." << endl;
//	}
//
//	void mergeSort()  //T=O(size log size),S=O(size)
//	{
//		if (size < 2) 
//			return;
//
//		int* temp_id = new int[size];
//		string* temp_name = new string[size];
//
//		for (int w = 1; w < size; w =w* 2) // T=O(log size),S=O(1)
//		{
//			for (int l = 0; l < size; l += 2 * w)  //T=O(size),S=O(1)
//			{
//				int m = l + w;
//				if (m > size) 
//					m = size;
//
//				int r = l + 2 * w;
//				if (r > size)
//					r = size;
//
//				int i = l, j = m, k = l;
//
//				while (i < m && j < r)  //T=O(size),S=O(1)
//				{
//					if (ID[i] <= ID[j]) 
//					{
//						temp_id[k] = ID[i];
//						temp_name[k] = name[i];
//						i++;
//					}
//					else {
//						temp_id[k] = ID[j];
//						temp_name[k] = name[j];
//						j++;
//					}
//					k++;
//				}
//				while (i < m) {
//					temp_id[k] = ID[i];
//					temp_name[k] = name[i];
//					i++; k++;
//				}
//				while (j < r) {
//					temp_id[k] = ID[j];
//					temp_name[k] = name[j];
//					j++; k++;
//				}
//			}
//			for (int x = 0; x < size; x++) {
//				ID[x] = temp_id[x];
//				name[x] = temp_name[x];
//			}
//		}
//		delete[] temp_id;
//		delete[] temp_name;
//	}
//
//	void quickSort()  //T=O(size log size),S=O(size)
//	{
//		if (size < 2) 
//			return;
//
//		int* st = new int[size];
//		int top = -1;
//
//		st[++top] = 0; //0
//		st[++top] = size - 1;  //4
//
//		while (top >= 0)
//		{
//			int e = st[top--];  //e=4,e=2
//			int s = st[top--];  //s=0,s=0
//
//			//id{1,3,2,4,5}
//			int pivot = ID[e];   //pivot=4,pivot=2
//			int i = s - 1;   //i=-1,i=-1
//			for (int j = s; j < e; j++)   //j=0,j=1,j=2,j=3,4  j=0
//			{
//				//id{1,3,5,2,4}
//				//name{}]
//
//				//id{1,3,2,4,5}
//				if (ID[j] < pivot)  //2<4  <2 
//				{
//					i++;  //i=2  i=1
//					int t = ID[i];  //t=5
//					ID[i] = ID[j]; 
//					ID[j] = t;    //id{1,3,2,5,4}
//					string ts = name[i];  
//					name[i] = name[j]; 
//					name[j] = ts;
//				}
//			}
//
//			//id{1,3,2,5,4}, i=2
//			//id{1,3,2,4,5} i=1
//			int t = ID[i + 1];  //t=5  t=2
//			ID[i + 1] = ID[e]; //
//			ID[e] = t;
//			//id{1,3,2,4,5}
//			string ts = name[i + 1];
//			name[i + 1] = name[e]; 
//			name[e] = ts;
//
//			int p = i + 1;  //p=3
//			if (p - 1/*p=2*/ > s)//s=0
//			{
//				st[++top] = s;  //top=0 st[0]=0
//				st[++top] = p - 1;//top=1 st[1]=2
//			}
//			if (p + 1 < e)  //4<4
//			{
//				st[++top] = p + 1;
//				st[++top] = e;
//			}
//		}
//
//		delete[] st;
//	}
//	void TraverseList()  //T=O(size),S=O(1)
//	{
//		cout << "\n{";
//		for (int i = 0; i < size; i++)
//		{
//			cout << "(ID: " << ID[i] << ", Name: " << name[i] << ")";
//			if (i != size - 1)
//			{
//				cout << ", ";
//			}
//		}
//		cout << "}";
//		cout << "\nSize: " << size
//			<< "\nCapacity: " << capacity << endl;
//	}
// 
//    //Deallocating the values array
//    ~List()
//    {
//      if (ID != nullptr && name!=nullptr)
//		{
//		  ID = nullptr;
//		  name = nullptr;
//		}
//    }
//};
//int main()  
//{
//	cout << "Enter the size of List: ";
//	int size; cin >> size;
//	List list(size);
//	cout << "Enter the elements of List: " << endl;
//	for (int i = 0; i < size; i++) //T=O(size), S=O(size)
//	{
//		int id; string n;
//		cout << "Enter ID: ";
//		cin >> id;
//		cout << "Enter Name: ";
//		cin >> n;
//		list.Insert(id, n);
//	}
//	int choice;
//	do {
//		cout << "Press any key to continue to List Menu...";
//		_getch();
//		system("cls");
//		cout << "----- List Menu -----\n";
//		cout << "1) Insert Element";
//		cout << "\n2) Delete Element";
//		cout << "\n3) Search Element";
//		cout << "\n4) Sort";
//		cout << "\n5) Show: ";
//		cout << "\n6) Exit";
//		cout << "\nChoice: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: //T=O(size),S=O(capacity)
//		{
//			int id; string n;
//			cout << "Enter ID: ";
//			cin >> id;
//			cout << "Enter Name: ";
//			cin >> n;
//			list.Insert(id, n);
//			cout << "Successfully Inserted Element..." << endl;
//			break;
//		}
//		case 2: //T=O(size),S=O(capacity)
//		{
//			int id;
//			cout << "Enter ID to delete: ";
//			cin >> id;
//			list.Delete(id);
//			cout << "Successfully Deleted Element..." << endl;
//			break;
//		}
//		case 3: //T=O(size),S=O(1)
//		{
//			int id;
//			cout << "Enter ID to search: ";
//			cin >> id;
//			list.BinarySearch(id);
//			break;
//		}
//
//		case 4:
//		{
//			int ch;
//			cout << "1) Merge Sort\n2) Quick Sort\nChoice: ";
//			cin >> ch;
//			if (ch == 1)
//			{
//				list.mergeSort();
//				cout << "List sorted using Merge Sort..." << endl;
//			}
//			else if (ch == 2)
//			{
//				list.quickSort();
//				cout << "List sorted using Quick Sort..." << endl;
//			}
//			else
//			{
//				cout << "Invalid Choice..." << endl;
//			}
//			break;
//		}
//		case 5: //T=O(size),S=O(1)
//		{
//			list.TraverseList();
//			break;
//		}
//		case 6:  //T=O(1),S=O(1)
//			cout << "Exiting..." << endl;
//			return 0;
//		}
//	} while (true);  //T=O(1),S=O(1)
//}