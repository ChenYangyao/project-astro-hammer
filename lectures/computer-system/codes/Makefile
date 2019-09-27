CXX = g++
CXXFLAGS = -Wall -std=c++11
CXXLDLIBS = -lmysys -lmymathCC

CFLAGS = -Wall -std=c99



proc_info.out : proc_info.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXLDLIBS)
multiprocess.out: multiprocess.c 
	cc $(CFLAGS) -o $@ $^
multithread.out: multithread.c 
	cc -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -pthread $(CFLAGS) -o $@ $^
multithread_omp.out : multithread_omp.c 
	cc -fopenmp $(CFLAGS) -o $@ $^
calc_twopt.out: calc_twopt.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXLDLIBS)
