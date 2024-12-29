#include <vector>

class rule {
  public:
    rule(int a, int b);

    int first;
    int second;
};

class update {
  public:
    update(std::vector<int> vals);

    int middlePage;
    std::vector<int> pages;
};