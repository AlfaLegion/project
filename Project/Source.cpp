#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<utility>
#include<stack>
using namespace std;
class book
{
private:
	string avtor;
	string name_book;
	int date;
	int count_page;
public:
	book() : avtor(), name_book(), date(0), count_page(0) {}
	book(const book& _other) :avtor(_other.avtor), name_book(_other.name_book), date(_other.date), count_page(_other.count_page)
	{

	}
	book& operator=(const book& other)
	{
		if (this == &other)
			return *this;
		avtor = other.avtor;
		name_book = other.name_book;
		date = other.date;
		count_page = other.count_page;
		return *this;
	}
	void set_avtor(const string& str)
	{
		avtor = str;
	}
	void set_name_book(const string& str)
	{
		name_book = str;
	}
	void set_date(int dt)
	{
		date = dt;
	}
	void set_count_page(int temp)
	{
		count_page = temp;
	}
	const string& get_avtor()const
	{
		return avtor;
	}
	const string& get_name_book()const
	{
		return name_book;
	}
	int get_date()const
	{
		return date;
	}
	int get_count_page()const
	{
		return count_page;
	}
};
int partition(book*m, int b, int e)
{
	int v = m[e].get_date();
	int i =b;
	int j = e-1;
	while (true)
	{
		while (m[i].get_date() < v)
		{
			if (i == j)
				break;
			i++;
		}
		while (m[j].get_date() > v)
		{
			if (j == i)
				break;
			j--;
		}
		if (i >= j)
			break;
		swap(m[i], m[j]);
	}
	if ((i == j) && (i == e - 1))
	{
		if (m[i].get_date() > m[e].get_date())
			swap(m[i], m[e]);
		return i;
	}
			swap(m[i], m[e]);
	
	return i ;
}
void My_qsort(book* ms, int b, int e)
{
	stack<pair<int, int>>stk;
	stk.push(pair<int,int>(b, e));
	while (!stk.empty())
	{
		b=stk.top().first;
		e = stk.top().second;
		stk.pop();
		if (e <= b)
			continue;
		int a = partition(ms, b, e);
		if ((a-b) > (e - a+1))
		{
			
			stk.push(pair<int, int>(b, a-1 ));
			stk.push(pair<int, int>(a, e));
		}
		else
		{
			if ((a - b) == 0)
			{
				if ((e - a + 1) == 2)
				{
					if (ms[e].get_date() < ms[a].get_date())
						swap(ms[e], ms[a]);
				}
				continue;
			}
				
			stk.push(pair<int, int>(a, e));
			stk.push(pair<int, int>(b, a-1));
		}
	}
}
int main()
{
	bool flag=true;
	book*library=nullptr;
	fstream file;
	int num=0;
	int switch_on;
	while (flag)
	{

		cout << "1. Creating library" << endl;
		cout << "2. Show rezult on the screen" << endl;
		cout << "3. Show rezult to file" << endl;
		cout << "4. Save rezult on file" << endl;
		cout << "5. Read data from file" << endl;
		cout << "6. Bubble sort" << endl;
		cout << "7. Quick sort" << endl;
		cout << "8. Exit" << endl;
		cout << "->";
		
		cin >> switch_on;
		while (cin.get() != '\n')
			continue;
		switch (switch_on)
		{
		case 1:
		{
			delete[]library;
				cout << "Count of books: ";
				cin >> num;
				while (cin.get() != '\n')
					continue;
				library = new book[num];
				for (int i = 0; i < num; i++)
				{
					string n_avt;
					cout << "Name avtor: ";
					getline(cin, n_avt);
					library[i].set_avtor(n_avt);
					string n_bk;
					cout << "Name book: ";
					getline(cin, n_bk);
					library[i].set_name_book(n_bk);
					int date;
					cout << "Date: ";
					cin>>date;
					library[i].set_date(date);
					int c_pg;
					cout << "Count page: ";
					cin >> c_pg;
					while (cin.get() != '\n')
						continue;
					library[i].set_count_page(c_pg);
					cout << endl;
				}
			break;
		}
		case 2:
		{
			cout << endl;
			for (int i = 0; i < num; i++)
			{
				cout << "Name avtor: " << library[i].get_avtor() << endl;
				cout << "Name book: " << library[i].get_name_book() << endl;
				cout << "Date: " << library[i].get_date() << endl;
				cout << "Count page: " << library[i].get_count_page() << endl;
				cout << endl;
			}
			break;
		}
		case 3:
		{
			cout << endl;
			string file_name;
			cout << "Input file name: ";
			cin >> file_name;
			while (cin.get() != '\n')
				continue;
			file.open(file_name + ".txt", ios_base::out);
			if (!file.is_open())
			{
				cout << "ERROR open file" << endl;
				break;
			}
			for (int i = 0; i < num; i++)
			{
				file << "Name avtor: " << library[i].get_avtor() << endl;
				file << "Name book: " << library[i].get_name_book() << endl;
				file << "Date: " << library[i].get_date() << endl;
				file << "Count page: " << library[i].get_count_page() << endl;
				file << endl;
			}
			file.close();
			cout << "Successful"<<endl;
			break;
		}
		case 4:
		{
			string file_name;
			cout << endl;
			cout << "Input file name: ";
			cin >> file_name;
			while (cin.get() != '\n')
				continue;
			file.open(file_name + ".txt",ios_base::out);
			if (!file.is_open())
			{
				cout << "ERROR open file" << endl;
				break;
			}
			file << num;
			file << endl;
			for (int i = 0; i < num; i++)
			{
				file << library[i].get_avtor() << endl;
				file << library[i].get_name_book() << endl;
				file << library[i].get_date() << endl;
				file << library[i].get_count_page() << endl;
			}
			cout << endl;
			file.close();
			cout << "Successful save" << endl;
			break;

		}
		case 5:
		{
			delete[]library;
			string file_name;
			cout << "Input file name: ";
			cin >> file_name;
			while (cin.get() != '\n')
				continue;
			file.open(file_name + ".txt", ios_base::in);
			if (!file.is_open())
			{
				cout << "ERROR open file" << endl;
				break;
			}
			file >> num;
			while (file.get() != '\n')
				continue;
			library = new book[num];
			for (size_t i = 0; i < num; i++)
			{
				string n_avt;
				getline(file, n_avt);
				library[i].set_avtor(n_avt);

				string n_bk;
				getline(file, n_bk);
				library[i].set_name_book(n_bk);

				int date;
				file>>date;
				library[i].set_date(date);

				int c_pg;
				file>>c_pg;
				while (file.get() != '\n')
					continue;
				library[i].set_count_page(c_pg);
			}
			file.close();
			cout << "Successful read" << endl;
			break;
		}
		case 6:
		{
			if (library)
			{
				bool flag = true;
				book temp;
				while (flag)
				{
					flag = false;
					for (int i = 0; i < num - 1; i++)
					{
						if (library[i].get_date() > library[i + 1].get_date())
						{
							temp = library[i + 1];
							library[i + 1] = library[i];
							library[i] = temp;
							flag = true;
						}
					}
				}
				cout << "Successful bubble sort" << endl;
				break;
			}
			cout << "Library is empty" << endl;
			break;
		}
		case 7:
		{
			if (library)
			{
				My_qsort(library, 0, num - 1);
				cout << "Successful quick sort" << endl;
				break;
			}
			cout << "Library is empty" << endl;
			break;
		}
		case 8:
		{
			delete[]library;
			flag = false;
			break;
		}
		default:
		{
			cout << "Choose 1-8" << endl;
				break;
		}
		}
	}
	return 0;
}