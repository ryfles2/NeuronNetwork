#include <cstdlib>
#include <iostream>
#include <ctime>
#include "neuron.h"

using namespace std;


const bool P1[SIZE] = { 1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1 }; //A
const bool P2[SIZE] = { 1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1 }; //C

const bool P3[SIZE] = { 0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1 }; //A
const bool P4[SIZE] = { 1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1 }; //
const bool P5[SIZE] = { 1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1 }; //C
const bool P6[SIZE] = { 1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1 }; //C

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Neuron neuron(SIZE);

	double e = 0.0;
	do {
		e = 0.0;
		if (rand() % 2 == 0) {
			e += neuron.learn(P1, 1.0);
			e += neuron.learn(P2, 0.0);
		}
		else {
			e += neuron.learn(P2, 0.0);
			e += neuron.learn(P1, 1.0);
		}
	} while (e > 0.0001);

	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P1[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P1);

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P2[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P2);

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P3[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P3);

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P4[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P4);

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P5[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P5);

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0) cout << endl;
		(P6[i] == true) ? cout << "#" : cout << " ";
	}
	cout << " " << neuron.count(P6);

	int t;
	cin >> t;

	return 0;
}
