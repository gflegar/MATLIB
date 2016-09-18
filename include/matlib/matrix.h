#ifndef MATLIB_INCLUDE_MATLIB_MATRIX_H_
#define MATLIB_INCLUDE_MATLIB_MATRIX_H_


#include <vector>


namespace matlib {


template <typename E, template<typename EE> class Repr>
class Matrix {
public:
    explicit Matrix(int rows, int cols = 1) : data_(rows, cols) {}
    explicit Matrix(const Repr<E> &data) : data_(data) {}

    int rows() const { return data_.rows(); }
    int cols() const { return data_.cols(); }

    E& operator ()(int row, int col) { return data_.get(row, col); }
    E operator ()(int row, int col) const { return data_.get(row, col); }

private:
    Repr<E> data_;
};


template <typename E>
class ColumnMajorRepresentation {
public:
    ColumnMajorRepresentation(int rows, int cols)
            : rows_(rows), cols_(cols), data_(rows*cols, E(0)) {}

    int rows() const { return rows_; }
    int cols() const { return cols_; }
    E& get(int row, int col) { return data_[row + col*rows_]; }
    E get(int row, int col) const { return data_[row + col*rows_]; }

private:
    const int rows_;
    const int cols_;
    std::vector<E> data_;
};


}  // namespace matlib


#endif  // MATLIB_INCLUDE_MATLIB_MATRIX_H_

