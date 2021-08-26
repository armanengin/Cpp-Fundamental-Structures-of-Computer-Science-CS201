#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
int* algorithm1(int* arr1, int arr1size, int* arr2, int arr2size) {
	int* arr3 = new int[arr1size + arr2size];
	for (int i = 0; i < arr1size; i++) {
		arr3[i] = arr1[i];
	}
	int lastIndex = arr1size - 1;
	for (int i = 0; i < arr2size; i++) {
		bool smaller = false;
		for (int j = 0; j <= lastIndex; j++) {
			if (arr2[i] <= arr3[j]) {
				for (int k = lastIndex; k >= j; k--) {
					arr3[k + 1] = arr3[k];
				}
				arr3[j] = arr2[i];
				lastIndex++;
				smaller = true;
				break;
			}		
		}
			if(!smaller) {
				arr3[++lastIndex] = arr2[i];
			}	
	}
	return arr3;
}

int* algorithm2(int* arr1, int arr1size, int* arr2, int arr2size) {
	int* arr3 = new int[arr1size + arr2size];
	int control = 0;
	int index1 = 0;
	int index2 = 0;
	while (control < arr1size + arr2size) {
		if (arr1[index1] < arr2[index2] && index1 < arr1size) {
			arr3[control++] = arr1[index1++];
		}
		else if (arr1[index1] == arr2[index2]) {
			arr3[control++] = arr1[index1++];
			arr3[control++] = arr2[index2++];
		}
		else if (arr1[index1] > arr2[index2] && index2 < arr2size) {
			arr3[control++] = arr2[index2++];
		}
		else if (index1 == arr1size && index2 < arr2size){
			for (int i = index2; i < arr2size; i++) {
				arr3[control++] = arr2[index2++];
			}
		}
		else if (index2 == arr2size && index1 < arr1size) {
			for (int i = index1; i < arr1size; i++) {
				arr3[control++] = arr1[index1++];
			}
		}
	}
	return arr3;
}

