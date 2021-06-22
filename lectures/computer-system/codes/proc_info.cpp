#include <mysys.h>
#include <mysys_ipc.h>
#include <mystd.h>

using namespace MYSTD;
using namespace MYSYS;


int main(int argc, char const *argv[]){
    cout << "PID: " << getpid() << endl;

    /* create and open a pipe */
    auto pipe = Pipe::open();

    /* create and open a message queue */
    MQueue mq( "/message_queue", "wr" );
    mq.set_own();

    /* open a file */
    FILE *f = fopen("ordinary_file", "wr");
    
    string buff;
    cin >> buff;

    return 0;
}

