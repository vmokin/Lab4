// ������� ������ �������; ������������; ��������� �� �������; ����������������; ��������� �� �������
#include "stdafx.h"
#include <iostream>
using namespace std;

class Ring1000 {
private:
	unsigned int R;
public:
	Ring1000() {};						//constructor
	Ring1000 R1000(int _R) { 
		R = _R % 1000;
	};
	void Input() {
		cout << "enter your element";
		cin >> R;
		R1000(R);
	};
	Ring1000 operator+(Ring1000 A) {
		unsigned int B;
		B = (R + A.R)%1000;
		return;
	};
	Ring1000 operator*(Ring1000 A) {
		unsigned int B;
		B = (R * A.R) % 1000;
		return;
	};
	~Ring1000() {};						//destructor
};

class Matrix:public Ring1000 {
private:
	Ring1000** MatrixRing1000;
public:
	int Size_L, Size_C;
	Matrix(int Size_Line, int Size_Column) {//constructor
		Size_L = Size_Line;
		Size_C = Size_Column;
		MatrixRing1000 = new Ring1000*[Size_Line];
		for (int i = 0; i < Size_Column-1; i++)
			MatrixRing1000[i] = new Ring1000[Size_Column];
	};									
	Ring1000** operator+(Ring1000** A) {//concatenation
		int Size_L2 = Size_L + A.Size_L;
		int Size_C2 = Size_C + A.Size_C;
		Ring1000** MatrixRing1000_2;
		MatrixRing1000_2 = new Ring1000*[Size_L2];
		for (int i = 0; i < Size_C2 - 1; i++)
			MatrixRing1000_2[i] = new Ring1000[Size_C2];
		for (int i = 0; i < Size_L - 1; i++) {
			for (int j = 0; j < Size_C2 - 1; j++) {
				MatrixRing1000_2[i][j] = MatrixRing1000[i][j];
			};
		}; 
		for (int i = Size_L; i < Size_L2 - 1; i++) {
			for (int j = 0; j < Size_C2 - 1; j++) {
				MatrixRing1000_2[i][j] = MatrixRing1000[i][j];
			};
		};
	};
	Ring1000** operator*() {//multiplying by the number
		int l, c;
		cout << "enter line of your element";
		cin >> l;
		cout << "enter column of your element";
		cin >> c;
		for (int i = 0; i < Size_L; i++) {
			for (int j = 0; j < Size_C; j++) {
				MatrixRing1000[i][j] = MatrixRing1000[i][j] * MatrixRing1000[l][c];
			};
		};
	};
	Ring1000** operator~() {//transposition
		Ring1000** MatrixRing1000_new;
		MatrixRing1000_new = new Ring1000*[Size_C];
		for (int i = 0; i < Size_L - 1; i++)
			MatrixRing1000_new[i] = new Ring1000[Size_L];
		for (int i = 0; i < Size_L-1; i++) {
			for (int j = 0; j < Size_C-1; j++) {
				MatrixRing1000_new[i][j] = MatrixRing1000[j][i];
			};
		};
	};
};

int main()
{
    return 0;
}

