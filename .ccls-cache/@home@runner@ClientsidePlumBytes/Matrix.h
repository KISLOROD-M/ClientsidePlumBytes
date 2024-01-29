#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix();
    explicit Matrix(const std::vector<std::vector<int>>& matrix);

    int size() const;
    int get(int i, int j) const;

  
    bool isSymmetric() const;


    std::vector<int> calculateVector() const;


    friend std::istream& operator>>(std::istream& input, Matrix& matrix);


    friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
};

#endif 
