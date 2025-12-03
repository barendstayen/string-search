#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

#define filename "data_large.txt"

size_t num_threads = 1;

struct threat_result {
    size_t count = 0;
};

size_t search_pattern_mt(const std::string& text,
                         const std::string& pattern,
                         size_t num_threads)
{
    size_t text_size = text.size();
    size_t pattern_len = pattern.size();
    size_t chunk_size = text_size / num_threads;

    std::vector<std::thread> threads;
    std::vector<threat_result> results(num_threads);

    for (size_t i = 0; i < num_threads; i++) {
        // split data set in chunks
        size_t start = i * chunk_size;
        size_t end = (i == num_threads -1) ? text_size : start + chunk_size;

        // as overlap at the start to prevent border issues exept for first chunk
        if (i > 0) {
            if (start >= pattern_len -1)
                start -= (pattern_len -1);
            else
                start = 0;
        }

        // start of chunk whithout overlap
        size_t real_start = i * chunk_size; 

        // launch thread
        threads.emplace_back([&, i, start, end, real_start]() {
            size_t local_count = 0;
            size_t pos = text.find(pattern, start);

            while (pos != std::string::npos && pos < end) {
                // only count if within real chunk (without overlap)
                if (pos >= real_start)
                    local_count++;
                pos = text.find(pattern, pos + 1);
            }

            // store result
            results[i].count = local_count;
        });
    }

    // wait for all threads to finish
    for(auto& t : threads) {
        t.join();
    }

    // sum results
    size_t total_count = 0;
    for (const auto& res : results) {
        total_count += res.count;
    }

    return total_count;
}

int main() {
    // load input file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    
    std::vector<std::string> patterns = {
        "parallel",
        "pattern",
        "search",
        "algorithm",
        "text",
        "cpu",
        "data",
        "string",
        "partition",
        "worker",
        "overlap",
        "boundary"
    };

    for (const auto& pattern : patterns) {
        // start timer
        auto start_time = std::chrono::high_resolution_clock::now();

        // count pattern occurrences
        size_t count = search_pattern_mt(text, pattern, num_threads);

        // stop timer
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end_time - start_time;

        // output results
        std::cout << "Pattern: \"" << pattern << "\" "
                  << "Count: " << count << " "
                  << "Time: " << duration.count() << " ms"
                  << std::endl;
    }

    return 0;

}
