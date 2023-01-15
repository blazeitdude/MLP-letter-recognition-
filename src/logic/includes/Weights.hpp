//
// Created by Louvenia Dione on 1/15/23.
//

#ifndef LOGIC_WEIGHTS_HPP
#define LOGIC_WEIGHTS_HPP

#include <cstdlib>

namespace s21 {

	class Weights {
	private:
		double**	matrix;
		int			row;
		int			col;
	public:
		void			init(int row, int col);
		void			randomize(void );
		static void		multi(const Weights& matrix, const double* multiplier, int size_m, double *result);
		static void		sumVector(double *a, const double *b, int size);
	};

} // s21

#endif //LOGIC_WEIGHTS_HPP
