#ifndef POTION_H
#define POTION_H

#include "Random.h"

class Potion {

	enum Type {
		health,
		strength,
		posion,
		max_types
	};

	enum Size {
		small,
		medium,
		large,
		max_sizes
	};

	Type m_type {};
	Size m_size {};


public:

	Potion(Type type, Size size)
		: m_type {type}
		, m_size {size}
	{}

	static Potion getRandomPotion() {
		return Potion(static_cast<Type>(Random::get(0, max_types - 1)), static_cast<Size>(Random::get(0, max_sizes - 1)));
	}

	Type getType() const {return m_type;}
	Size getSize() const {return m_size;}

	static std::string_view getTypeName(Type type) {
		static constexpr std::string_view names[] {"health", "strength", "posion"};
		return names[type];
	}

	static std::string_view getSizeName(Size size) {
		static constexpr std::string_view sizes[] {"small", "medium", "large"};
		return sizes[size];
	}

};

#endif
