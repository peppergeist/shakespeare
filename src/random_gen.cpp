#include "random_gen.h"

int get_random_number(int min, int max)
{
    std::default_random_engine generator;
    std::chrono::milliseconds ms =
    std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch());
    generator.seed(ms.count());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
