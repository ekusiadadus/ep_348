void lambda() {
  auto l = [](int value){};
  l();
}

struct Lambda {
  constexpr auto operator()(int value) const {}
};

void equivalent() {
 auot l = Lambda{};
 l(42);
}