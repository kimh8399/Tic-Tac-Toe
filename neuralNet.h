#ifndef NEURALNET_H_INCLUDED
#define NEURALNET_H_INCLUDED

#include "libraries.h"

class Neuron;

typedef  vector<Neuron> Layer;

struct Connection
{
    int weight;
    int deltaWeight;
};

class Neuron
{
public:
    Neuron(unsigned numOutputs);
private:
    double randomWeight() {return rand() / RAND_MAX;}
    double outputValue;
    vector <Connection> outputWeights;

};

class Net
{
public:
    Net(const vector <unsigned> topology);
    void feedForward(const vector <unsigned> &inputValues);
    void backProp(const vector <unsigned> &testValues);
    void getResult(unsigned probability);
private:
    vector <Layer> n_layers;
};

#endif // NEURALNET_H_INCLUDED
