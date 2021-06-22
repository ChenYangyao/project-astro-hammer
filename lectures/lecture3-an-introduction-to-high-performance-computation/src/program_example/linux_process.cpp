#include <mysys.h>
#include <mysys_ipc.h>
using namespace MYSTD;
using namespace MYSYS;


int subproc( int b, int e ){
    int ret = 0;
    for(int i=b; i<e; ++i) ret += i;
    return ret;
}

int main(int argc, char const *argv[])
{
    const int Ntask = 10000, Nsubproc = 8;
    int Ntask_each = Ntask / Nsubproc;
    
    // create processes, assign works
    MQueue mq_scatter("/scatter", "rw"),  mq_reduce("/reduce", "rw");
    pid_t pid;
    for(int i=0; i<Nsubproc; ++i){
        if( (pid = fork()) == 0 ) break;
        mq_scatter.write( i );
    }
    
    // finish and send back result
    int rank, ret;
    if( pid == 0 ){
        mq_scatter.read( rank );
        ret = subproc( Ntask_each*rank, Ntask_each*(rank+1) );
        mq_reduce.write( ret );
    }else{
        mq_scatter.set_own(); mq_reduce.set_own();
        int total = 0;
        for(int i=0; i<Nsubproc; ++i){
            mq_reduce.read(ret);
            total += ret;
        }
        cout << "sum to " << Ntask << " equals " << total << endl;
    }

    return 0;
}
