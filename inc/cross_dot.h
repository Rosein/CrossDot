#include <string>
#include <memory>

const std::string kDefaultBoard{"........."};
class Input {
public:
  virtual ~Input(){};
  virtual int enterInput() = 0;
};

class Display {
public:
  Display() : board_(kDefaultBoard) {}
  std::string draw();
  void setXat(int position);
  void setOat(int position);
  std::string getBoard();

private:

  void setCharAt(char character, int position);
  std::string board_;
};

enum class Status {
  XWon,
  OWon
};

class Controller
{
    public:
    Controller(std::shared_ptr<Input> &input):input_(input){}
    Status play();

    std::shared_ptr<Input> input_;
    private:
};

