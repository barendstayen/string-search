#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

#define num_threads 4
#define filename "C:\\Users\\baren\\Documents\\School\\Canada\\359\\string search\\input.txt"

struct threat_result {
    size_t count = 0;
};


int main() {
    // load file in to string
    std::ifstream in(filename);

    if (!in) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(in)),
                      std::istreambuf_iterator<char>());


    // pattern list
    std::vector<std::string> patterns = {"test", "bee"};

    // split data set
    // get max length for each pattern
    size_t max_pattern_len = 0;
    for (auto& p : patterns)
        max_pattern_len = std::max(max_pattern_len, p.size());

    // split text in chunks for each thread
    size_t text_size = text.size();
    size_t chunk_size = text_size / num_threads;

    // temp storage for each thread result
    std::vector<std::thread> threads;
    std::vector<threat_result> count(num_threads);

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // launch threads
    for (int i = 0; i < num_threads; i++) {
        size_t start = i * chunk_size;
        size_t end = (i == num_threads - 1) ? text_size : start + chunk_size;

        // add overlap to start
        if (i > 0) {
            if (start >= max_pattern_len - 1) {
                start -= (max_pattern_len - 1);
            } 
            else {
                start = 0;
            }
        }

        threads.emplace_back([&, i, start, end]() {
            size_t local_count = 0;

            for (const auto& patern : patterns) {
                size_t pos = text.find(patern, start);
                while (pos != std::string::npos && pos < end) {
                    local_count++;
                    pos = text.find(patern, pos + 1);
                }
            }

            count[i].count = local_count;

        });
    }

    // wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    size_t total_count = 0;
    for (const auto& res : count) {
        total_count += res.count;
    }

    // stop timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;


    // print results
    std::cout << "Total occurrences: " << total_count << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}

