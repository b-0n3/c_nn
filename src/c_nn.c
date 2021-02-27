#include "c_nn.h"
// @author B-0n3@1337


void new_neural_network
(t_neural_network *this, size_t nb_inputs, size_t nb_hidden_layers, size_t nb_output){
    if (this == NULL)
      THROW(NULL_POINTER_EXCEPTION, "null pointer neural_network In c_nn:: new_neural_network");
    
}

t_neural_network *new_neural_network_p
  ( size_t nb_inputs, size_t nb_hidden_layers, size_t nb_output){

}

void train(t_neural_network *this, double **data , size_t rows, size_t cols){

}

double *guess(t_neural_network *this, double *data, size_t size_of_data){

}

void free_neural_network(t_neural_network *this)
{

}

double activation_function(double value){
    return 1 / (1 - exp(-value));
}

double deactivation_function(double y){
    return y * (1 / y);
}
