#include<bits/stdc++.h>
#include <random>
#include <iostream>

#define MAX 1000000
std::random_device rseed;
std::mt19937 rng(rseed());
std::uniform_int_distribution<int> dist(-500000,500000);

int main(){
    std::string filename = "array.in";
    std::ofstream outfile;
    outfile.open(filename, std::ios::app | std::ios::in);
    for(int i = 0; i < MAX; i++)
        outfile << i << " " ;
    outfile << "\n";
    for(int i = MAX - 1; i >= 0; i--)
        outfile << i << " " ;
    outfile << "\n";
    for(int i = 0; i < 8; i++){
        for(int i = MAX - 1; i >= 0; i--)
            outfile << dist(rng) << " ";
        outfile << "\n";
    }
    outfile.close();
    return 0;
}