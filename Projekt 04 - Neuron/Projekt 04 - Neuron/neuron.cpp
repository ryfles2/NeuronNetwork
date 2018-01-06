#include "neuron.h"

// Konstruktor
Neuron::Neuron(const int _size) {
	//zabespieczenie
	if (_size == 0) return;

	size = 7;

	weight = new double*[size];
	for (int i = 0; i < size; i++)
	{
		//losowanie wagi od -1 do 1
		weight[i] = new double (- 1 + (double)rand() / RAND_MAX *(1 - (-1)));
	}
}

// Destruktor
Neuron::~Neuron() {
	if (weight)
	{
		for (int i = 0; i < size; i++)
		{
			if (weight[i]) delete weight[i];
		}
			
	}
}

// Funkcja uczaca neuron
double Neuron::learn(const bool* array, const double answer) {
	// Obliczam net
	double net = 0.0;
	for (int i = 0; i < size; i++)
		net += (array[i] == true) ? *(weight[i]) : 0.0;

	// Obliczam sygnal wyjsciowy
	double y = 1.0 / (1.0 + exp(-net));

	// Uaktualnianie wag
	for (int i = 0; i < size; i++)
		*weight[i] += 0.002 * (answer - y) * (1.0 - y) * static_cast<double>(array[i]) * y;

	// Obliczam E(w)
	double e = 0.5 * (answer - y) * (answer - y);

	return e;
}

// Obliczanie wartosci dla danych testowych
double Neuron::count(const bool* array) {
	double net = 0.0;

	for (int i = 0; i < size; i++)
		net += (array[i] == true) ? *weight[i] : 0.0;

	return 1.0 / (1.0 + exp(-net));
}
