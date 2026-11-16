// ferrexd: the exchange daemon. In Phase 0 it only prints build info;
// gateway, matching shards and market data are wired in later phases.

#include <cstdio>

#include "ferrex/version.hpp"

int main() {
    const auto info = ferrex::build_info();
    std::printf("%.*s\n", static_cast<int>(info.size()), info.data());
    return 0;
}
