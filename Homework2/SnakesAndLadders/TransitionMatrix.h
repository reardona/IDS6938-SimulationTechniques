int size = 10;  //TODO //this will change to 101
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 10; //TODO

double prob = 1.0 / 6.0;  //TODO




void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	for (int i = 0; i < TransitionMatrix.rows()-6;i++)
	{

			TransitionMatrix(i, i + 1) = prob;
			TransitionMatrix(i, i + 2) = prob;
			TransitionMatrix(i, i + 3) = prob;
			TransitionMatrix(i, i + 4) = prob;
			TransitionMatrix(i, i + 5) = prob;
			TransitionMatrix(i, i + 6) = prob;

		//TransitionMatrix(0, 1) = prob; this is an example of doing it manually


	}

	//TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 1) = 999;
	//TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 2) = 999;
	//TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 3) = 999;
	//TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 4) = 999;
	//TransitionMatrix(TransitionMatrix.rows()-6, TransitionMatrix.rows()-6 + 5) = 999;
	//TransitionMatrix(TransitionMatrix.rows()-7, TransitionMatrix.rows()-7 + 6) = 999;
	
	/*TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 1) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 2) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 3) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 4) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 5) = 999;
	TransitionMatrix(TransitionMatrix.rows() - 13, TransitionMatrix.rows() - 13 + 6) = 999;*/



	std::cout << TransitionMatrix << std::endl;
	exit(1);
	
}