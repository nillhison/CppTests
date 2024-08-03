#include <array>
#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>

#include <ctime>
#include <cstdlib>

static const unsigned int WEEK_SIZE = 7;
static const unsigned int WEEKS = 4;

class Week {
    public:
        Week() {
            for (auto i = 0; i < WEEK_SIZE; i++) {
                temperatures[i] = std::rand() % 100;
            }
            statistics.averege = (std::accumulate(temperatures.begin(), temperatures.end(), 0)) / WEEK_SIZE;
            statistics.lowest = *(std::min_element(temperatures.begin(), temperatures.end()));
            statistics.highest = *(std::max_element(temperatures.begin(), temperatures.end()));
        }
        void show_temperatures() {
            for (auto i = 0; i < WEEK_SIZE; i++) {
                std::cout << "Temperature at " << day[i] << ": " << temperatures[i] << std::endl;
            }
        }
        void show_statistics() {
            std::cout << "Averege temperature: " << statistics.averege << std::endl;
            std::cout << "Lowest temperature: " << statistics.lowest << std::endl;
            std::cout << "Highest temperature: " << statistics.highest << std::endl;
        }

    private:
        const std::array<std::string, WEEK_SIZE> day {
            "Sunday", "Monday", "Tuesday", "Wendsday", "Thursday", "Friday", "Saturday"
        };
        std::array<unsigned int, WEEK_SIZE> temperatures;
        struct {
            double averege;
            unsigned int lowest;
            unsigned int highest;
        } statistics;
};

int main() {

    std::srand((unsigned int)std::time(nullptr));

    std::array<Week*, WEEKS> weeks;

    std::for_each(
        weeks.begin(), weeks.end(), [](Week* &wk) {
            wk = new Week();
        }
    );

    std::for_each(
        weeks.begin(), weeks.end(), [&](Week* &wk) {
            std::cout << "====================================" << std::endl;
            std::cout << "## DATA FOR WEEK 0" << std::distance(weeks.begin(), &wk) + 1 << "  ##" << std::endl;
            wk->show_temperatures();
            std::cout << "----- Statistics for this week -----" << std::endl;
            wk->show_statistics();
            delete wk;
        }
    );

    std::cout << "====================================" << std::endl;

    return 0;
    
}