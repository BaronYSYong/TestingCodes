/*!
 * @file counter.cpp
 * @brief compare gettimeofday, HPET and RDTSC
 * @date 2013/11/14
 * @author Yong Yoon Seong
 * 
 */

#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h> /// for uint64_t
#include <time.h>

/// RDTSC
/// assembly code to read the TSC
static inline uint64_t RDTSC()
{
  unsigned int hi, lo;
  __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
  return ((uint64_t)hi << 32) | lo;
}

template <int M> int counter(void)
{
    int t=0;
    /// Function for counter, initialize all timers
    struct timeval start, end;
    struct timespec HPET_begin, HPET_end;
    uint64_t RDTSC_begin = 0, RDTSC_end = 0;
    /// check the CPU speed by using command cat /var/log/dmesg | grep "MHz processor
    const long CPU_SPEED_IN_MHZ = 2399.955;
    
    /// Getting start time    
    clock_gettime(CLOCK_MONOTONIC, &HPET_begin);
    RDTSC_begin = RDTSC();   
    gettimeofday(&start, NULL);
    /// Sleep (or do something)
    sleep(M);
    /// Getting end time
    RDTSC_end = RDTSC();
    clock_gettime(CLOCK_MONOTONIC, &HPET_end);   
    gettimeofday(&end, NULL);
    
    /// Calculate the time elapsed and display all the result in microseconds       
    int Get_time = (end.tv_sec * 1000000 + end.tv_usec) 
    - (start.tv_sec * 1000000 + start.tv_usec);    
    int HPET = (HPET_end.tv_sec * 1000000 + HPET_end.tv_nsec/1000) 
    - (HPET_begin.tv_sec * 1000000 + HPET_begin.tv_nsec/1000);
    int RDTSC_time = (RDTSC_end - RDTSC_begin)/CPU_SPEED_IN_MHZ; 
    t = M * 1000000;
    
    std::cout<<"gettimeofday():\t"<<Get_time<<std::endl;
    std::cout<<"HPET:\t\t"<<HPET<<std::endl; 
    std::cout<<"RDTSC:\t\t"<<RDTSC_time<<std::endl;    

    return t;
}

int main(void)
{
    std::cout << "counter<3>() =\t" << counter<3>() << std::endl<< std::endl;

    std::cout << "counter<10>() =\t" << counter<10>() << std::endl<< std::endl;
    return 0;
}
