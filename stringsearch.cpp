#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

#define filename "input.txt"

size_t num_threads = 0;

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

// int main() {
//     // load file in to string
//     std::ifstream in(filename);

//     if (!in) {
//         std::cerr << "Unable to open file " << filename << std::endl;
//         return 1;
//     }

//     std::string text((std::istreambuf_iterator<char>(in)),
//                       std::istreambuf_iterator<char>());


//     // pattern list
//     std::vector<std::string> patterns = {"test", "bee"};

//     // split data set
//     // get max length for each pattern
//     size_t max_pattern_len = 0;
//     for (auto& p : patterns)
//         max_pattern_len = std::max(max_pattern_len, p.size());

//     // split text in chunks for each thread
//     size_t text_size = text.size();
//     size_t chunk_size = text_size / num_threads;

//     // temp storage for each thread result
//     std::vector<std::thread> threads;
//     std::vector<threat_result> count(num_threads);

//     // start timer
//     auto start_time = std::chrono::high_resolution_clock::now();

//     // launch threads
//     for (int i = 0; i < num_threads; i++) {
//         size_t start = i * chunk_size;
//         size_t end = (i == num_threads - 1) ? text_size : start + chunk_size;

//         // add overlap to start
//         if (i > 0) {
//             if (start >= max_pattern_len - 1) {
//                 start -= (max_pattern_len - 1);
//             } 
//             else {
//                 start = 0;
//             }
//         }

//         threads.emplace_back([&, i, start, end]() {
//             size_t local_count = 0;

//             for (const auto& patern : patterns) {
//                 size_t pos = text.find(patern, start);
//                 while (pos != std::string::npos && pos < end) {
//                     local_count++;
//                     pos = text.find(patern, pos + 1);
//                 }
//             }

//             count[i].count = local_count;

//         });
//     }

//     // wait for all threads to finish
//     for (auto& t : threads) {
//         t.join();
//     }

//     size_t total_count = 0;
//     for (const auto& res : count) {
//         total_count += res.count;
//     }

//     // stop timer
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> elapsed = end_time - start_time;


//     // print results
//     std::cout << "Total occurrences: " << total_count << std::endl;
//     std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

//     return 0;
// }

