#include "matlib/matrix.h"


#include "gtest/gtest.h"


namespace matlib {


TEST(ColumnMajorRepresentationTest, Constructor)
{
    const int rows = 3;
    const int cols = 4;
    const ColumnMajorRepresentation<double> cmr(rows, cols);
    ASSERT_EQ(cmr.rows(), rows);
    ASSERT_EQ(cmr.cols(), cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(cmr.get(i, j), 0.0)
                << "element at (" << i << "," << j << ") not initialized";
        }
    }
}


TEST(ColumnMajorRepresentationTest, ElementAccess)
{
    const int rows = 3;
    const int cols = 4;
    ColumnMajorRepresentation<double> cmr(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cmr.get(i, j) = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(cmr.get(i, j), (i + 1) * (j + 1))
                << "error accessing element at position ("
                << i << "," << j << ")";
        }
    }

    const ColumnMajorRepresentation<double> &kcmr = cmr;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(kcmr.get(i, j), (i + 1) * (j + 1))
                << "error accessing constant element at position ("
                << i << "," << j << ")";
        }
    }
}


TEST(MatrixTest, Constructor)
{
    const int rows = 3;
    const int cols = 4;
    // default
    const Matrix<double, ColumnMajorRepresentation> mat(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(mat(i, j), 0.0)
                << "element at (" << i << "," << j << ") not initialized";
        }
    }
    // from existing representation
    ColumnMajorRepresentation<double> cmr(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cmr.get(i,j) = (i + 1) * (j + 1);
        }
    }
    const Matrix<double, ColumnMajorRepresentation> mat2(cmr);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(mat2(i, j), (i + 1) * (j + 1))
                << "element at (" << i << "," << j << ") not set";
        }
    }
}


TEST(MatrixTest, ElementAccess)
{
    const int rows = 3;
    const int cols = 4;
    Matrix<double, ColumnMajorRepresentation> mat(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat(i, j) = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(mat(i, j), (i + 1) * (j + 1))
                << "error accessing element at (" << i << "," << j << ")";
        }
    }
}


} // namespace matlib

