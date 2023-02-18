//
// Created by Louvenia Dione on 2/3/23.
//

#ifndef MLP_2_0_MATRIXNET_HPP
#define MLP_2_0_MATRIXNET_HPP
#include <cmath>
#include "Net.hpp"


namespace s21 {

	class MatrixNet : public NetInterface {
	public:
		void			backPropagation(v_double& right) override;
		void			forwardFeed() override;
		void			feedInitValues(const v_double& values) override;
		void			saveExperience(std::string path) override;
		bool			readExperience(std::string path) override;
		void			setLayers(std::vector<config> info) override;

		size_t			getResult() override;
		const v_double	getResVector() override;

	private:
		std::vector<Matrix>	neurons;
		std::vector<Matrix>	weights;
		v_double			biases;

		void	initWeights(Matrix& matrix);
		double	randomWeight();
		void	gradient(v_double &grads, const v_double &expect, size_t layer);
	};

} // s21

#endif //MLP_2_0_MATRIXNET_HPP
