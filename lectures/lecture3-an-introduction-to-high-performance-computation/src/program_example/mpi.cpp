#include <mystd.h>
#include <mympe.h>
using namespace MYSTD;
using namespace MYMPE;
    
int subproc( int b, int e ){
    int ret = 0;
    for(int i=b; i<e; ++i) ret += i;
    return ret;
}

int main(int argc, char const *argv[])
{
    const int Ntask = 10000;
    
    // assign works
    Env env; Comm comm;
    int Ntask_each = Ntask / comm.size(), rank = comm.rank();
    int ret = subproc( Ntask_each*rank, Ntask_each*(rank+1) );

    // reduce result
    int total;
    comm.reduce( ret, total, MPI_SUM, 0 );

    if( comm.rank() == 0 )
        cout << "sum to " << Ntask << " equals " << total << endl;

    return 0;
}
