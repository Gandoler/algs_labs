#include <iostream>
#include <list>
#include <time.h>
using namespace std;



class Lab_1 {
private:
	int len_mas = 1;
	int* masik;
	int counter = 0;
	void Create_random_list_of_numbers() {
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



	void Print_mas() {
		for (int i = 0; i < this->len_mas - 1; i++) {
			if (i % 20 == 0)printf("\n");
			printf("%d,\t", this->masik[i]);
		}
		printf("\n#############################################################################################################################################################\n");
		printf("%d - Количество итераций", counter);
		
	}

	void rerarndom() {
		delete this->masik;
		cout << "Введите длинну массива\t";
		cin >> this->len_mas;
		this->masik = new int[len_mas];
		Create_random_list_of_numbers();
	}
	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void Hoara_sort() {
		this->counter = 0;
		rec(this->masik, 0, this->len_mas - 1);
	}


	void Shella_sort() {
		this->counter = 0;
		int stepchik = len_mas / 2;
		Shelik_try_recurs(stepchik);
	}
	int binarySearch(int key) {
		return binary_rec(0, this->len_mas - 1, key);

	}

	void rec(int* tmp_masik, int first, int last) {
		this->counter = this->counter + 1;
		if (last-first >= 0) {
			int x = tmp_masik[(first + last) / 2];
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
			if (i < last) rec(tmp_masik, i, last);
			if (first < j) rec(tmp_masik, first, j+1);// тут наугад поставил +1 и ошибочные фрагменты исчезли
		}
	}
	void Shelik_try_recurs(int stepchik) {
		this->counter++;
		if (stepchik >= 1) {
			for (int i = stepchik; i < this->len_mas; i++) {
				int temp = this->masik[i];
				int j;
				for (j = i; j >= stepchik && this->masik[j - stepchik] > temp; j -= stepchik) {
					this->masik[j] = this->masik[j - stepchik];
				}
				this->masik[j] = temp;
			}
			Shelik_try_recurs(stepchik / 2);
		}
	}

	int  binary_rec(int start, int end,int key) {
		if (end >= start) {
			int mid = start + (end - start) / 2;
			if (this->masik[mid] == key) {
				return mid;
			}
			if (this->masik[mid] > key) {
				return binary_rec(start, mid - 1, key);
			}
			else {
				return binary_rec(mid+1, end, key);
			}
		}
		return -1;
	}


};

void First_lab_1_task() {
	Lab_1* laba = new Lab_1;
	laba->Print_mas();
	laba->Hoara_sort();
	laba->Print_mas();
}

void First_lab_2_task() {
	Lab_1* laba = new Lab_1;
	laba->Print_mas();
	laba->Shella_sort();
	laba->Print_mas();
}


void First_lab_3_task() {
	Lab_1* laba = new Lab_1;
	laba->Hoara_sort();
	laba->Print_mas();
	cout << "\nВведите искомое число\n";
	int num;
	cin >> num;
	printf("\nИндекс этого числа-%d\n", laba->binarySearch(num));
	
}



int main() {
	system("chcp 1251");
	srand(time(NULL));
	First_lab_3_task();

	

	return 0;
}
