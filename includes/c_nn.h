#ifndef FT_C_NN_H
#define FT_C_NN_H
#include "array_list.h"
#include "stringbuilder.h"
#include "matrix.h"

#define LEARINING_RATE 0.01
typedef struct s_layer{
      t_matrix *bias;
      t_matrix *wieghts;
      t_matrix *(*feed_forward)(struct s_layer *this,t_matrix input);
      t_matrix *(*correct)(struct s_layer *this, t_matrix errors);
      void (*free)(void *item);

}             t_layer;

typedef struct  s_neural_network
{
  t_layer       *input_layer;
  t_array_list  hidden_layers;
  t_layer       *output_layer;

  void (*train)(struct s_neural_network *this, double **data, size_t rows, size_t cols);
  double *(*guess)(struct s_neural_network *this, double *data , size_t size_of_data);
  void (*free)(struct s_neural_network *this);
}             t_neural_network;
// neural_network
void new_neural_network(t_neural_network *this, size_t nb_inputs, size_t nb_hidden_layers, size_t nb_output);
t_neural_network *new_neural_network_p( size_t nb_inputs, size_t nb_hidden_layers, size_t nb_output);
void train(t_neural_network *this, double **data , size_t rows, size_t cols);
double *guess(t_neural_network *this, double *data, size_t size_of_data);
void free_neural_network(t_neural_network *this);
double activation_function(double value);
double deactivation_function(double value);

// layer
void new_layer(t_layer *this,size_t nb_node_in, size_t nb_node_out);
t_layer *new_layer_p(size_t nb_node_in, size_t nb_node_out);
t_matrix *feed_forward(struct s_layer *this,t_matrix input);
t_matrix *correct(struct s_layer *this, t_matrix errors);
void free(void *item);
#endif