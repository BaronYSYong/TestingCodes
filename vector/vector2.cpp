/*!
 * @file vector2.cpp
 * @brief try matrix multiply in C++
 * @date 2013/11/18
 * @author Yong Yoon Seong
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>

/// multiply all elements of an array by a scalar value
/// return is true
/// use normal C array access using mat[i]
bool stlMatrixMultiply(const std::vector<double> &mat, const int m1)
{
    std::cout << "Matrix Multiply (use normal C array access using mat[i]) is:" << std::endl;

    for (int i = 0; i < mat.size(); i++)
        std::cout << mat[i] * m1 << " ";
    std::cout << std::endl << std::endl;

    return true;
}

/// multiply all elements of an array by a scalar value
/// return is true
/// loop using stl iterators
bool stlMatrixMultiply2(const std::vector<double> &mat, const int m1)
{
    std::cout << "Matrix Multiply2 (loop using stl iterators) is:" << std::endl;

    for (std::vector<double>::const_iterator it = mat.begin(); it != mat.end(); ++it)
        std::cout << *it * m1 << " ";
    std::cout << std::endl << std::endl;

    return true;
}

/// multiply all elements of a matrix by a vector
/// assume matrices are of size 2x2, 3x3, 4x4, ...
/// check that the provided vector size is correct
/// return false if the matrix size or vector size is incorrect
bool stlMatrixVectorMultiply(const std::vector<double> &mat, const std::vector<double> &vec,
                             std::vector<double> &res)
{
    double intpart;
    /// modf(x) function breaks argument into integral and fractional part of x, and return fraction part of x
    double square = modf(sqrt(mat.size()),&intpart);

    /// check if the matrix size is square or not, if the square==0, then it is square size
    /// check if the size of matrix is equal to size of vector or not
    if(square == 0 && (sqrt(mat.size())) == vec.size())
    {
        int j = 0;
        int k = 0;
        for (int i = 0; i < mat.size(); i++) /// 1 row of matrix
        {
            res[k] += mat[i] * vec[j];
            j++;
            if (j > ((vec.size() - 1))) /// split the matrix to next row
            {
                j = 0;
                k++;
            }
        }
        return true;
    }
    else
    {
        std::cerr << "The input matrix is invalid, please key in again." << std::endl;
        return false;
    }
}


/// 2D vector of the above
bool stlMatrixVectorMultiply2(const std::vector< std::vector<double> > &mat,
                              const std::vector<double> &vec,
                              std::vector<double> &res)
{
    int row_mat = mat.size();
    int column_mat = mat[0].size();

    /// check if the column size of matrix is equal to size of vector or not
    if(column_mat == vec.size())
    {
        for (int i = 0; i < row_mat; i++)
            for (int j = 0; j < column_mat; j++)
                res[i] += mat[i][j] * vec[j];
        return true;
    }
    else
    {
        std::cerr << "The input matrix is invalid, please key in again." << std::endl;
        return false;
    }
}

/// multiply two matrices
bool stlMatrixMatrixMultiply(const std::vector< std::vector<double> > mat1,
                             const std::vector< std::vector<double> > mat2,
                             std::vector< std::vector<double> > &res)
{
    int row_mat1 = mat1.size();
    int column_mat1 = mat1[0].size();
    int row_mat2 = mat2.size();
    int column_mat2 = mat2[0].size();

    /// check if the column size of mat1 match with row size of mat 2 or not
    if (column_mat1 == row_mat2)
    {
        for (int i = 0; i < row_mat1; i++)
            for (int j = 0; j < column_mat2; j++)
                for (int k = 0; k < column_mat1; k++) /// Remark: column_mat1 == row_mat2
                    res[i][j] += mat1[i][k] * mat2[k][j];
        return true;
    }
    else
    {
        std::cerr << "The input matrix is invalid, please key in again." << std::endl;
        return false;
    }
}


int main (int argv,char** argc)
{
    std::vector<double> mat1(25,0);
    std::vector<double> mat2(5,0);
    std::vector<double> mat3(mat2.size(),0);
    std::vector< std::vector<double> > mat4(6, std::vector<double>(5,0));
    std::vector<double> mat5(mat4.size(),0);
    std::vector< std::vector<double> > mat6(5, std::vector<double>(6,0));
    std::vector< std::vector<double> > mat7(mat4.size(), std::vector<double>(mat6[0].size(),0));
    int k = 0;
    int l = 0;

    for (int i = 0; i < mat1.size(); i++)
        mat1[i] = i + 1;

    for (int i = 0; i < mat2.size(); i++)
        mat2[i] = i + 1;

    for (int i = 0; i < mat4.size(); i++)
        for (int j = 0; j < mat4[0].size(); j++)
            mat4[i][j] = ++k;

    for (int i = 0; i < mat6.size(); i++)
        for (int j = 0; j < mat6[0].size(); j++)
            mat6[i][j] = ++l;

    ///call the function of stlMatrixMultiply (use normal C array access using mat [i])
    stlMatrixMultiply (mat1, 2);

    ///call the function of stlMatrixMultiply2 (loop using stl iterators)
    stlMatrixMultiply2 (mat2, 3);

    ///call the function of stlMatrixVectorMultiply (split 1 dimension matrix)
    bool c = stlMatrixVectorMultiply (mat1, mat2, mat3);

    if (c == 1)
    {
        std::cout << "Matrix Vector Multiply (1 dimension) is:" << std::endl;
        for (int i = 0; i < mat3.size(); i++)
            std::cout << mat3[i] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /// call the function of stlMatrixVectorMultiply2 (2D Matrix x 1D Vector)
    bool d = stlMatrixVectorMultiply2 (mat4, mat2, mat5);

    if (d == 1)
    {
        std::cout << "Matrix Vector Multiply (2D Matrix x 1D Vector) is:" << std::endl;
        for (int i = 0; i < mat5.size(); i++)
            std::cout << mat5[i] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /// call the function of stlMatrixMatrixMultiply (2D Matrix x 2D Matrix)
    bool e = stlMatrixMatrixMultiply (mat4, mat6, mat7);

    if (e == 1)
    {
        std::cout << "stl Matrix Matrix Multiply (2D Matrix x 2D Matrix) is:" << std::endl;
        for (int i = 0; i < mat7.size(); i++)
        {
            for (int j = 0; j < mat7[0].size(); j++)
                std::cout << mat7[i][j] << "\t";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
