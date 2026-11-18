// ferrexd: the exchange daemon. In Phase 0 it only prints build info;
// gateway, matching shards and market data are wired in later phases.

#include <print>

#include "ferrex/version.hpp"

int main() {
    std::println("{}", ferrex::build_info());
    return 0;
}
