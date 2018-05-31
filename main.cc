#include "coprime_gen.h"
#include "nocopy_integer.h"
#include "prime_gen.h"
#include "sim_rns.h"
#include "two_phase.h"
#include <array>
#include <linbox/integer.h>
#include <ostream>

using namespace std;
using namespace LinBox;
int main()
{
    const size_t phase1_modulis_size = 10;
    const uint_fast8_t phase1_modulis_expo_bit_length = 10;

    const size_t phase2_modulis_basis_size = 1000;
    const size_t phase2_modulis_bit_length = 26;

    TwoPhaseAlgo<NoCopyInteger, phase1_modulis_size, phase1_modulis_expo_bit_length, NoCopyInteger, phase2_modulis_basis_size, phase2_modulis_bit_length> algo;
    NoCopyInteger a;
    NoCopyInteger b;
    NoCopyInteger d;
    a.randomize(1025);
    b.randomize(1025);
    algo.mult(d, a, b);

    cout << a << endl;
    cout << b << endl;
    // NoCopyInteger d;
    // algo.mult(d, a, b);

    // PrimeGenExact<NoCopyInteger, basis_size, 26> basis;
    // cout << basis << endl;
    // vector<NoCopyInteger*> inputs;
    // inputs.push_back(NoCopyInteger::newRandom(4096));
    // inputs.push_back(NoCopyInteger::newRandom(4096));
    // inputs.push_back(NoCopyInteger::newRandom(4096));
    // cout << SIM_RNS::RNS<NoCopyInteger, NoCopyInteger, NoCopyInteger, basis_size>::naive_reduce(inputs, basis) << endl;

    // inputs.erase(inputs.begin());
    // MargeGenExact<NoCopyInteger, 1, 26> a;

    // PrimeGen<NoCopyInteger, 10, 10> a([](size_t i) {
    //     cout << i << endl;
    //     return new NoCopyInteger(i);
    // });
    // cout
    // << a << endl
    // << a.product << endl;
}
