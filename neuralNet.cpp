#include "neuralNet.h"

Neuron::Neuron(unsigned numOutputs)
{
    for(unsigned i = 0; i < numOutputs; i++)
    {
        outputWeights.push_back(Connection());
        outputWeights.back().weight = randomWeight();
    }
}

Net::Net(const vector <unsigned> topology)
{
    for(unsigned layerNum = 0; layerNum < topology.size(); layerNum++)
    {
        n_layers.push_back(Layer());
        unsigned numOutputs = (layerNum == topology.size()-1) ? 0 : topology[layerNum + 1];
        for(unsigned n = 0; n <= topology[layerNum]; n++)
        {
            n_layers.back().push_back(Neuron(numOutputs));
            cout<<"Made a neuron";
        }
    }
}

Net::feedForward(const vector<unsigned> &inputValues)
{
    for(unsigned layerNum = 0; )
}
