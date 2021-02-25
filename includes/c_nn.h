#ifndef FT_C_NN_H
#define FT_C_NN_H
#include "array_list.h"
#include "stringbuilder.h"
#include "matrix.h"

#define LEARINING_RATE 0.01
typedef struct s_layer{
      t_matrix *bias;
      t_matrix *wieghts;
      
}             t_layer;

typedef struct  s_neural_network
{
  t_layer       *input_layer;
  t_array_list  hidden_layers;
  t_layer       *output_layer;

  void (*train)(struct s_neural_network *this, double **data, size_t rows, size_t cols);
  double *(*guess)(struct s_neural_network *this, double *data , size_t size_of_data);
  void (*free)(struct s_neural_network *this)
}             t_neural_network;

#endif