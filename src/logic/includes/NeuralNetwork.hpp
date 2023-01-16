//
// Created by Louvenia Dione on 1/15/23.
//

#ifndef LOGIC_NEURALNETWORK_HPP
#define LOGIC_NEURALNETWORK_HPP

#include <cmath>
#include <ctime>
#include "Weights.hpp"
#include "Dataset.hpp"
#include <iostream>

namespace s21 {

	class NeuralNetwork {
	private:

		int		layers;
		int 	*size;
		Weights	*matrix;
		Dataset	*dataset;
		double	**bios;
		double 	**neuron, **neuron_err;
		double 	*neuron_bios;


	public:
		void	activate_func(double *value, int len);
		void	derivative(double *value, int len);
		double 	derivative(double value);
		void 	init();
		//void 	close
		void 	init_layers( int *neuro_amount, int count);
		void	set_input(double *ex);
		double	forwardFeed();
		double 	searchMaxIndex(double *value);
		void 	backPropogation(double expect);
		void 	update_weights(double lr);
		void 	save_weights( void );
		void 	downloads_weights( void );
	};

} // s21

#endif //LOGIC_NEURALNETWORK_HPP
