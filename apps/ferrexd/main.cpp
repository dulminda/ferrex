// ferrexd: the exchange daemon. In Phase 0 it only prints build info;
// gateway, matching shards and market data are wired in later phases.

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <print>

#include "ferrex/version.hpp"

int main() {
    // Nothing may escape main(): an uncaught exception calls std::terminate,
    // skipping destructors. The handlers use std::fputs because it never throws.
    try {
        std::println("{}", ferrex::build_info());
        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        std::fputs("ferrexd: fatal: ", stderr);
        std::fputs(e.what(), stderr);
        std::fputs("\n", stderr);
    } catch (...) {
        std::fputs("ferrexd: fatal: unknown exception\n", stderr);
    }
    return EXIT_FAILURE;
}
