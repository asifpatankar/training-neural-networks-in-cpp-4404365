#include "MLP.h"

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}


// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(size_t inputs, double bias){
	this->bias = bias;
	weights.resize(inputs+1);
	generate(weights.begin(),weights.end(),frand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(std::vector<double> x){
	x.push_back(bias);
	double sum = inner_product(x.begin(),x.end(),weights.begin(),(double)0.0);
	return sigmoid(sum);
}

// Set the weights. w_init is a vector with the weights.
void Perceptron::set_weights(std::vector<double> w_init){
	weights = w_init;
}

// Evaluate the sigmoid function for the floating point input x.
double Perceptron::sigmoid(double x){
	return 1.0/(1.0 + exp(-x));
}


// Return a new MultiLayerPerceptron object with the specified parameters.
MultiLayerPerceptron::MultiLayerPerceptron(std::vector<size_t> layers, double bias, double eta) {
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;

    for (size_t i = 0; i < layers.size(); i++){
        values.push_back(std::vector<double>(layers[i],0.0));
        d.push_back(std::vector<double>(layers[i],0.0));
        network.push_back(std::vector<Perceptron>());
        if (i > 0)   //network[0] is the input layer,so it has no neurons
            for (size_t j = 0; j < layers[i]; j++)
                network[i].push_back(Perceptron(layers[i-1], bias));
    }
}


// Set the weights. w_init is a vector of vectors of vectors with the weights for all but the input layer.
void MultiLayerPerceptron::set_weights(std::vector<std::vector<std::vector<double> > > w_init) {
    for (size_t i = 0; i < w_init.size(); i++)
        for (size_t j = 0; j < w_init[i].size(); j++)
            network[i+1][j].set_weights(w_init[i][j]);
}

void MultiLayerPerceptron::print_weights() {
    std::cout << std::endl;
    for (size_t i = 1; i < network.size(); i++){
        for (size_t j = 0; j < layers[i]; j++) {
            std::cout << "Layer " << i+1 << " Neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                std::cout << it << "   ";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Feed a sample x into the MultiLayer Perceptron.
std::vector<double> MultiLayerPerceptron::run(std::vector<double> x) {
    values[0] = x;
    for (size_t i = 1; i < network.size(); i++)
        for (size_t j = 0; j < layers[i]; j++)
            values[i][j] = network[i][j].run(values[i-1]);
    return values.back();
}


// Challenge: Implement the bp() function:


// Run a single (x,y) pair with the backpropagation algorithm.
double MultiLayerPerceptron::bp(std::vector<double> x, std::vector<double> y){
    
    // Backpropagation Step by Step:
    
    // STEP 1: Feed a sample to the network
    
    // STEP 2: Calculate the MSE
    double MSE = 0.0;
    
    // STEP 3: Calculate the output error terms
    
    // STEP 4: Calculate the error term of each unit on each layer    
    for (size_t i = network.size()-2; i > 0; i--)
        for (size_t h = 0; h < network[i].size(); h++){
            double fwd_error = 0.0;
            for (size_t k = 0; k < layers[i+1]; k++)
                ; // fill in the blank
            ; // fill in the blank
        }
    
    // STEPS 5 & 6: Calculate the deltas and update the weights
    for (size_t i = 1; i < network.size(); i++)
        for (size_t j = 0; j < layers[i]; j++)
            for (size_t k = 0; k < layers[i-1]+1; k++){
                // fill in the blank
            }
    return MSE;
}

