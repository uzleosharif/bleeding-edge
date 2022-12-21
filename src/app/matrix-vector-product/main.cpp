

#include "armadillo"

auto main() -> int {
  const arma::Mat<double> a_mat = arma::randu(4, 4);
  std::cout << "A:\n" << a_mat << "\n";

  return 0;
}