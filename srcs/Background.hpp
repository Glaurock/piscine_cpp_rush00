#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "AGameEntity.hpp"

class Background : public AGameEntity
{
  private:
    Background(Background const &src);
    Background &operator=(Background const &src);
    Background();

  public:
    Background(int, int, int, char);
    virtual ~Background();

    static int getNextFreeSpace(Background ** backgrounds);    
    void move(void);
};

#endif // Background_HPP