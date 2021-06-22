#include <omp.h>
#include <mystd.h>
using namespace MYSTD;

int main(int argc, char const *argv[]){
    const int Ntask = 10000;

    // create threads, assign works, reduce result
    int total = 0;
    #pragma omp parallel for reduction(+:total)
    for(int i=0; i<Ntask; ++i){
        total += i;
    }
        

    cout << "sum to " << Ntask << " equals " << total << endl;
    
    return 0;
}
