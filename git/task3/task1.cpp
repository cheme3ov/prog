/*
 * task1.cpp
 *
 *  Created on: 27 февр. 2018 г.
 *      Author: artemchemezov
 */
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
//#include <malloc.h>

using namespace std;

struct ret{
    int don;
    int rec;
};

void add(vector<int> v, mutex* mut, int rec, int d){
    lock_guard<mutex> guard(mut[rec]);
     v[rec] += d;
    
}


void func(vector<int> v, mutex* mut, int don, int rec, int d){
                 cerr << "ZZZZZZ" << endl;
                lock_guard<mutex> guard(mut[don]);
              
                    if (v[don] - d >= 0) {
                        v[don] -= d;
                        //r.don = don;
                       
                        add(v, mut, rec, d);
                        //r.rec = rec;
                }
}



int main(int argc, char* argv[]){
    if (argc < 3) {
        cerr << "Need more arg" << endl;
        return 1;
    }

    int N = stoi(argv[1]);

    if(N < 1){
        cerr << "Invalid number of threads\n";
        return 1;
    }


    int m = stoi(argv[2]);

    vector<thread> threads;
    threads.reserve(m);


    std::vector<int> v;
    mutex* mut = new mutex[m];
    v.reserve(N);

    for (int i = 0; i < N; ++i) {v[i] = 100;}

        for (int i = 0; i < N; ++i){cerr << v[i] << endl;}
            cerr << "-------------------" << endl;
 
    for (int i = 0; i < m; ++i){
        int d = rand() % 100;
        int num = rand() % N;
        int num2 = rand() % N;
        ret r;

        threads[i] = thread(func, v, mut, num, num2, d);
    }

    
    for(int i = 0; i < m; ++i)
        threads[i].join();

    for (int i = 0; i < N; ++i){cerr << v[i] << endl;}


    
    return 0;
}



    