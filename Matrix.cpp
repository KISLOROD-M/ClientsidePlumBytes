#include "Matrix.h"

Matrix::Matrix() : data() {}

Matrix::Matrix(const std::vector<std::vector<int>>& matrix) : data(matrix) {}

int Matrix::size() const {
    return data.size();
}

int Matrix::get(int i, int j) const {
    return data[i][j];
}

bool Matrix::isSymmetric() const {
    int n = size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (data[i][j] != data[j][i]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> Matrix::calculateVector() const {
    int n = size();
    std::vector<int> result;

    for (int i = 0; i < n; ++i) {
        int s1 = 0, s2 = 0;

     
        for (int j = 0; j < n; ++j) {
            if (data[i][j] != 0) {
                s1 += data[i][j];
            }

            if (data[i][j] % 10 != 0) {
                s2 += data[i][j];
            }
        }

   
        result.push_back(s1 - s2);
    }

    return result;
}

std::istream& operator>>(std::istream& input, Matrix& matrix) {
    int n;
    input >> n;

    matrix.data.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> matrix.data[i][j];
        }
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix& matrix) {
    int n = matrix.size();

    output << "Symmetric Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output << matrix.get(i, j) << ' ';
        }
        output << '\n';
    }

    output << "\nVector {bi}:\n";
    std::vector<int> result = matrix.calculateVector();
    for (int i = 0; i < n; ++i) {
        output << result[i] << ' ';
    }

    return output;
}
