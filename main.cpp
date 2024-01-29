#include "Matrix.h"

int main() {
    try {
        Matrix matrix;

       
        std::cout << "Enter the size and elements of the symmetric matrix:\n";
        std::cin >> matrix;


        if (!matrix.isSymmetric()) {
            std::cerr << "Error: Entered matrix is not symmetric.\n";
            return 1;
        }


        std::cout << matrix << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

