#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "AGameEntity.hpp"

class Background : public AGameEntity
{
  private:
    Background(Background const &src);
    Background &operator=(Background const &src);
    Background();
    int _mountainCounter;

  public:
    Background(int, int, int, char);
    virtual ~Background();

    static int getNextFreeSpace(Background ** backgrounds);    
    void move(void);
    int getMountainCounter() const;
    void setMountainCounter(int);
};

#endif // Background_HPP