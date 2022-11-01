void lambda() {
  auto l = []([[maybe_unused]] int value, int &value2) -> long {
    return ++value + value2++;
  };
  int i = 13;
  l(42, i);
}

struct Lambda {
  constexpr auto operator()([[maybe_unused]] int value, int &value2) const -> long {
    return ++value + value2++;
  }
};

void equivalent() {
  auto l = Lambda{};
  int i = 13;
  l(42, i);
}
