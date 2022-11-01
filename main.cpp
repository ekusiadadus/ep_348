void lambda() {
  auto l = [](auto value, int &value2) -> long {
    return ++value + value2++;
  };
  long (*fp)(int, int &) = l;
}

class Lambda {
  template<typename T>
  using pointer_type = long (*)(T, int &);

  template<typename T>
  constexpr static auto FUNC(T value, int &value2) -> long {
    return ++value + value2++;
  }

public:
  template<typename T>
  constexpr auto operator()(T value, int &value2) const -> long {
    return ++value + value2++;
  }

  template<typename T>
  constexpr operator pointer_type<T>() const {
    return FUNC;
  }
};