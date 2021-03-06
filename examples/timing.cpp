// Timing
// Source: ./examples/timing.cpp
#include <qpp.h>
using namespace qpp;

int main()
{
    std::cout << std::setprecision(8); // increase the default output precision

    // get the first codeword from Shor's [[9,1,3]] code
    ket c0 = codes.codeword(Codes::Type::NINE_QUBIT_SHOR, 0);

    Timer t; // declare and start a timer
    std::vector<idx> perm = randperm(9); // declare a random permutation
    ket c0perm = syspermute(c0, perm); // permute the system
    t.toc(); // stops the timer
    std::cout << "Permuting subsystems according to " << disp(perm, ", ");
    std::cout << "\nIt took " << t << " seconds to permute the subsytems.\n";

    t.tic(); // restart the timer
    std::cout << "Inverse permutation: ";
    std::cout << disp(invperm(perm), ", ") << std::endl;
    ket c0invperm = syspermute(c0perm, invperm(perm)); // permute again
    std::cout << "It took " << t.toc();
    std::cout << " seconds to un-permute the subsystems.\n";

    std::cout << "Norm difference: " << norm(c0invperm - c0) << std::endl;
}
