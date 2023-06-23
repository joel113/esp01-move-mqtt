class Acceleration {
    int x;
    int y;
    int z;
  public:
    Acceleration(int x, int y, int z) {
      this->x = x;
      this->y = y;
      this->z = z;
    }
    int getX();
    int getY();
    int getZ();
}