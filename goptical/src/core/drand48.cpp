#include <random>

static std::default_random_engine generator;
static std::uniform_real_distribution<double> distribution (0.0, 1.0);

double
drand48 ()
{
	return distribution (generator);
}