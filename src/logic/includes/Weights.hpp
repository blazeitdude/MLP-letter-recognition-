//
// Created by Louvenia Dione on 1/15/23.
//

#ifndef LOGIC_WEIGHTS_HPP
#define LOGIC_WEIGHTS_HPP

#include <cstdlib>
#include <fstream>

namespace s21 {

	class Weights {
	private:
		int			row;
		int			col;
	public:
		double	**matrix;
		void			init(int row, int col);
		void			randomize(void );
		static void		multi(const Weights& matrix, const double* multiplier, int size_m, double *result);
		static void 	multi_T(const Weights& matrix, const double* multiplier, int size_m, double *result);
		static void		sumVector(double *a, const double *b, int size);
		double			&operator()(int i, int j);
		friend std::ostream&	operator<<(std::ostream &stream, const Weights &m);
		friend std::istream&	operator>>(std::istream &stream, Weights &m);
	};

} // s21

#endif //LOGIC_WEIGHTS_HPP
