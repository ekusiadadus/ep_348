void lambda() {
  auto l = []([[maybe_unused]], int value, int &value2) {};
  l();
}

struct Lambda {
  constexpr auto operator()([[maybe_unused]], int value, int &value2) const {}
};

void equivalent() {
  auot l = Lambda{};
  l(42);
}