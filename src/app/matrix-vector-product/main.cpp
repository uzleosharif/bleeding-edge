

#include "armadillo"

auto main() -> int {
  const arma::Mat<double> A = arma::randu(4, 4);
  std::cout << "A:\n" << A << "\n";

  const arma::vec x = arma::randu(4, 1);
  std::cout << "x:\n" << x << "\n";

  auto b = A * x;
  std::cout << "b:\n" << b << "\n";

  return 0;
}