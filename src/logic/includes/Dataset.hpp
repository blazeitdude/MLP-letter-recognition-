//
// Created by Louvenia Dione on 1/14/23.
//

#ifndef LOGIC_DATASET_HPP
#define LOGIC_DATASET_HPP

#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#define STD_DSET	"../../datasets/emnist-letters/emnist-letters-test.csv"
//#define STD_TRAINT_DSET	"../../datasets/emnist-letters/emnist-letters-train.csv"
#define STD_TRAINT_DSET	"/Users/ldione/Desktop/MLP/datasets/emnist-letters/emnist-letters-train.csv"
#define TRAIN_MODE	1
typedef std::vector<double *>				v_intp;
typedef std::vector<int>				v_int;
typedef std::vector<std::string>		v_str;




namespace s21 {
	class Dataset {
	private:
		v_intp	dataset;
		bool	is_train;
		int		amount;
		v_int	map;
		int		size;
		int		min;
		int 	max;

	public:
		void read_csv_dataset(char *filepath, bool is_train);
		v_intp&				getDataSet(void );
		bool				getCondition( void );
		int 				getAmount( void );
		int 				getSize( void );
		v_int&				getMap( void );

		void 				normalize( void );
		void 				DEV_PRINT( void );
	};
}

#endif //LOGIC_DATASET_HPP
