#include <string>
#include <memory>

class Input {
public:
  virtual ~Input(){};
  virtual int enterInput() = 0;
};

class Display {
public:
  Display() : board_(".........") {}
  std::string draw();
  void setXat(int position);
  void setOat(int position);
  std::string getBoard();

private:
  std::string board_;
};

enum class Status {XWon,OWon};

class Controller
{
    public:
    Controller(std::shared_ptr<Input> &input):input_(input){}
    Status play();

    std::shared_ptr<Input> input_;
    private:
};

