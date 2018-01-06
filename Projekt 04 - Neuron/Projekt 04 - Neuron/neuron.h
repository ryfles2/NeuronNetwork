#include <iostream>
#include <cmath>

#define SIZE 35

using namespace std;

class Neuron {
public:
	// Konstruktor
	Neuron(const int& size);

	// Destruktor
	~Neuron();

	// Funkcja uczaca neuron
	double learn(const bool* array, const double& answer);

	// Obliczanie wartosci dla danych testowych
	double count(const bool* array);
private:
	int size;
	double **weight;
};
