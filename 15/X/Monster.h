#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>

class Monster {
public:
	enum Type {
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		maxMonsterTypes,
	};

	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints);
	constexpr std::string_view getTypeString() const;
	void print() const;

private:
	Type m_type {};
	std::string m_name {"???"};
	std::string m_roar {"???"};
	int m_hitPoints {};
};

#endif
