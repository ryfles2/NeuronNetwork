#include "neuron.h"

// Konstruktor
Neuron::Neuron(const int& size) {
	if (size == 0)
		return;

	this->size = size;

	weight = new double*[this->size];
	for (int i = 0; i < this->size; i++)
		weight[i] = new double(((rand() % 10000) * ((rand() & 1) ? 1 : -1)) / 10000.0);
}

// Destruktor
Neuron::~Neuron() {
	if (weight)
		for (int i = 0; i < size; i++)
			if (weight[i])
				delete weight[i];
}

// Funkcja uczaca neuron
double Neuron::learn(const bool* array, const double& answer) {
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
