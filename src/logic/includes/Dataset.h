//
// Created by Louvenia Dione on 1/14/23.
//

#ifndef LOGIC_DATASET_H
#define LOGIC_DATASET_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#define STD_DSET "../../datasets/emnist-letters/emnist-letters-test.csv"
//#define STD_TRAINT_DSET "../../datasets/emnist-letters/emnist-letters-train.csv"
#define STD_TRAINT_DSET "/Users/ldione/Desktop/MLP/datasets/emnist-letters/emnist-letters-train.csv"
typedef std::vector<int *>	vv_int;
typedef std::vector<int>				v_int;
typedef std::vector<std::string>		v_str;




namespace s21 {
	class Dataset {
	private:
		vv_int	dataset;
		std::vector<int>	map;
		bool	is_train;
		int		amount;

	public:
		Dataset(char *filepath, bool is_train);
		vv_int&					getDataSet( void );
		std::vector<int>&	getMap ( void );
		bool				getCondition( void );
		int 				getAmount( void );
		v_str				getNextLine(std::istream& filepath);
	};
}

#endif //LOGIC_DATASET_H
