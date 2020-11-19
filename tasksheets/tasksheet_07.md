# Solutions for Tasksheet 7
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_07/pdf/tasksheet_07.pdf) for problem set.

All the tasks in this tasksheet were executed by running a computer program that executes all of the operations required in each task. Each task will have a screenshot of the output that was printed to the console. The source code for this program can be found [here](../test/task7/task7.cpp). To verify that the system of equations was solved correctly, function named

    LinearAlgebra::verifySolution(const LinearAlgebra::Matrix & A, const Linear::Algebra & x, const LinearAlgebra::Matrix & b)
  
is called to double check the solution. The statement "System solved correctly" indicates that this function produced a positive result. The source code for the matrix operations can be found [here](../src/linsolver.cpp)

<img src="https://render.githubusercontent.com/render/math?math=f(x) = e^{-x^2}sin(4x^2 - 1.0) %2B 0.051">.

To facilitate the matrix equation solving, the following namespace was added to the math4610lib.a archive. 

    namespace LinearAlgebra
    {
    enum MatrixType
    {
        UPPR,
        LWR,
        DIAG,
        SQR
    };

    class Matrix
    {
        private:
            const size_t NUM_ROWS;
            const size_t NUM_COLS;
            Matrix reduceRowEchelonPrivate() const;
            Matrix reduceRowEchelon(LinearAlgebra::Matrix & b) const;
            Matrix backSubstitution(const LinearAlgebra::Matrix & b) const;
            Matrix forwardSubstitution(const LinearAlgebra::Matrix & b) const;
        public:
            double ** data;
            Matrix(const int & numRows, const int & numCols, const double & value, MatrixType type);
            Matrix(const int & numRows, const int & numCols, MatrixType type);
            Matrix(const int & numRows, const int & numCols, const double & value);
            size_t getNumRows() const;
            size_t getNumCols() const;
            Matrix solve(LinearAlgebra::Matrix & b) const;
            Matrix solveLWR(LinearAlgebra::Matrix & b) const;
            Matrix duplicate() const;
            Matrix transpose() const;
            void reduceRowEchelon();
            void print(int minRow, int maxRow, int minCol, int maxCol) const;
            void print() const;
            Matrix operator+(const LinearAlgebra::Matrix & operand) const;
            Matrix operator+=(const LinearAlgebra::Matrix & operand) const;
            Matrix operator-(const LinearAlgebra::Matrix & operand) const;
            Matrix operator-=(const LinearAlgebra::Matrix & operand) const;
            Matrix operator*(const double & operand) const;
    };

    bool verifySolution(const LinearAlgebra::Matrix & A, const LinearAlgebra::Matrix & x, const LinearAlgebra::Matrix & b);
    }

<hr>

**Task 1**

The following code block generated the output seen in the image below. This code is taken directly from the program mentioned at the beginning of this tasksheet. The solve operation consists of row reduction and back substitution. The type of matrix is determined by the last argument in the Matrix constructor. 

    // Task 1
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 1" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    size_t squareSize = 10;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::UPPR);
    std::cout << "A" << std::endl;
    A.print();
    std::cout << std::endl;
    LinearAlgebra::Matrix b(squareSize, 1, 1.0);
    std::cout << "b" << std::endl;
    b.print();

    LinearAlgebra::Matrix x = A.solve(b);
    std::cout << std::endl;
    std::cout << "x" << std::endl;
    x.print();
    LinearAlgebra::verifySolution(A, x, b);

![](../images/tasksheet7_task1.JPG)

<hr>

**Task 2**

![](../images/tasksheet7_task2.JPG)

<hr>

**Task 3**

![](../images/tasksheet7_task3.JPG)

<hr>

**Task 4**

![](../images/tasksheet7_task4.JPG)

<hr>

**Task 5**

![](../images/tasksheet7_task5.JPG)

<hr>

**Task 6**


