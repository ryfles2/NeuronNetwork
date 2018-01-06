#include <cstdlib>
#include <iostream>
#include <ctime>
#include "neuron.h"

using namespace std;


const bool P1[SIZE] = { 1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1 }; //A
const bool P2[SIZE] = { 1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1 }; //C

//const bool P3[SIZE] = {}// sprawdzanie sieci


int main(int argc, char *argv[]) {
	srand(time(NULL));
	Neuron neuron(SIZE);

	//**********************************************************NAUKA
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
	} while (e > 0.0001);//warunek uczenia
	//**********************************************************NAUKA KONIEC


	for (int i = 0; i < SIZE; i++) 
	{
		if (i % 5 == 0) cout << endl;
		if (P1[i] == true)cout << "#";
		else cout << " ";
	}
	cout << " " << neuron.count(P1);

	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 5 == 0) cout << endl;
		if (P2[i] == true)cout << "#";
		else cout << " ";
	}
	cout << " " << neuron.count(P2);


	//SPRAWDZANIE
	/*cout << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		if (i % 5 == 0) cout << endl;
		if (P3[i] == true)cout << "#";
		else cout << " ";
	}
	cout << " " << neuron.count(P3);
	*/
	

	cout << endl;
	return 0;
}
