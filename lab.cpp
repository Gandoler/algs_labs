#include <iostream>
#include <list>
#include <time.h>
using namespace std;



class Lab_1 {
private:
	int len_mas = 1;
	int  *masik;
	void Create_random_list_of_numbers(){
		
		
		
		int tmp_number = 0;
		int MAXVALUE = 1000;
		int MINVALUE = -1000;
		
		for (int i = 0; i < len_mas; i++) {
			tmp_number = MINVALUE + rand() % (MAXVALUE - MINVALUE + 1);
			this->masik[i] = tmp_number;
		}
	}
	int getRandom(int a, int b) {
		
		int randomnumber = rand() % 2;
		return (randomnumber == 0) ? a : b;
	}
public:
	Lab_1() {
		cout << "Введите длинну массива\t";
		cin >> this->len_mas;
		this->masik = new int[len_mas];
		Create_random_list_of_numbers();
	}


	~Lab_1() {
		delete this->masik;
	}

	void Hoara_sort() {
		rec(this->masik, 0, this->len_mas);
	}


	void Print_mas() {
		for (int i = 0; i < this->len_mas-1; i++) {
			if (i % 10 == 0)printf("\n");
			printf("%d,\t", this->masik[i]);
		}
		printf("\n############################################################################");
	}
	
	void rec(int * tmp_masik, int first, int last) {
		if (last > 1) {
			int x = tmp_masik[(first+last)/2];
			int i = first, j = last - 1;
			do {
				while (tmp_masik[i] < x)i++;
				while (tmp_masik[j] > x)j--;

				if (i <= j) {
					if (tmp_masik[i] > tmp_masik[j]) swap(tmp_masik[i], tmp_masik[j]);
					i++;
					j--;
				}
			} while (i <= j);
			if (i < last) rec(tmp_masik,i,last);
			if (first < j) rec(tmp_masik, first, j);
		}
	}

};






int main() {
	system("chcp 1251");
	srand(time(NULL));
	Lab_1 *laba = new Lab_1;
	laba->Print_mas();
	laba->Hoara_sort();
	laba->Print_mas();
	
	return 0;
}
