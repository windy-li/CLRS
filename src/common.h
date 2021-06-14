#ifndef CLRS_SRC_COMMON_H_
#define CLRS_SRC_COMMON_H_

#include <random>

class Random {
 public:
  static int Get(int left, int right) {
    std::uniform_int_distribution<int> distribution(left, right - 1);
    std::default_random_engine engine = GetEngine();
    return distribution(engine);
  }

  static double Get() {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::default_random_engine engine = GetEngine();
    return distribution(engine);
  }

  static std::vector<int> Vector() {
    int n = 1000;
    int low = 0;
    int high = 100;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
      vec[i] = Get(low, high);
    }
    return vec;
  }

 private:
  static std::default_random_engine GetEngine() {
    std::random_device device;
    std::default_random_engine engine(device());
    return engine;
  }
};

class Demo {
 public:
  explicit Demo(std::string& username) : username_(std::string(username)){}

  std::string GetUsername() {
    return username_;
  }

 private:
  std::string username_;
};

#endif  // CLRS_SRC_COMMON_H_