int main() {	
	srand(time(0));
	double duration = 0;
	//arrays for case i and case ii
	/*
	int* arr1{ new int[10]{ 2 , 5 , 6 , 14 , 19 , 59 , 65 , 78 , 89 , 90 } };
	int* arr2{ new int[10]{157 , 158 , 184 , 194 , 294 , 496 , 687 , 956 , 1049, 1745 } };
	
	int* arr3 = new int[100];
	for (int i = 0; i < 100; i++) {
		arr3[i] = i;
	}
	int a4 = 176;
	int* arr4 = new int[100];
	for (int i = 0; i < 100; i++) {
		arr4[i] = a4++;
	}
	int* arr5 = new int[1000];
	for (int i = 0; i < 1000; i++) {
		arr5[i] = i;
	}
	int a6 = 2894;
	int* arr6 = new int[1000];
	for (int i = 0; i < 1000; i++) {
		arr6[i] = a6++;
	}
	int* arr7 = new int[10000];
	for (int i = 0; i < 10000; i++) {
		arr7[i] = i;
	}
	int* arr8 = new int[10000];
	int a8 = 15678;
	for (int i = 0; i < 10000; i++) {
		arr8[i] = a8++;
	}
	int* arr9 = new int[50000];
	for (int i = 0; i < 50000; i++) {
		arr9[i] = i;
	}
	int* arr10 = new int[50000];
	int a10 = 79536;
	for (int i = 0; i < 50000; i++) {
		arr10[i] = a10++;
	}
	int* arr11 = new int[100000];
	for (int i = 0; i < 100000; i++) {
		arr11[i] = i;
	}
	int* arr12 = new int[100000];
	int a12 = 183490;
	for (int i = 0; i < 100000; i++) {
		arr12[i] = a12++;
	}
	int* arr13 = new int[250000];
	for (int i = 0; i < 250000; i++) {
		arr13[i] = i;
	}
	int* arr14 = new int[250000];
	int a14 = 485903;
	for (int i = 0; i < 250000; i++) {
		arr14[i] = a14++;
	}
	int* arr15 = new int[350000];
	for (int i = 0; i < 350000; i++) {
		arr15[i] = i;
	}
	int* arr16 = new int[350000];
	int a16 = 478303;
	for (int i = 0; i < 350000; i++) {
		arr16[i] = a16++;
	}
	int* arr17 = new int[450000];
	for (int i = 0; i < 450000; i++) {
		arr17[i] = i;
	}
	int* arr18 = new int[450000];
	int a18 = 573893;
	for (int i = 0; i < 450000; i++) {
		arr18[i] = a18++;
	}
	int* arr19 = new int[500000];
	for (int i = 0; i < 500000; i++) {
		arr19[i] = i;
	}
	int* arr20 = new int[500000];
	int a20 = 674920;
	for (int i = 0; i < 500000; i++) {
		arr20[i] = a20++;
	}
	int* arr21 = new int[650000];
	for (int i = 0; i < 650000; i++) {
		arr21[i] = i;
	}
	int* arr22 = new int[650000];
	int a22 = 748494;
	for (int i = 0; i < 650000; i++) {
		arr22[i] = a22++;
	}
	int* arr23 = new int[750000];
	for (int i = 0; i < 750000; i++) {
		arr23[i] = i;
	}
	int* arr24 = new int[750000];
	int a24 = 846738;
	for (int i = 0; i < 750000; i++) {
		arr24[i] = a24++;
	}
	int* arr25 = new int[850000];
	for (int i = 0; i < 850000; i++) {
		arr25[i] = i;
	}
	int* arr26 = new int[850000];
	int a26 = 985035;
	for (int i = 0; i < 850000; i++) {
		arr26[i] = a26++;
	}
	int* arr27 = new int[1000000];
	for (int i = 0; i < 1000000; i++) {
		arr27[i] = i;
	}
	int* arr28 = new int[1000000];
	int a28 = 1789003;
	for (int i = 0; i < 1000000; i++) {
		arr28[i] = a28++;
	}
	
	//for both case i and case ii 
	clock_t startTime1 = clock();
	int* result1 = algorithm1(arr1, 10, arr2, 10);
	duration = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;
	cout << " 10 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime2 = clock();
	int* result2 = algorithm1(arr3, 100, arr4, 100);
	duration = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
	cout << " 100 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime3 = clock();
	int* result3 = algorithm1(arr5, 1000, arr6, 1000);
	duration = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
	cout << " 1000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime4 = clock();
	int* result4 = algorithm1(arr7, 10000, arr8, 10000);
	duration = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;
	cout << " 10000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime5 = clock();
	int* result5 = algorithm1(arr9, 50000, arr10, 50000);
	duration = 1000 * double(clock() - startTime5) / CLOCKS_PER_SEC;
	cout << " 50000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime6 = clock();
	int* result6 = algorithm1(arr11, 100000, arr12, 100000);
	duration = 1000 * double(clock() - startTime6) / CLOCKS_PER_SEC;
	cout << " 100000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime7 = clock();
	int* result7 = algorithm1(arr13, 250000, arr14, 250000);
	duration = 1000 * double(clock() - startTime7) / CLOCKS_PER_SEC;
	cout << " 250000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime8 = clock();
	int* result8 = algorithm1(arr15, 350000, arr16, 350000);
	duration = 1000 * double(clock() - startTime8) / CLOCKS_PER_SEC;
	cout << " 350000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime9 = clock();
	int* result9 = algorithm1(arr17, 450000, arr18, 450000);
	duration = 1000 * double(clock() - startTime9) / CLOCKS_PER_SEC;
	cout << " 450000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime10 = clock();
	int* result10 = algorithm1(arr19, 500000, arr20, 500000);
	duration = 1000 * double(clock() - startTime10) / CLOCKS_PER_SEC;
	cout << " 500000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime11 = clock();
	int* result11 = algorithm1(arr21, 650000, arr22, 650000);
	duration = 1000 * double(clock() - startTime11) / CLOCKS_PER_SEC;
	cout << " 650000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime12 = clock();
	int* result12 = algorithm1(arr23, 750000, arr24, 750000);
	duration = 1000 * double(clock() - startTime12) / CLOCKS_PER_SEC;
	cout << " 750000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime13 = clock();
	int* result13 = algorithm1(arr25, 850000, arr26, 850000);
	duration = 1000 * double(clock() - startTime13) / CLOCKS_PER_SEC;
	cout << " 850000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime14 = clock();
	int* result14 = algorithm1(arr27, 1000000, arr28, 1000000);
	duration = 1000 * double(clock() - startTime14) / CLOCKS_PER_SEC;
	cout << " 1000000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;
	*/
	

	//case iii
	int* ranArr1{ new int[10]{ 2573 , 532 , 6142 , 123 , 1932 , 593 , 65 , 7831 , 893 , 904 } };
	int* ranArr2{ new int[10]{1574 , 158 , 4 , 194 , 2924 , 642 , 67 , 956 , 49, 45 } };

int* ranArr3 = new int[100];
	for (int i = 0; i < 100; i++) {
		ranArr3[i] = rand();
	}
	sort(ranArr3, ranArr3 + 100);

int* ranArr4 = new int[100];
	for (int i = 0; i < 100; i++) {
		ranArr4[i] = rand();
	}
	sort(ranArr4, ranArr4 + 100);

int* ranArr5 = new int[1000];
	for (int i = 0; i < 1000; i++) {
		ranArr5[i] = rand();
	}
	sort(ranArr5, ranArr5 + 1000);

int* ranArr6 = new int[1000];
	for (int i = 0; i < 1000; i++) {
		ranArr6[i] = rand();
	}
	sort(ranArr6, ranArr6 + 1000);

int* ranArr7 = new int[10000];
	for (int i = 0; i < 10000; i++) {
		ranArr7[i] = rand();
	}
	sort(ranArr7, ranArr7 + 10000);

int* ranArr8 = new int[10000];
	for (int i = 0; i < 10000; i++) {
		ranArr7[i] = rand();
	}
	sort(ranArr8, ranArr8 + 10000);

int* ranArr9 = new int[50000];
	for (int i = 0; i < 50000; i++) {
		ranArr9[i] = rand();
	}
	sort(ranArr9, ranArr9 + 50000);

int* ranArr10 = new int[50000];
	for (int i = 0; i < 50000; i++) {
		ranArr9[i] = rand();
	}
	sort(ranArr10, ranArr10 + 50000);

int* ranArr11 = new int[100000];
	for (int i = 0; i < 100000; i++) {
		ranArr11[i] = rand();
	}
	sort(ranArr11, ranArr11 + 100000);

int* ranArr12 = new int[100000];
	for (int i = 0; i < 100000; i++) {
		ranArr11[i] = rand();
	}
	sort(ranArr12, ranArr12 + 100000);

int* ranArr13 = new int[250000];
	for (int i = 0; i < 250000; i++) {
		ranArr13[i] = rand();
	}
	sort(ranArr13, ranArr13 + 250000);

int* ranArr14 = new int[250000];
	for (int i = 0; i < 250000; i++) {
		ranArr14[i] = rand();
	}
	sort(ranArr14, ranArr14 + 250000);

int* ranArr15 = new int[350000];
	for (int i = 0; i < 350000; i++) {
		ranArr15[i] = rand();
	}
	sort(ranArr15, ranArr15 + 350000);

int* ranArr16 = new int[350000];
	for (int i = 0; i < 350000; i++) {
		ranArr16[i] = rand();
	}
	sort(ranArr16, ranArr16 + 350000);

int* ranArr17 = new int[450000];
	for (int i = 0; i < 450000; i++) {
		ranArr17[i] = rand();
	}
	sort(ranArr17, ranArr17 + 450000);

int* ranArr18 = new int[450000];
	for (int i = 0; i < 450000; i++) {
		ranArr18[i] = rand();
	}
	sort(ranArr18, ranArr18 + 450000);

int* ranArr19 = new int[500000];
	for (int i = 0; i < 500000; i++) {
		ranArr19[i] = rand();
	}
	sort(ranArr19, ranArr19 + 500000);

int* ranArr20 = new int[500000];
	for (int i = 0; i < 500000; i++) {
		ranArr20[i] = rand();
	}
	sort(ranArr20, ranArr20 + 500000);

int* ranArr21 = new int[650000];
	for (int i = 0; i < 650000; i++) {
		ranArr21[i] = rand();
	}
	sort(ranArr21, ranArr21 + 650000);

int* ranArr22 = new int[650000];
	for (int i = 0; i < 650000; i++) {
		ranArr22[i] = rand();
	}
	sort(ranArr22, ranArr22 + 650000);

int* ranArr23 = new int[750000];
	for (int i = 0; i < 750000; i++) {
		ranArr23[i] = rand();
	}
	sort(ranArr23, ranArr23 + 750000);

int* ranArr24 = new int[750000];
	for (int i = 0; i < 750000; i++) {
		ranArr24[i] = rand();
	}
	sort(ranArr24, ranArr24 + 750000);

	int* ranArr25 = new int[850000];	
	for (int i = 0; i < 850000; i++) {
		ranArr25[i] = rand();
	}
	sort(ranArr25, ranArr25 + 850000);

int* ranArr26 = new int[850000];
	for (int i = 0; i < 850000; i++) {
		ranArr26[i] = rand();
	}
	sort(ranArr26, ranArr26 + 850000);

int* ranArr27 = new int[1000000];
	for (int i = 0; i < 1000000; i++) {
		ranArr27[i] = rand();
	}
	sort(ranArr27, ranArr27 + 1000000);

	int* ranArr28 = new int[1000000];	
	for (int i = 0; i < 1000000; i++) {
		ranArr28[i] = rand();
	}
	sort(ranArr28, ranArr28 + 1000000);

	clock_t startTime15 = clock();
	int* result15 = algorithm2(ranArr1, 10, ranArr2, 10);
	duration = 1000 * double(clock() - startTime15) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 10 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime16 = clock();
	int* result16 = algorithm2(ranArr3, 100, ranArr4, 100);
	duration = 1000 * double(clock() - startTime16) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 100 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime17 = clock();
	int* result17 = algorithm2(ranArr5, 1000, ranArr6, 1000);
	duration = 1000 * double(clock() - startTime17) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 1000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime18 = clock();
	int* result18 = algorithm2(ranArr7, 10000, ranArr8, 10000);
	duration = 1000 * double(clock() - startTime18) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 10000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime19 = clock();
	int* result19 = algorithm2(ranArr9, 50000, ranArr10, 50000);
	duration = 1000 * double(clock() - startTime19) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 50000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime20 = clock();
	int* result20 = algorithm2(ranArr11, 100000, ranArr12, 100000);
	duration = 1000 * double(clock() - startTime20) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 100000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime21 = clock();
	int* result21 = algorithm2(ranArr13, 250000, ranArr14, 250000);
	duration = 1000 * double(clock() - startTime21) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 250000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime22 = clock();
	int* result22 = algorithm2(ranArr15, 350000, ranArr16, 350000);
	duration = 1000 * double(clock() - startTime22) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 350000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime23 = clock();
	int* result23 = algorithm2(ranArr17, 450000, ranArr18, 450000);
	duration = 1000 * double(clock() - startTime23) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 450000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime24 = clock();
	int* result24 = algorithm2(ranArr19, 500000, ranArr20, 500000);
	duration = 1000 * double(clock() - startTime24) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 500000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime25 = clock();
	int* result25 = algorithm2(ranArr21, 650000, ranArr22, 650000);
	duration = 1000 * double(clock() - startTime25) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 650000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime26 = clock();
	int* result26 = algorithm2(ranArr23, 750000, ranArr24, 750000);
	duration = 1000 * double(clock() - startTime26) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 750000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime27 = clock();
	int* result27 = algorithm2(ranArr25, 850000, ranArr26, 850000);
	duration = 1000 * double(clock() - startTime27) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 850000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

	clock_t startTime28 = clock();
	int* result28 = algorithm2(ranArr27, 1000000, ranArr28, 1000000);
	duration = 1000 * double(clock() - startTime28) / CLOCKS_PER_SEC;
	cout << "Execution took for case iii - 1000000 input sizes: " << duration << " milliseconds." << endl;
	duration = 0;

/*
	delete[] result1;
	delete[] result2;
	delete[] result3;
	delete[] result4;
	delete[] result5;
	delete[] result6;
	delete[] result7;
	delete[] result8;
	delete[] result9;
	delete[] result10;
	delete[] result11;
	delete[] result12;
	delete[] result13;
	delete[] result14;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;
	delete[] arr11;
	delete[] arr12;
	delete[] arr13;
	delete[] arr14;
	delete[] arr15;
	delete[] arr16;
	delete[] arr17;
	delete[] arr18;
	delete[] arr19;
	delete[] arr20;
	delete[] arr21;
	delete[] arr22;
	delete[] arr23;
	delete[] arr24;
	delete[] arr25;
	delete[] arr26;
	delete[] arr27;
	delete[] arr28;
	*/

	delete[] result15;
	delete[] result16;
	delete[] result17;
	delete[] result18;
	delete[] result19;
	delete[] result20;
	delete[] result21;
	delete[] result22;
	delete[] result23;
	delete[] result24;
	delete[] result25;
	delete[] result26;
	delete[] result27;
	delete[] result28;
	delete[] ranArr1;
	delete[] ranArr2;
	delete[] ranArr3;
	delete[] ranArr4;
	delete[] ranArr5;
	delete[] ranArr6;
	delete[] ranArr7;
	delete[] ranArr8;
	delete[] ranArr9;
	delete[] ranArr10;
	delete[] ranArr11;
	delete[] ranArr12;
	delete[] ranArr13;
	delete[] ranArr14;
	delete[] ranArr15;
	delete[] ranArr16;
	delete[] ranArr17;
	delete[] ranArr18;
	delete[] ranArr19;
	delete[] ranArr20;
	delete[] ranArr21;
	delete[] ranArr22;
	delete[] ranArr23;
	delete[] ranArr24;
	delete[] ranArr25;
	delete[] ranArr26;
	delete[] ranArr27;
	delete[] ranArr28;
	
}