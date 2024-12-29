#include "helpers.h"

rule::rule(int a, int b) {
    this->first = a;
    this->second = b;
}

update::update(std::vector<int> vals) {
    this->pages = vals;
    this->middlePage = vals[vals.size() / 2];
};
