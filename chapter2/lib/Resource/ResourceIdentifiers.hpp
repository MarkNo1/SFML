#ifndef BOOK_RESOURCEIDENTIFIERS_HPP
#define BOOK_RESOURCEIDENTIFIERS_HPP

// Forward declaration of SFML classes
namespace sf {
class Texture;
class Font;
}

namespace Textures {
enum class ID : int {
		UFO
};
}

namespace Fonts {
enum class ID : int {
	Main,
};
}

// Forward declaration and a few type definitions
template<typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_HPP
