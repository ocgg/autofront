#ifndef COLORS_H
#define COLORS_H

#include <string_view>

namespace colors
{
constexpr std::string_view reset{"\x1b[0m"};

// RGB colors (48: background, 2: RGB format, 0;0;0 RGB values)
constexpr std::string_view black{"\x1b[48;2;0;0;0m \x1b[0m"};
constexpr std::string_view white{"\x1b[48;2;255;255;255m \x1b[0m"};
constexpr std::string_view green{"\x1b[48;2;0;255;0m \x1b[0m"};
constexpr std::string_view red{"\x1b[48;2;255;0;0m \x1b[0m"};
} // namespace colors

#endif
