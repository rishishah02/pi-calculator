#include <math.h>
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

double distanceFromOrigin(double x, double y){
    return sqrt((x*x)+(y*y));
}

double piCalc(int num_sims){
    int insideCircle = 0;
    double randX;
    double randY;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    for(int i = 0; i<num_sims; ++i){
        randX = distribution(generator);
        randY = distribution(generator);
        //cout << randX << ", " << randY << endl;
        if(distanceFromOrigin(randX, randY)<=1){
            insideCircle++;
        }
    }
    return 4.0 * (double) insideCircle/num_sims;
}

int main(){
    int sims;
    cout << "Enter Number of Simulations: ";
    cin >> sims;
    cout << endl;
    double pi = piCalc(sims);
    cout << "Approximation of Pi using Monte Carlo Simulation: " << pi << endl;
    return 0;
}