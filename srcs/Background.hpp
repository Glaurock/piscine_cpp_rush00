#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "AGameEntity.hpp"

class Background : public AGameEntity
{

  private:
    Background();

    Background(Background const &src);
    Background &operator=(Background const &src);

  public:
    virtual ~Background();
};

#endif // Background_HPP