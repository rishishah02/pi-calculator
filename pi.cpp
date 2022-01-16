#include <math.h>
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

double piCalc(int num_sims){
    int insideCircle = 0;
    double x;
    double y;
    
    // Random Number Generator using this implementation of a uniform random distribution (runif): https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    
    // Create two random x and y coordinates in first quadrant
    // Check if distance is at most 1 (within the circle)
    // Count number of points inside quadrant and divide by total points (multiply by 4 to account for entire circle)
    for(int i = 0; i<num_sims; ++i){
        x = distribution(generator);
        y = distribution(generator);
        if(((x*x)+(y*y))<=1){
            insideCircle++;
        }
    }
    return 4.0 * (double) insideCircle/num_sims;
}

int main(){
    int sims;
    cout << "Enter Number of Simulations: "; // The larger the number of simulations, the closer the approximation will be to the exact value
    cin >> sims;
    cout << endl;
    double pi = piCalc(sims);
    cout << "Approximation of Pi using Monte Carlo Simulation: " << pi << endl;
    return 0;
}
