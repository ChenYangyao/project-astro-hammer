#include <thread>
#include <future>
#include <mystd.h>
using namespace MYSTD;

int subthread( int b, int e ){
    int ret = 0;
    for(int i=b; i<e; ++i) ret += i;
    return ret;
}

int main(int argc, char const *argv[])
{
    const int Ntask = 10000, Nsubthread = 8;

    // create threads, assign works
    vector<std::future<int> > rets;
    int Ntask_each = Ntask / Nsubthread;
    for(int i=0; i<Nsubthread; ++i)
        rets.emplace_back( 
            std::async( 
                subthread, Ntask_each*i, Ntask_each*(i+1) ));

    // join threads, reduce result
    int total = 0;
    for(auto &ret: rets) total += ret.get();
    
    cout << "sum to " << Ntask << " equals " << total << endl;

    return 0;
}


