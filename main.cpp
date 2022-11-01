void lambda() {
  auto l = []([[maybe_unused]] int value, int &value2) -> long {
    return ++value + value2++;
  };
  long (*fp)(int, int &) = l;
}

struct Lambda {
  using pointer_type = long (*)(int, int &);
  constexpr static auto FUNC([[maybe_unused]] int value, int &value2) -> long {
    return ++value + value2++;
  }
public:
  constexpr auto operator()([[maybe_unused]] int value, int &value2) const -> long {
    return ++value + value2++;
  }

  constexpr operator pointer_type() { return FUNC; }
};

void equivalent() {
  auto l = Lambda{};
  long (*fp)(int, int &) = l;
}
