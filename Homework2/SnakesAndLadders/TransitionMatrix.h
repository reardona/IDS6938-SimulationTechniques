int size = 50;  //TODO //this will change to 101
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 10; //TODO

double prob = 1;  //TODO




void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	for (int i = 0; i < TransitionMatrix.rows() - 6;i++) //limited by the size up to 6 spots. rows are where you are and columns are where you could be.
	{

		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;

		//TransitionMatrix(0, 1) = prob; this is an example of doing it manually


	}
	TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 1) = prob;
	TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 2) =prob;
	TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 3) =prob;
	TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 4) =prob;
	TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 5) =prob*2;

	TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 1) = prob;
	TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 2) = prob;
	TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 3) = prob;
	TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 4) = prob*3;
											  
	TransitionMatrix(TransitionMatrix.rows() -4, TransitionMatrix.rows() -4+ 1) = prob;
	TransitionMatrix(TransitionMatrix.rows() -4, TransitionMatrix.rows() -4+ 2) = prob;
	TransitionMatrix(TransitionMatrix.rows() -4, TransitionMatrix.rows() -4+ 3) = prob *4;

	TransitionMatrix(TransitionMatrix.rows() - 3, TransitionMatrix.rows() - 3 + 1) = prob;
	TransitionMatrix(TransitionMatrix.rows() - 3, TransitionMatrix.rows() - 3 + 2) = prob*5;

	TransitionMatrix(TransitionMatrix.rows() - 2, TransitionMatrix.rows() - 2 + 1) = prob*6;
	
	TransitionMatrix(TransitionMatrix.rows() - 1, TransitionMatrix.rows() - 1) = prob * 6; //END
	
	
	
	
	//TransitionMatrix(TransitionMatrix.rows() + 12, TransitionMatrix.rows() + 12 + 1) = 999;
	/*TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 2) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 3) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 4) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 5) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 6) = 999;*/



	std::cout << TransitionMatrix << std::endl;
	
	int x;
	std::cin >> x;
	exit(1);

	
}