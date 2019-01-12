#ifndef SHIP_HPP
#define SHIP_HPP

#include "AGameEntity.hpp"
#include "Missile.hpp"
#include "ft_retro.hpp"

class Ship : public AGameEntity {

private:
  Ship();
  Ship(Ship const &src);
  Ship &operator=(Ship const &src);

public:
  Ship(char *arena);
  virtual ~Ship();

  bool move(char *arena);
  Missile *fireMissile(void);
};

#endif // SHIP_HPP