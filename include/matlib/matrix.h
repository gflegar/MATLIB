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
    E& operator ()(int element) { return data_.get(element); }
    E operator ()(int element) const { return data_.get(element); }

private:
    Repr<E> data_;
};


template <typename E>
class ColumnMajorRepr {
public:
    ColumnMajorRepr(int rows, int cols)
            : rows_(rows), cols_(cols), data_(rows, cols) {}

    int rows() const { return rows_; }
    int cols() const { return cols_; }
    E& get(int row, int col) { return data_[row + col*rows_]; }
    E get(int row, int col) const { return data_[row + col*rows_]; }
    E& get(int element) { return data_[element]; }
    E get(int element) const { return data_[element]; }

private:
    int rows_;
    int cols_;
    std::vector<E> data_;
};


}  // matlib


#endif  // MATLIB_INCLUDE_MATLIB_MATRIX_H_

